/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:14:08 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/28 22:40:10 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static t_sems	set_sem(t_args args);
t_philo			set_philo(uint64_t id, t_sems *sem, bool *in_running);
void			philo_process(t_philo *philo, t_args args);
static int		run_simulation(uint64_t num, sem_t *running_sem, bool is_running);

int	philo_bonus(t_args args)
{
	t_philo		*philo;
	bool		is_running;
	t_sems		sem;
	uint64_t	i;
	

	philo = ft_calloc(args.philo_num, sizeof(t_philo));
	if (!philo)
		return (-1);
	is_running = false;
	sem = set_sem(args);
	i = 0;
	while (i++ < args.philo_num)
	{
		philo[i] = set_philo(i + 1, &sem, &is_running);
		philo[i].pid = fork();
		if (philo[i].pid == 0)	
			philo_process(&philo[i], args);
	}
	run_simulation(args.philo_num, sem.running, is_running);
	return (0);
}

static t_sems	set_sem(t_args args)
{
	t_sems sem;

	sem_unlink(SEM_RUNNING);
	sem.running = sem_open(SEM_RUNNING, O_CREAT, 0644, 0);  // set_sem()
	sem_unlink(SEM_FORKS);
	sem.forks = sem_open(SEM_RUNNING, O_CREAT, 0644, args.philo_num);
	sem_unlink(SEM_PRINT);
	sem.print = sem_open(SEM_RUNNING, O_CREAT, 0644, 1);
	return (sem);
}

static int	run_simulation(uint64_t num, sem_t *running_sem, bool is_running)
{
	uint64_t	i;

	is_running = true;
	i = 0;
	while (i++ < num)
		sem_post(running_sem);
	return (0);
}