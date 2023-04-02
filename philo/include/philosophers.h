/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yena <yena@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 13:02:11 by yena              #+#    #+#             */
/*   Updated: 2023/04/02 18:41:11 by yena             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <pthread.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <signal.h>
# include <stdbool.h>

typedef struct s_philo_info
{
	long long				number_of_philosophers;
	long long				number_of_must_eat;
	long long				time_to_die;
	long long				time_to_eat;
	long long				time_to_sleep;
	long long				birthday;
	bool					is_end;
	pthread_mutex_t			*forks;
	pthread_mutex_t			during_routine;
	struct s_philosophers	*philosophers;
}	t_philo_info;

typedef struct s_philosophers
{
	int				number;
	int				number_of_times_eaten;
	long long		last_time_eaten;
	bool			is_alive;
	pthread_t		routine;
	pthread_mutex_t	critical_section;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_philo_info	*philo_info;
}	t_philosophers;

/*--------------------------------- UTIL ------------------------------------*/
long long	ft_atoll(const char *str);
long long	get_time(void);

/*----------------------------- PHILOSOPHERS --------------------------------*/
void		init_philo_info(t_philo_info *philo_info, char **argv);
bool		is_valid_info(t_philo_info *philo_info);
void		init_philosophers(t_philo_info *philo_info);
void		give_birth_to_philosophers(t_philo_info *philo_info);
void		*live(void *philosophers);
void		wait_and_end_routine(t_philo_info *philo_info);
void		take_fork(t_philosophers *philosophers);
void		eat(t_philosophers *philosophers);
void		do_sleep(t_philosophers *philosophers);
void		think(t_philosophers *philosophers);

/*--------------------------------- PRINT -----------------------------------*/
void		print_time(void);
void		print_death(t_philosophers *philosophers);
void		print_thinking(t_philosophers *philosophers);
void		print_sleeping(t_philosophers *philosophers);
void		print_fork(t_philosophers *philosophers);
void		print_eating(t_philosophers *philosophers);

/*-------------------------------- MONITOR ----------------------------------*/
void		*check_vital(void *arg);
void		*check_all_is_full(void *arg);

#endif //PHILOSOPHERS_PHILOSOPHERS_H
