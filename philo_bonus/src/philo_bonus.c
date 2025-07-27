/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:14:08 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/27 21:24:55 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	philo_process(t_philo *philo, t_args args);

int	philo_bonus(t_args args)
{
	sem_t		*running_sem;
	uint64_t	i;
	t_philo		*philo;

	sem_unlink(SEM_RUNNING);
	running_sem = sem_open(SEM_RUNNING, O_CREAT, 0644, 0);  // set_sem()
	
	philo = ft_calloc(args.philo_num, sizeof(t_philo));
	if (!philo)
		return (-1);
	i = 0;
	while (i++ < args.philo_num)
	{
		set_philo(&philo[i]);
		philo[i].pid = fork();
		if (philo[i].pid == 0)	
			philo_process(&philo[i], args);
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