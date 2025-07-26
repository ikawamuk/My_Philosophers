/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:14:08 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/26 16:58:19 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int	philo_bonus(t_args args)
{
	sem_t		*running_sem;
	uint64_t	id;
	pid_t		pid;

	sem_unlink(SEM_RUNNING);
	running_sem = sem_open(SEM_RUNNING, O_CREAT, 0644, 0);  // set_sem()
	
	id = 1;
	while (id++ <= args.philo_num)
	{
		pid = fork();
		if (pid == 0)	
			philo_process(id, running_sem, args);
	}
	run_simulation(args.philo_num, running_sem);
	return (0);
}

static int	run_simulation(uint64_t philo_num, sem_t *running_sem)
{
	uint64_t	i;

	i = 0;
	while (i++ < philo_num)
		sem_post(running_sem);
	return (0);
}