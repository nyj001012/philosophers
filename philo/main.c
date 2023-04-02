/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:01:21 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 16:07:30 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosophers.h"

int	main(int argc, char **argv)
{
	t_philo_info	philo_info;

	if (argc < 5 || argc > 6)
	{
		printf("Error: Wrong argument\n");
		return (0);
	}
	argv++;
	init_philo_info(&philo_info, argv);
	if (!is_valid_info(&philo_info))
	{
		printf("Error: Wrong argument\n");
		return (0);
	}
	init_philosophers(&philo_info);
	give_birth_to_philosophers(&philo_info);
	wait_and_end_routine(&philo_info);
	return (0);
}
