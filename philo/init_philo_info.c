/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo_info.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 18:22:42 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 18:30:05 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

void	init_philo_info(t_philo_info *philo_info, char **argv)
{
	philo_info->number_of_philosophers = ft_atoll(argv[0]);
	philo_info->time_to_die = ft_atoll(argv[1]);
	philo_info->time_to_eat = ft_atoll(argv[2]);
	philo_info->time_to_sleep = ft_atoll(argv[3]);
	philo_info->birthday = get_time();
	philo_info->is_end = false;
	if (argv[4])
		philo_info->number_of_must_eat = ft_atoll(argv[4]);
	else
		philo_info->number_of_must_eat = 0;
}
