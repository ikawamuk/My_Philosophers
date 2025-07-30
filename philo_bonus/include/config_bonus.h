/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:37:52 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 00:30:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_BONUS_H
# define CONFIG_BONUS_H

# include <stdlib.h>
# include <stdint.h>
# include <stdbool.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/types.h>
# include <semaphore.h>
# include <fcntl.h>
# include <pthread.h>
# include <sys/wait.h>

# define SEM_FORKS		"/forks"
# define SEM_PRINT		"/print"
# define SEM_START		"/start"
# define SEM_MEAL		"/meal"

typedef struct s_args
{
	uint64_t	philo_num;
	uint64_t	life_time;
	uint64_t	eat_time;
	uint64_t	sleep_time;
	uint64_t	must_eat;
}	t_args;

typedef struct s_sem
{
	sem_t		*forks;
	sem_t		*print;
	sem_t		*start;	
}	t_sem;

typedef struct s_philo
{
	uint64_t	id;
	pid_t		pid;
	pthread_t	thread;
	t_args		args;
	uint64_t	start;
	uint64_t	last_meal_time;
	uint64_t	eat_cnt;
	t_sem		sems;

}	t_philo;

#endif