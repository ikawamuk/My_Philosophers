/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:26:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 13:23:09 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	check_running(t_philo *philo);
static bool	someone_died(t_philo *philo);
static bool	all_philo_full(t_philo *philo, uint64_t *philo_full);

void	monitor_loop(t_philo *philo)
{
	pthread_mutex_lock(&philo->cmn->running_mutex);
	philo->cmn->running = true;
	philo->cmn->start = get_ms();
	philo->ctx->start = philo->cmn->start;
	pthread_mutex_unlock(&philo->cmn->running_mutex);
	while (1)
	{
		if (check_running(philo) == 0)
			return ;
		usleep(500);
	}
	return ;
}

static int	check_running(t_philo *philo)
{
	uint64_t	i;
	uint64_t	philo_full;

	i = 0;
	philo_full = 0;
	while (i < philo->ctx->philo_num)
	{
		if (someone_died(&philo[i]))
			return (0);
		if (all_philo_full(&philo[i], &philo_full))
			return (0);
		i++;
	}
	return (1);
}

static bool	someone_died(t_philo *philo)
{
	int			died;
	uint64_t	now;

	pthread_mutex_lock(&philo->meal_mutex);
	pthread_mutex_lock(&philo->cmn->running_mutex);
	pthread_mutex_lock(&philo->cmn->print_mutex);
	now = get_timestamp(philo->ctx->start);
	if ((now - philo->last_meal_time) > (philo->ctx->life_time))
	{
		philo->cmn->running = false;
		printf("%lu\t%lu %s\n", now, philo->id, "is died");
	}
	died = !philo->cmn->running;
	pthread_mutex_unlock(&philo->cmn->print_mutex);
	pthread_mutex_unlock(&philo->cmn->running_mutex);
	pthread_mutex_unlock(&philo->meal_mutex);
	return (died);
}

static bool	all_philo_full(t_philo *philo, uint64_t *philo_full)
{
	bool		is_all_full;
	uint64_t	now;

	if (philo->ctx->must_eat == 0)
		return (0);
	pthread_mutex_lock(&philo->meal_mutex);
	pthread_mutex_lock(&philo->cmn->running_mutex);
	pthread_mutex_lock(&philo->cmn->print_mutex);
	if (philo->eat_cnt >= philo->ctx->must_eat)
		(*philo_full)++;
	if (*philo_full == philo->ctx->philo_num)
	{
		now = get_timestamp(philo->ctx->start);
		philo->cmn->running = false;
		printf("%lu\tAll philo are full!\n", now);
	}
	is_all_full = !philo->cmn->running;
	pthread_mutex_unlock(&philo->cmn->print_mutex);
	pthread_mutex_unlock(&philo->cmn->running_mutex);
	pthread_mutex_unlock(&philo->meal_mutex);
	return (is_all_full);
}
