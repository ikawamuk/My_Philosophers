/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finish_simulation.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 00:33:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 00:53:34 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static void	monitor_full(t_philo *philo, pid_t *pids);
static void	monitor_dead(t_philo *philo, pid_t *pids);
static void	kill_all_philo(uint64_t philo_num, pid_t *pids);
static void	wait_all_process(uint64_t philo_num, pid_t *pids);

void	set_monitor(t_philo *philo, pid_t *pids)
{
	pthread_create(monitor_full, NULL, monitor_full, (void *)philo);
	pthread_create(monitor_dead, NULL, monitor_dead, (void *)philo);
	return ;
}

static void	monitor_full(t_philo *philo, pid_t *pids)
{
	uint64_t	i;

	i = 0;
	while (i++ < philo->args.philo_num)
		sem_wait(philo->sems.all_full);
	kill_all_philo(philo->args.philo_num, pids);
	wait_all_process(philo->args.philo_num, pids);
	return ;
}

static void	monitor_dead(t_philo *philo, pid_t *pids)
{
	sem_wait(philo->sems.someone_dead);
	kill_all_philo(philo->args.philo_num, pids);
	wait_all_process(philo->args.philo_num, pids);
	return ;
}

static void	wait_all_process(uint64_t philo_num, pid_t *pids)
{
	uint64_t	i;
	
	i = 0;
	while (i < philo_num)
		waitpid(pids[i++], NULL, 0);
	return ;	
}

static void	kill_all_philo(uint64_t philo_num, pid_t *pids)
{
	uint64_t	i;
	
	i = 0;
	while (i < philo_num)
		kill(pids[i++], SIGKILL);
	return ;		
}
