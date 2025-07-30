/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_monitor_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 00:33:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 02:10:41 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static void	*monitor_full(void *arg);
static void *monitor_dead(void *arg);
static void	kill_all_philo(uint64_t philo_num, pid_t *pids);

void	set_monitor(t_philo *philo)
{
	pthread_t	full;
	pthread_t	dead;

	pthread_create(&dead, NULL, monitor_dead, (void *)philo);
	pthread_create(&full, NULL, monitor_full, (void *)philo);
	pthread_detach(dead);
	pthread_detach(full);
	return ;
}

static void	*monitor_dead(void *arg)
{
	t_philo	*philo;

	philo = arg;
	sem_wait(philo->sems.dead);
	kill_all_philo(philo->args.philo_num, philo->pids);
	return (NULL);
}

static void	*monitor_full(void *arg)
{
	t_philo	*philo;
	uint64_t	i;

	philo = arg;
	i = 0;
	while (i++ < philo->args.philo_num)
		sem_wait(philo->sems.full);
	kill_all_philo(philo->args.philo_num, philo->pids);
	sem_wait(philo->sems.print);
	printf("All philosophers are full!\n");
	return (NULL);
}

static void	kill_all_philo(uint64_t philo_num, pid_t *pids)
{
	uint64_t	i;
	
	i = 0;
	while (i < philo_num)
		kill(pids[i++], SIGKILL);
	return ;		
}
