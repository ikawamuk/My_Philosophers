/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_thread_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 03:01:40 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 03:13:41 by ikawamuk         ###   ########.fr       */
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
			print_state(philo, "is died");
			sem_post(philo->sems.dead);
			exit(0);
		}
		sem_post(philo->sems.meal);
		usleep(500);
	}
	return (NULL);
}