/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_loop_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:22:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 20:56:03 by ikawamuk         ###   ########.fr       */
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
	}
	return (NULL);
}

static bool	is_dead(t_philo *philo)
{
	u_int64_t	now;

	sem_wait(philo->meal);
	now = get_timestamp(philo->start);
	if (now - philo->last_meal_time > philo->args.life_time)
	{
		sem_wait(philo->print);
		printf("%lu\t%lu died\n", now, philo->id);
		sem_post(philo->print);
		sem_post(philo->meal);
		exit(1);
	}
	sem_post(philo->meal);
	return (false);
}
