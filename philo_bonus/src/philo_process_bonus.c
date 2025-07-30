/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 01:05:52 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 03:09:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	*monitor_thread(void *arg);
void	thinking(t_philo *philo);
void	eating(t_philo *philo);
void	sleeping(t_philo *philo);

void	*philo_process(void *arg)
{
	t_philo		*philo;
	pthread_t	monitor;
	philo = (t_philo *)arg;
	pthread_create(&monitor, NULL, monitor_thread, (void *)philo);
	pthread_detach(monitor);
	sem_wait(philo->sems.start);
	philo->start = get_ms();
	while (1)
	{
		thinking(philo);
		eating(philo);
		sleeping(philo);
	}
	return (NULL);
}
