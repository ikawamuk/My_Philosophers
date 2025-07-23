/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:26:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/24 01:08:53 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	check_finished(t_philo *philo);
static int	someone_died(t_philo *philo);
static int	all_philo_full(t_philo *philo, uint64_t *philo_full);

void	monitor_loop(t_philo *philo)
{
	while (1)
	{
		if (check_finished(philo) == 1)
			return ;
		usleep(100);
	}
	return ;
}

static int	check_finished(t_philo *philo)
{
	uint64_t	i;
	uint64_t	philo_full;

	i = 0;
	philo_full = 0;
	while (i < philo->ctx->philo_num)
	{
		if (someone_died(&philo[i]) == 1)
			return (1);
		if (all_philo_full(&philo[i], &philo_full) == 1)
			return (1);
		i++;
	}
	return (0);
}

static int	someone_died(t_philo *philo)
{
	uint64_t	now;

	pthread_mutex_lock(&philo->meal_mutex);
	pthread_mutex_lock(&philo->cmn->finished_mutex);
	pthread_mutex_lock(&philo->cmn->print_mutex);
	now = get_timestamp(philo->ctx->start);
	if ((now - philo->last_meal_time) > (philo->ctx->life_time))
	{
		philo->cmn->finished = true;
		printf("%lu\t%lu %s\n", now, philo->id, "is died");
		pthread_mutex_unlock(&philo->cmn->print_mutex);
		pthread_mutex_unlock(&philo->cmn->finished_mutex);
		pthread_mutex_unlock(&philo->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->cmn->print_mutex);
	pthread_mutex_unlock(&philo->cmn->finished_mutex);
	pthread_mutex_unlock(&philo->meal_mutex);
	return (0);
}

static int	all_philo_full(t_philo *philo, uint64_t *philo_full)
{
	uint64_t	now;

	if (philo->ctx->must_eat == 0)
		return (0);

	pthread_mutex_lock(&philo->meal_mutex);
	pthread_mutex_lock(&philo->cmn->finished_mutex);
	pthread_mutex_lock(&philo->cmn->print_mutex);
	if (philo->eat_cnt >= philo->ctx->must_eat)
		(*philo_full)++;
	if (*philo_full == philo->ctx->philo_num)
	{
		now = get_timestamp(philo->ctx->start);
		philo->cmn->finished = true;
		printf("%lu\tAll philo are full!\n", now);
		pthread_mutex_unlock(&philo->cmn->print_mutex);
		pthread_mutex_unlock(&philo->cmn->finished_mutex);
		pthread_mutex_unlock(&philo->meal_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->cmn->print_mutex);
	pthread_mutex_unlock(&philo->cmn->finished_mutex);
	pthread_mutex_unlock(&philo->meal_mutex);
	return (0);
}
