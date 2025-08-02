/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:57:51 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/08/02 21:56:51 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_philo		set_philo(t_args args);
void		*philo_process(void *arg);
void		set_terminator(t_philo *philo);
void		run_simulation(t_philo *philo);
static void	wait_all_process(uint64_t philo_num, pid_t *pids);
static void	close_sem(t_philo *philo);

int	philo_bonus(t_args args)
{
	t_philo	philo;

	philo = set_philo(args);
	philo.pids = malloc(sizeof(pid_t) * args.philo_num);
	if (!philo.pids)
		return (-1);
	while (philo.id < args.philo_num)
	{
		philo.pids[philo.id] = fork();
		if (philo.pids[philo.id++] == 0)
			philo_process(&philo);
	}
	set_terminator(&philo);
	run_simulation(&philo);
	wait_all_process(args.philo_num, philo.pids);
	close_sem(&philo);
	free(philo.pids);
	return (0);
}

static void	close_sem(t_philo *philo)
{
	sem_close(philo->sems.dead);
	sem_close(philo->sems.forks);
	sem_close(philo->sems.full);
	sem_close(philo->sems.print);
	sem_close(philo->sems.start);
	sem_close(philo->sems.meal);
	
}

static void	wait_all_process(uint64_t philo_num, pid_t *pids)
{
	uint64_t	i;

	i = 0;
	while (i < philo_num)
		waitpid(pids[i++], NULL, 0);
	return ;
}
