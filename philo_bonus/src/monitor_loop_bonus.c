/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_loop_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:22:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 20:35:39 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"



void	*monitor_loop(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		usleep(500);
		if (is_dead(philo))
			break ;
		if (is_full(philo))
			break ;
	}
	return (NULL);
}

static bool	is_dead(t_philo *philo)
{
	bool		died;
	u_int64_t	now;

	sem_wait(philo->meal);
	
	sem_post(philo->meal);
	return (died);
}

static bool	is_full(t_philo *philo)
{
	if (philo->args.must_eat == 0)
		return (false);
	sem_wait(philo->meal);
	if (philo->eat_cnt == philo->args.must_eat)
		sem_post(philo->running);
	sem_post(philo->meal);
	return (0);
}
