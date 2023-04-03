/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   give_birth_to_philosophers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 14:00:46 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 21:16:25 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
 * Description: 철학자가 일생을 살아가는 함수
 *              1. 홀수 번째 철학자는 (밥 먹는 시간 * 1000)밀리초 만큼 usleep 한다.
 *              2. 철학자가 한 명이라도 죽지 않았다면, 아래의 루틴을 반복한다.
 *                 1) 포크를 집는다.
 *                 2) 밥을 먹는다.
 *                 3) 잠을 잔다.
 *                 4) 생각한다.
 * Param.   #1: 철학자들의 정보를 담고 있는 구조체
 * Return     : 없음
 */
void	*live(void *arg)
{
	t_philosophers	*philosophers;

	philosophers = (t_philosophers *)arg;
	if (philosophers->number % 2 == 0)
		my_usleep(philosophers->philo_info->time_to_eat);
	while (!philosophers->philo_info->is_end && (philosophers->left_fork))
	{
		take_fork(philosophers);
		eat(philosophers);
		do_sleep(philosophers);
		think(philosophers);
	}
	return (NULL);
}

/*
 * Description: 철학자들을 탄생시킨다.
 *              1. 각각의 철학자들이 살아가는 스레드를 생성한다.
 *              2. 각각의 철학자들이 죽었는지 확인하는 스레드를 생성한다.
 *              3. 1~2의 과정을 철학자의 수만큼 반복한 후, 만약 철학자가 반드시 먹어야 하는 식사의 수가 정해져 있다면,
 *                 철학자들이 모두 해당 수만큼 식사를 했는지 확인하는 스레드를 생성한다.
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
		pthread_create(&philo_info->philosophers[i].routine, NULL,
			live, &philo_info->philosophers[i]);
		pthread_create(&monitoring_thread, NULL,
			check_vital, &philo_info->philosophers[i]);
		pthread_detach(monitoring_thread);
	}
	if (!philo_info->is_end && philo_info->number_of_must_eat)
	{
		pthread_create(&monitoring_thread, NULL,
			check_all_is_full, philo_info->philosophers);
		pthread_detach(monitoring_thread);
	}
}
