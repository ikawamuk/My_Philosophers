/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_loop_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:22:04 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 13:25:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static bool	someone_died(t_philo *philo);
static bool	is_all_full(t_philo *philo);

void	*monitor_loop(void *args)
{
	t_philo	*philo;

	philo = (t_philo *)args;
	while (1)
	{
		if (someone_died(philo))
			break ;
		if (is_all_full(philo))
			break ;
		usleep(500);
	}
	return (NULL);
}

static bool	someone_died(t_philo *philo)
{
	bool		died;
	u_int64_t	now;

	sem_wait(philo->meal);
	sem_wait(philo->running);
	sem_wait(philo->print);
	now = get_timestamp(philo->start);
	if (now - philo->last_meal_time > philo->args.life_time)
	{
		philo->someone_died = true;
		printf("%lu\t%lu %s\n", now, philo->id, "is died");
	}
	died = philo->someone_died;
	sem_post(philo->print);
	sem_post(philo->running);
	sem_post(philo->meal);
	return (died);
}

static bool	is_all_full(t_philo *philo)
{
	bool		is_all_full;
	uint64_t	now;

	is_all_full = false;
	sem_wait(philo->meal);
	sem_wait(philo->running);
	sem_wait(philo->print);
	if (philo->eat_cnt == philo->args.must_eat)
		philo->full_cnt++;
	if (philo->full_cnt == philo->args.philo_num)
	{
		now = get_timestamp(philo->start);
		printf("%lu\tAll philo are full!\n", now);
		is_all_full = true;
	}
	sem_post(philo->print);
	sem_post(philo->running);
	sem_post(philo->meal);
	return (is_all_full);
}