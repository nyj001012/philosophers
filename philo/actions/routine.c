/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:15:48 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 18:19:13 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

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
