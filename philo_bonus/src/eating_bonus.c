/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:29:26 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 20:50:42 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static void	update_philo_state(t_philo *philo, uint64_t *start, uint64_t *now);

int	eating(t_philo *philo)
{
	uint64_t	start_eat;
	uint64_t	now;

	update_philo_state(philo, &start_eat, &now);
	while (now - start_eat < philo->args.eat_time)
	{
		usleep(100);
		now = get_timestamp(philo->start);
	}
	sem_post(philo->forks);
	sem_post(philo->forks);
	return (0);
}

static void	update_philo_state(t_philo *philo, uint64_t *start, uint64_t *now)
{
	sem_wait(philo->meal);
	philo->last_meal_time = print_state(philo, "is eating");
	philo->eat_cnt++;
	if (philo->eat_cnt == philo->args.must_eat)
		sem_post(philo->running); 
	*start = philo->last_meal_time;
	*now = *start;
	sem_post(philo->meal);
}
