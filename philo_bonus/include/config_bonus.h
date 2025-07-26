/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:37:52 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/26 16:34:04 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_BONUS_H
# define CONFIG_BONUS_H

# include <stdio.h>
# include <stdint.h>
# include <stdlib.h>
# include <stdbool.h>
# include <unistd.h>
# include <fcntl.h>
# include <semaphore.h>
# include <sys/wait.h>

# define SEM_FORKS		"/forks"
# define SEM_PRINT		"/print"
# define SEM_RUNNING	"/running"


typedef struct s_args
{
	uint64_t	philo_num;
	uint64_t	life_time;
	uint64_t	eat_time;
	uint64_t	sleep_time;
	uint64_t	must_eat;
}	t_args;

typedef struct s_philo
{
	uint64_t	id;
	pid_t		pid;
	sem_t		forks;
	sem_t		print;
	sem_t		finished;
	uint64_t	start;
	uint64_t	last_meal_time;
	uint64_t	eat_cnt;
	
}	t_philo;


#endif