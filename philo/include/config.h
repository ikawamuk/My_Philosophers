/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 07:21:55 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 09:04:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>

typedef struct s_args
{
	uint64_t	philo_num;
	uint64_t	life_time;
	uint64_t	eat_time;
	uint64_t	sleep_time;
	uint64_t	must_eat;
}	t_args;

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
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	uint64_t		last_meal_time;
	pthread_mutex_t	meal_time_mutex;
	bool			*finished;
	pthread_mutex_t	finished_mutex;
	uint64_t		id;
	pthread_t		thread;
	t_ctx			*ctx;
	// uint64_t		eat_cnt;
}	t_philo;

#endif