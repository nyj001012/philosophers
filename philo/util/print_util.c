/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 00:59:02 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 16:21:03 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	print_eating(t_philosophers *philosophers)
{
	long long	time;

	if (philosophers->philo_info->is_end)
		return ;
	pthread_mutex_lock(&philosophers->philo_info->during_routine);
	philosophers->number_of_times_eaten++;
	time = get_time();
	philosophers->last_time_eaten = time;
	time -= philosophers->philo_info->birthday;
	printf("%lld ", time);
	printf("%d\tis eating\n", philosophers->number);
	pthread_mutex_unlock(&philosophers->philo_info->during_routine);
}

void	print_sleeping(t_philosophers *philosophers)
{
	long long	time;

	if (philosophers->philo_info->is_end)
		return ;
	pthread_mutex_lock(&philosophers->philo_info->during_routine);
	time = get_time();
	time -= philosophers->philo_info->birthday;
	printf("%lld ", time);
	printf("%d\tis sleeping\n", philosophers->number);
	pthread_mutex_unlock(&philosophers->philo_info->during_routine);
}

void	print_thinking(t_philosophers *philosophers)
{
	long long	time;

	if (philosophers->philo_info->is_end)
		return ;
	pthread_mutex_lock(&philosophers->philo_info->during_routine);
	time = get_time();
	time -= philosophers->philo_info->birthday;
	printf("%lld ", time);
	printf("%d\tis thinking\n", philosophers->number);
	pthread_mutex_unlock(&philosophers->philo_info->during_routine);
}

void	print_death(t_philosophers *philosophers)
{
	long long	time;

	if (philosophers->philo_info->is_end)
		return ;
	time = get_time();
	time -= philosophers->philo_info->birthday;
	printf("%lld ", time);
	printf("%d\tdead\n", philosophers->number);
}

void	print_fork(t_philosophers *philosophers)
{
	long long	time;

	if (philosophers->philo_info->is_end)
		return ;
	pthread_mutex_lock(&philosophers->philo_info->during_routine);
	time = get_time() -  philosophers->philo_info->birthday;
	printf("%lld ", time);
	printf("%d\thas taken a fork\n", philosophers->number);
	pthread_mutex_unlock(&philosophers->philo_info->during_routine);
}