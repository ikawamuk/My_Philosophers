/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 01:21:51 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 03:41:36 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	eating(t_philo *philo)
{
	uint64_t	start_eat;
	uint64_t	now;

	sem_wait(philo->sems.meal);
	philo->last_meal_time = print_state(philo, "is eating");
	sem_post(philo->sems.meal);
	philo->eat_cnt++;
	if (philo->eat_cnt == philo->args.must_eat)
		sem_post(philo->sems.full);
	start_eat = philo->last_meal_time;
	now = start_eat;
	while (now - start_eat < philo->args.eat_time)
	{
		usleep(100);
		now = get_timestamp(philo->start);
	}
	sem_post(philo->sems.forks);
	sem_post(philo->sems.forks);
	return ;
}
