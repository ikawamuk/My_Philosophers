/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:35:47 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/27 21:06:20 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_philo		set_philo(uint64_t id, sem_t *running_sem, t_args args);
int			thinking(t_philo *philo);
int			eating(t_philo *philo);
int			sleeping(t_philo *philo);
void		philo_process(uint64_t id, sem_t *running_sem, t_args args)
{
	t_philo	philo;

	philo = set_philo(id, running_sem, args);
	sem_wait(running_sem);
	philo.start = get_ms();
	if (id % 2 == 0)
		usleep(1000 * args.eat_time / 3);
	while (1)
	{
		if (thinking(&philo) == 1)
			break ;
		if (eating(&philo) == 1)
			break ;
		if (sleeping(&philo) == 1)
			break ;
	}
	exit(0);
}
