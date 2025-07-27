/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:35:47 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/27 21:23:55 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int			thinking(t_philo *philo);
int			eating(t_philo *philo);
int			sleeping(t_philo *philo);

void		philo_process(t_philo *philo, t_args args)
{
	sem_wait(philo->running);
	philo->start = get_ms();
	if (philo->id % 2 == 0)
		usleep(1000 * args.eat_time / 3);
	while (1)
	{
		if (thinking(philo) == 1)
			break ;
		if (eating(philo) == 1)
			break ;
		if (sleeping(philo) == 1)
			break ;
	}
	exit(0);
}
