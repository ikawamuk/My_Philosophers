/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:45:58 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 01:08:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	*monitor_loop(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		if (is_died(philo))
			break ;
		if (is_all_full(philo))
			break ;
		usleep(100);
	}
	return (NULL);
}

static bool	is_died(t_philo *philo)
{

	bool		is_died;
	u_int64_t	now;

	is_died = false;
	sem_wait(philo->sem.meal);
	sem_wait(philo->sem.running);
	sem_wait(philo->sem.print);
	now = get_timestamp(philo->start);
	if (now - philo->last_meal_time > philo->args.life_time)
		philo->is_running = false;
	is_died = true;
	sem_post(philo->sem.print);
	sem_post(philo->sem.running);
	sem_post(philo->sem.meal);
	return (is_died);
}
