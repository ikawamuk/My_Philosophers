/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 03:01:40 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 03:37:18 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	*monitor_thread(void *arg)
{
	t_philo		*philo;
	uint64_t	now;

	philo = (t_philo *)arg;
	while (1)
	{
		sem_wait(philo->sems.meal);
		now = get_timestamp(philo->start);
		if (now - philo->last_meal_time > philo->args.life_time)
		{
			sem_wait(philo->sems.print);
			printf("%lu\t%lu %s\n", now, philo->id, "is died");
			sem_post(philo->sems.dead);
			exit(0);
		}
		sem_post(philo->sems.meal);
	}
	return (NULL);
}