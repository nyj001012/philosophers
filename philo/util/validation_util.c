/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:51:47 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 12:20:31 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

bool	is_valid_info(t_philo_info *philo_info)
{
	if (philo_info->number_of_philosophers < 1)
		return (false);
	if (philo_info->time_to_die < 0)
		return (false);
	if (philo_info->time_to_eat < 0)
		return (false);
	if (philo_info->time_to_sleep < 0)
		return (false);
	if (philo_info->number_of_must_eat < 0)
		return (false);
	return (true);
}
