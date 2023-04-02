/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 00:16:21 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 18:34:33 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
 * Description: philosophers를 초기화 한다.
 * Param.   #1: t_philo_info 구조체의 포인터
 * Return     : 없음
 */
void	init_philosophers(t_philo_info *philo_info)
{
	int	i;

	pthread_mutex_init(&philo_info->during_routine, NULL);
	philo_info->philosophers = (t_philosophers *)malloc(
			sizeof(t_philosophers) * philo_info->number_of_philosophers);
	philo_info->forks = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * philo_info->number_of_philosophers);
	i = -1;
	while (++i < philo_info->number_of_philosophers)
	{
		pthread_mutex_init(&philo_info->philosophers[i].critical_section, NULL);
		pthread_mutex_init(&philo_info->forks[i], NULL);
		philo_info->philosophers[i].number = i + 1;
		philo_info->philosophers[i].number_of_times_eaten = 0;
		philo_info->philosophers[i].last_time_eaten = 0;
		philo_info->philosophers[i].is_alive = true;
		philo_info->philosophers[i].philo_info = philo_info;
		philo_info->philosophers[i].left_fork = &philo_info->forks[i];
		if (!i)
			philo_info->philosophers[i].right_fork = \
			&philo_info->forks[philo_info->number_of_philosophers - 1];
		else
			philo_info->philosophers[i].right_fork = &philo_info->forks[i - 1];
	}
}
