/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 00:59:02 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 21:43:17 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
 * Description: 밥을 먹는다는 메시지를 출력한다.
 * Param.   #1: 철학자들의 정보를 담고 있는 구조체
 * Return     : 없음
 */
void	print_eating(t_philosophers *philosophers)
{
	long long	time;

	if (philosophers->philo_info->is_end)
		return ;
	pthread_mutex_lock(&philosophers->philo_info->during_routine);
	time = get_time() - philosophers->philo_info->birthday;
	printf("%lld\t", time);
	printf("%d\tis eating\n", philosophers->number);
	pthread_mutex_unlock(&philosophers->philo_info->during_routine);
}

/*
 * Description: 잔다는 메시지를 출력한다.
 * Param.   #1: 철학자들의 정보를 담고 있는 구조체
 * Return     : 없음
 */
void	print_sleeping(t_philosophers *philosophers)
{
	long long	time;

	if (philosophers->philo_info->is_end)
		return ;
	pthread_mutex_lock(&philosophers->philo_info->during_routine);
	time = get_time() - philosophers->philo_info->birthday;
	printf("%lld\t", time);
	printf("%d\tis sleeping\n", philosophers->number);
	pthread_mutex_unlock(&philosophers->philo_info->during_routine);
}

/*
 * Description: 생각한다는 메시지를 출력한다.
 * Param.   #1: 철학자들의 정보를 담고 있는 구조체
 * Return     : 없음
 */
void	print_thinking(t_philosophers *philosophers)
{
	long long	time;

	if (philosophers->philo_info->is_end)
		return ;
	pthread_mutex_lock(&philosophers->philo_info->during_routine);
	time = get_time() - philosophers->philo_info->birthday;
	printf("%lld\t", time);
	printf("%d\tis thinking\n", philosophers->number);
	pthread_mutex_unlock(&philosophers->philo_info->during_routine);
}

/*
 * Description: 죽었다는 메시지를 출력한다.
 * Param.   #1: 철학자들의 정보를 담고 있는 구조체
 * Return     : 없음
 */
void	print_death(t_philosophers *philosophers)
{
	long long	time;

	if (philosophers->philo_info->is_end)
		return ;
	time = get_time() - philosophers->philo_info->birthday;
	printf("%lld\t", time);
	printf("%d\tdied\n", philosophers->number);
	philosophers->philo_info->is_end = true;
	philosophers->is_alive = false;
}

/*
 * Description: 포크를 집는다는 메시지를 출력한다.
 * Param.   #1: 철학자들의 정보를 담고 있는 구조체
 * Return     : 없음
 */
void	print_fork(t_philosophers *philosophers)
{
	long long	time;

	if (philosophers->philo_info->is_end)
		return ;
	pthread_mutex_lock(&philosophers->philo_info->during_routine);
	time = get_time() - philosophers->philo_info->birthday;
	printf("%lld\t", time);
	printf("%d\thas taken a fork\n", philosophers->number);
	pthread_mutex_unlock(&philosophers->philo_info->during_routine);
}
