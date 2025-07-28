/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:35:47 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/28 22:44:34 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	create_monitor(t_philo *philo, t_args args);
int		thinking(t_philo *philo, t_args args);
int		eating(t_philo *philo, t_args args);
int		sleeping(t_philo *philo, t_args args);

void		philo_process(t_philo *philo, t_args args)
{
	create_monitor(philo, args);
	sem_wait(philo->running);
	philo->start = get_ms();
	if (philo->id % 2 == 0)
		usleep(1000 * args.eat_time / 3);
	while (1)
	{
		if (thinking(philo, args) == 1)
			break ;
		if (eating(philo, args) == 1)
			break ;
		if (sleeping(philo, args) == 1)
			break ;
	}
	pthread_join(philo->thread, NULL);
	exit(0);
}
