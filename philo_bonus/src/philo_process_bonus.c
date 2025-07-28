/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:35:47 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 00:59:12 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	*monitor_loop(void *args);
int		thinking(t_philo *philo);
int		eating(t_philo *philo);
int		sleeping(t_philo *philo);

void		philo_process(t_philo *philo)
{
	pthread_create(philo->thread, NULL, monitor_loop, (void *)philo);
	sem_wait(philo->sem.running);
	philo->start = get_ms();
	if (philo->id % 2 == 0)
		usleep(1000 * philo->args.eat_time / 3);
	while (1)
	{
		if (thinking(philo) == 1)
			break ;
		if (eating(philo) == 1)
			break ;
		if (sleeping(philo) == 1)
			break ;
	}
	pthread_join(philo->thread, NULL);
	exit(0);
}
