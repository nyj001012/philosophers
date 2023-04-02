/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_birth_to_philosophers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:00:46 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 18:24:22 by yena             ###   ########.fr       */
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

/*
 * Description: 철학자들을 태어나게 한다.
 * Param.   #1: 철학자들의 정보를 담고 있는 구조체
 * Return     : 없음
 */
void	give_birth_to_philosophers(t_philo_info *philo_info)
{
	int				i;
	pthread_t		monitoring_thread;

	i = -1;
	while (++i < philo_info->number_of_philosophers)
	{
		philo_info->philosophers[i].last_time_eaten = philo_info->birthday;
		pthread_create(&philo_info->philosophers[i].routine, NULL, live, &philo_info->philosophers[i]);
		pthread_create(&monitoring_thread, NULL, check_vital, &philo_info->philosophers[i]);
		pthread_detach(monitoring_thread);
	}
	if (philo_info->number_of_must_eat)
	{
		pthread_create(&monitoring_thread, NULL, check_all_is_full, philo_info->philosophers);
		pthread_detach(monitoring_thread);
	}
}
