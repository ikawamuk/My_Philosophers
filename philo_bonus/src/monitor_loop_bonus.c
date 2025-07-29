/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_loop_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:22:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 12:37:08 by ikawamuk         ###   ########.fr       */
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
		usleep(500);
	}
	return (NULL);	
	return (NULL);
}

static bool	is_died(t_philo *philo)
{
	bool		is_died;
	u_int64_t	now;

	sem_wait(philo->meal);
	sem_wait(philo->running);
	sem_wait(philo->print);
	now = get_timestamp(philo->start);
	if (now - philo->last_meal_time > philo->args.life_time)
		philo->someone_died = true;
	is_died = philo->someone_died;
	sem_post(philo->print);
	sem_post(philo->running);
	sem_post(philo->meal);
	return (is_died);
}
