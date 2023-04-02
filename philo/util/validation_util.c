/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid_info.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:51:47 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 20:28:50 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
 * Description: philo_info의 정보가 유효한지 확인한다.
 * Param.   #1: philo_info 구조체의 주소
 * Return     : true  : 유효한 정보
 *              false : 유효하지 않은 정보
 */
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
