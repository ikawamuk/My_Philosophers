/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 07:21:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/08/02 22:08:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>

# define END	1
# define ERROR	-1

typedef struct s_args
{
	uint64_t	philo_num;
	uint64_t	life_time;
	uint64_t	eat_time;
	uint64_t	sleep_time;
	uint64_t	must_eat;
}	t_args;

typedef struct s_common
{
	uint64_t		start;
	bool			running;
	pthread_mutex_t	running_mutex;
	pthread_mutex_t	print_mutex;
}	t_cmn;

typedef struct s_ctx
{
	uint64_t		philo_num;
	uint64_t		life_time;
	uint64_t		eat_time;
	uint64_t		sleep_time;
	uint64_t		must_eat;
	uint64_t		start;
	pthread_mutex_t	*forks;
}	t_ctx;

typedef struct s_philo
{
	uint64_t		id;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	uint64_t		last_meal_time;
	uint64_t		eat_cnt;
	pthread_mutex_t	meal_mutex;
	t_cmn			*cmn;
	t_ctx			*ctx;
}	t_philo;

#endif