/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:15:48 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 18:24:59 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

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

void	take_fork(t_philosophers *philosophers)
{
	print_fork(philosophers);
	print_fork(philosophers);
	pthread_mutex_lock(philosophers->left_fork);
	pthread_mutex_lock(philosophers->right_fork);
}

void	eat(t_philosophers *philosophers)
{
	print_eating(philosophers);
	pthread_mutex_lock(&philosophers->critical_section);
	usleep(philosophers->philo_info->time_to_eat * 1000);
	pthread_mutex_unlock(&philosophers->critical_section);
	pthread_mutex_unlock(philosophers->left_fork);
	pthread_mutex_unlock(philosophers->right_fork);
}

void	do_sleep(t_philosophers *philosophers)
{
	print_sleeping(philosophers);
	usleep(philosophers->philo_info->time_to_sleep * 1000);
}

void	think(t_philosophers *philosophers)
{
	print_thinking(philosophers);
	usleep(100);
}
