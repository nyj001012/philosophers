/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:15:48 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 21:41:14 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/philosophers.h"

/*
 * Description: 철학자들이 루틴을 수행하는 동안 메인 스레드를 대기시키고,
 *              루틴이 끝나면 critical_section을 해제한다.
 *              모든 철학자들의 루틴이 끝나면, 철학자들을 free하고, 포크를 해제한 후 free한다.
 * Param.   #1: t_philo_info 구조체의 포인터
 * Return     : 없음
 */
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

/*
 * Description: 철학자들이 포크를 집는다.
 *              1. 철학자가 왼쪽 포크를 집는다.
 *              2. 포크를 집었다는 메시지를 출력한다.
 *              3. 철학자가 오른쪽 포크를 집는다.
 *              4. 포크를 집었다는 메시지를 출력한다.
 * Param.   #1: t_philosophers 구조체의 포인터
 * Return     : 없음
 */
void	take_fork(t_philosophers *philosophers)
{
	if (philosophers->philo_info->is_end)
		return ;
	pthread_mutex_lock(philosophers->left_fork);
	print_fork(philosophers);
	pthread_mutex_lock(philosophers->right_fork);
	print_fork(philosophers);
}

/*
 * Description: 철학자들이 먹는다.
 *              1. 식사하는 동안 critical_section을 잠금한다.
 *              2. 식사 메시지를 출력한다.
 *              3. 식사를 한다 = 식사 시간 만큼 sleep한다.
 *              4. 마지막으로 식사를 한 시간을 갱신한다.
 *              5. 식사 횟수를 1 증가시킨다.
 *              6. critical_section을 잠금 해제한다.
 *              7. 왼쪽 포크를 놓는다.
 *              8. 오른쪽 포크를 놓는다.
 * Param.   #1: t_philosophers 구조체의 포인터
 * Return     : 없음
 */
void	eat(t_philosophers *philosophers)
{
	if (philosophers->philo_info->is_end)
		return ;
	pthread_mutex_lock(&philosophers->critical_section);
	print_eating(philosophers);
	usleep(philosophers->philo_info->time_to_eat * 1000);
	philosophers->last_time_eaten = get_time();
	philosophers->number_of_times_eaten++;
	pthread_mutex_unlock(&philosophers->critical_section);
	pthread_mutex_unlock(philosophers->left_fork);
	pthread_mutex_unlock(philosophers->right_fork);
}

/*
 * Description: 철학자들이 잠을 잔다.
 *              1. 잠을 잔다는 메시지를 출력한다.
 *              2. 잠을 잔다 = 잠자는 시간 만큼 sleep한다.
 * Param.   #1: t_philosophers 구조체의 포인터
 * Return     : 없음
 */
void	do_sleep(t_philosophers *philosophers)
{
	if (philosophers->philo_info->is_end)
		return ;
	print_sleeping(philosophers);
	usleep(philosophers->philo_info->time_to_sleep * 1000);
}

/*
 * Description: 철학자들이 생각한다.
 *              1. 생각한다는 메시지를 출력한다.
 * Param.   #1: t_philosophers 구조체의 포인터
 * Return     : 없음
 */
void	think(t_philosophers *philosophers)
{
	if (philosophers->philo_info->is_end)
		return ;
	print_thinking(philosophers);
}
