/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor_loop.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 10:26:44 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 11:23:27 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	monitor_loop(t_philo *philo)
{
	uint64_t	i;
	uint64_t	now;

	while (1)
	{
		i = 0;
		while (i < philo->ctx->philo_num)
		{
			now = get_timestamp(philo->ctx->start);
			if (check_died(&philo[i], now) == 1)
				return ;
			i++;
		}
		usleep(100);
	}
	return ;
}

static int	check_died(t_philo *philo, uint64_t now)
{
	uint64_t	last_meal_time;

	pthread_mutex_lock(&philo->meal_mutex);
	last_meal_time = philo->last_meal_time;
	pthread_mutex_unlock(&philo->meal_mutex);
	if ((now - last_meal_time) > (philo->ctx->life_time))
	{
		pthread_mutex_lock(&philo->common->finished_mutex);
		philo->common->finished = true;
		pthread_mutex_unlock(&philo->common->finished_mutex);
		pthread_mutex_lock(&philo->common->print_mutex);
		printf("%lu\t%lu is died\n", now, philo->id);
		pthread_mutex_unlock(&philo->common->print_mutex);
		return (1);
	}
	return (0);
}
