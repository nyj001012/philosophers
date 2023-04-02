/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitoring.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 23:27:35 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 21:39:09 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
 * Description: 철학자들이 살아있는지 확인한다.
 *              철학자들이 한 명이라도 죽지 않았다면, 아래의 과정을 반복한다.
 *              1. 철학자 한 명만 접근할 수 있는 영역을 잠근다.
 *              2. 철학자들의 루틴 영역을 잠근다.
 *              3. 마지막으로 밥을 먹은 시간과 현재 시간을 비교하여, 철학자가 죽었는지 확인한다.
 *                 1) 만약 죽었다면, 철학자가 죽었다는 메시지를 출력하며 philo_info의 값을 바꾼다.
 *              4. 철학자 한 명만 접근할 수 있는 영역을 잠금 해제한다.
 *              5. 철학자들의 루틴 영역을 잠금 해제한다.
 * Param.   #1: 철학자들의 정보를 담고 있는 구조체
 * Return     : 없음
 */
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
		if (after_eating >= philosophers->philo_info->time_to_die)
			print_death(philosophers);
		pthread_mutex_unlock(&philosophers->critical_section);
		pthread_mutex_unlock(&philosophers->philo_info->during_routine);
	}
	return (NULL);
}

/*
 * Description: 철학자들이 배부른지 확인한다
 *              = 철학자들이 반드시 밥을 먹어야 하는 횟수만큼 먹었는지 확인한다.
 *              1. 철학자들의 루틴 영역을 잠근다.
 *              2. 각각의 철학자들이 반드시 밥을 먹어야 하는 횟수만큼 먹었다면 반복문을 진행한다.
 *                 1) 만약 반드시 밥을 먹어야 하는 횟수만큼 먹지 않았다면 반복문을 종료한다.
 *              3. 반드시 밥을 먹어야 하는 횟수만큼 밥을 먹은 철학자의 수가 전체 철학자의 수와 같다면,
 *                 philo_info의 is_end값을 true로 바꾼다.
 *              4. 철학자들의 루틴 영역을 잠금 해제한다.
 * Param.   #1: 철학자들의 정보를 담고 있는 구조체
 * Return     : 없음
 */
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
