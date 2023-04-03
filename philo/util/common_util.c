/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_util.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 12:18:11 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 18:32:42 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
 * Description: 현재 시각을 밀리초 단위로 변환 한다.
 * Param.     : 없음
 * Return     : 밀리초 단위의 시각
 *              = (초 단위 * 1000) + (마이크로초 단위 / 1000)
 */
long long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

/*
 * Description: 주어진 시간 만큼 usleep을 한다.
 * Param.   #1: usleep을 하는 데 걸리는 시간
 * Return     : 없음
 */
void	my_usleep(long long duration)
{
	long long	now;

	now = get_time();
	while (get_time() < duration + now)
		usleep(1);
}

long long	ft_atoll(const char *str)
{
	long long	ll;
	long long	sign;
	int			i;

	ll = 0;
	sign = 1;
	i = 0;
	while ((*(str + i) >= 9 && *(str + i) <= 13) || *(str + i) == 32)
		i++;
	if (*(str + i) == '-' || *(str + i) == '+')
	{
		if (*(str + i) == '-')
			sign = -1;
		i++;
	}
	while (*(str + i) >= '0' && *(str + i) <= '9')
	{
		ll = ll * 10 + (*(str + i) - '0');
		i++;
	}
	return (ll * sign);
}
