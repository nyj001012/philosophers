/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:27:35 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 18:10:08 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*check_vital(void *arg)
{
	t_philosophers	*philosophers;
	long long		after_eating;

	philosophers = (t_philosophers *)arg;
	while (!philosophers->philo_info->is_end)
	{
		pthread_mutex_lock(&philosophers->critical_section);
		pthread_mutex_lock(&philosophers->philo_info->during_routine);
		after_eating = get_time() - philosophers->last_time_eaten;
		if (after_eating >= philosophers->philo_info->time_to_die
			&& !philosophers->philo_info->is_end)
		{
			print_death(philosophers);
			philosophers->is_alive = false;
			philosophers->philo_info->is_end = true;
		}
		pthread_mutex_unlock(&philosophers->critical_section);
		pthread_mutex_unlock(&philosophers->philo_info->during_routine);
	}
	return (NULL);
}

void	*check_all_is_full(void *arg)
{
	t_philo_info	*philo_info;
	int				i;

	philo_info = ((t_philosophers *)arg)->philo_info;
	while (!philo_info->is_end)
	{
		pthread_mutex_lock(&philo_info->during_routine);
		i = -1;
		while (++i < philo_info->number_of_philosophers)
		{
			if (philo_info->philosophers[i].number_of_times_eaten
				< philo_info->number_of_must_eat)
				break ;
		}
		if (i == philo_info->number_of_philosophers)
			philo_info->is_end = true;
		pthread_mutex_unlock(&philo_info->during_routine);
	}
	return (NULL);
}
