/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/02 00:16:21 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 20:35:04 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

/*
 * Description: philo_info를 초기화 한다.
 *              이때, forks와 philosophers는 init_philosophers 초기화한다.
 *              5번째 인자가 없을 경우, number_of_must_eat은 0으로 초기화한다.
 * Param.   #1: t_philo_info 구조체의 포인터
 * Param.   #2: 입력받은 인자들의 배열
 * Return     : 없음
 */
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

/*
 * Description: philosophers를 초기화 한다.
 *              1. philo_info 내 philosophers와 forks를 동적할당한다.
 *              2. 각 philosophers의 critical_section을 mutex로 초기화한다.
 *              3. 각 philo_info의 각 fork를 mutex로 초기화한다.
 *              4. 각 philosophers의 남은 멤버 변수를 초기화한다.
 * Param.   #1: t_philo_info 구조체의 포인터
 * Return     : 없음
 */
void	init_philosophers(t_philo_info *philo_info)
{
	int	i;

	pthread_mutex_init(&philo_info->during_routine, NULL);
	philo_info->philosophers = (t_philosophers *)malloc(
			sizeof(t_philosophers) * philo_info->number_of_philosophers);
	philo_info->forks = (pthread_mutex_t *)malloc(
			sizeof(pthread_mutex_t) * philo_info->number_of_philosophers);
	i = -1;
	while (++i < philo_info->number_of_philosophers)
	{
		pthread_mutex_init(&philo_info->philosophers[i].critical_section, NULL);
		pthread_mutex_init(&philo_info->forks[i], NULL);
		philo_info->philosophers[i].number = i + 1;
		philo_info->philosophers[i].number_of_times_eaten = 0;
		philo_info->philosophers[i].last_time_eaten = philo_info->birthday;
		philo_info->philosophers[i].is_alive = true;
		philo_info->philosophers[i].philo_info = philo_info;
		philo_info->philosophers[i].left_fork = &philo_info->forks[i];
		if (!i)
			philo_info->philosophers[i].right_fork = \
			&philo_info->forks[philo_info->number_of_philosophers - 1];
		else
			philo_info->philosophers[i].right_fork = &philo_info->forks[i - 1];
	}
}
