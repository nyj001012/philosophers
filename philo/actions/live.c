/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:30:15 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 18:20:38 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	*live(void *arg)
{
	t_philosophers	*philosophers;

	philosophers = (t_philosophers *)arg;
	if (philosophers->number % 2 == 1)
		usleep(philosophers->philo_info->time_to_eat * 1000);
	while (!philosophers->philo_info->is_end)
	{
		take_fork(philosophers);
		eat(philosophers);
		do_sleep(philosophers);
		think(philosophers);
	}
	return (NULL);
}

void	wait_and_end_routine(t_philo_info *philo_info)
{
	int	i;

	i = -1;
	while (++i < philo_info->number_of_philosophers)
	{
		pthread_join(philo_info->philosophers[i].routine, NULL);
		pthread_mutex_destroy(&philo_info->philosophers[i].critical_section);
	}
	free(philo_info->philosophers);
	i = -1;
	while (++i < philo_info->number_of_philosophers)
		pthread_mutex_destroy(&philo_info->forks[i]);
	free(philo_info->forks);
}

