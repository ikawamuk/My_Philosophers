/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_terminator_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 00:33:02 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 02:23:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static void	*terminator_full(void *arg);
static void *terminator_dead(void *arg);
static void	kill_all_philo(uint64_t philo_num, pid_t *pids);

void	set_terminator(t_philo *philo)
{
	pthread_t	full;
	pthread_t	dead;

	pthread_create(&dead, NULL, terminator_dead, (void *)philo);
	pthread_create(&full, NULL, terminator_full, (void *)philo);
	pthread_detach(dead);
	pthread_detach(full);
	return ;
}

static void	*terminator_dead(void *arg)
{
	t_philo	*philo;

	philo = arg;
	sem_wait(philo->sems.dead);
	sem_wait(philo->sems.print);
	kill_all_philo(philo->args.philo_num, philo->pids);
	return (NULL);
}

static void	*terminator_full(void *arg)
{
	t_philo	*philo;
	uint64_t	i;

	philo = arg;
	i = 0;
	while (i++ < philo->args.philo_num)
		sem_wait(philo->sems.full);
	sem_wait(philo->sems.print);
	kill_all_philo(philo->args.philo_num, philo->pids);
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
