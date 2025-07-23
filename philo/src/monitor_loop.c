/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:26:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 13:49:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	check_died(t_philo *philo);
static int	all_philo_full(t_philo *philo, uint64_t *philo_full);

void	monitor_loop(t_philo *philo)
{
	uint64_t	i;
	uint64_t	philo_full;

	while (1)
	{
		i = 0;
		philo_full = 0;
		while (i < philo->ctx->philo_num)
		{
			if (check_died(&philo[i]) == 1)
				return ;
			if (all_philo_full(&philo[i], &philo_full) == 1)
				return ;
			i++;
		}
		usleep(100);
	}
	return ;
}

static int	check_died(t_philo *philo)
{
	uint64_t	last_meal_time;
	uint64_t	now;

	pthread_mutex_lock(&philo->meal_mutex);
	last_meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_mutex);
	now = get_timestamp(philo->ctx->start);
	if ((now - last_meal_time) > (philo->ctx->life_time))
	{
		pthread_mutex_lock(&philo->cmn->finished_mutex);
		philo->cmn->finished = true;
		pthread_mutex_unlock(&philo->cmn->finished_mutex);
		pthread_mutex_lock(&philo->cmn->print_mutex);
		printf("%lu\t%lu %s\n", now, philo->id, "is died");
		pthread_mutex_unlock(&philo->cmn->print_mutex);
		return (1);
	}
	return (0);
}

static int	all_philo_full(t_philo *philo, uint64_t *philo_full)
{
	uint64_t	eat_cnt;
	uint64_t	now;

	pthread_mutex_lock(&philo->meal_mutex);
	eat_cnt = philo->eat_cnt;
	pthread_mutex_unlock(&philo->meal_mutex);
	if (eat_cnt >= philo->ctx->must_eat)
		(*philo_full)++;
	if (*philo_full == philo->ctx->philo_num)
	{
		now = get_timestamp(philo->ctx->start);
		pthread_mutex_lock(&philo->cmn->finished_mutex);
		philo->cmn->finished = true;
		pthread_mutex_unlock(&philo->cmn->finished_mutex);
		pthread_mutex_lock(&philo->cmn->print_mutex);
		printf("%lu\tAll philo are full!\n", now);
		pthread_mutex_unlock(&philo->cmn->print_mutex);
		return (1);
	}
	return (0);
}
