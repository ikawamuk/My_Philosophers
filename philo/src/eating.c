/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:27:23 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/24 01:52:39 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	update_philo_state(t_philo *philo, uint64_t *start, uint64_t *now);

int	eating(t_philo *philo)
{
	uint64_t	start_eat;
	uint64_t	now;
	bool		running;

	update_philo_state(philo, &start_eat, &now);
	while (now - start_eat < philo->ctx->eat_time)
	{
		pthread_mutex_lock(&philo->cmn->running_mutex);
		running = philo->cmn->running;
		pthread_mutex_unlock(&philo->cmn->running_mutex);
		if (!running)
		{
			pthread_mutex_unlock(philo->right_fork);
			pthread_mutex_unlock(philo->left_fork);
			return (1);
		}
		usleep(100);
		now = get_timestamp(philo->ctx->start);
	}
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	return (0);
}

static void	update_philo_state(t_philo *philo, uint64_t *start, uint64_t *now)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = print_state(philo, philo->id, "is eating");
	philo->eat_cnt++;
	*start = philo->last_meal_time;
	*now = *start;
	pthread_mutex_unlock(&philo->meal_mutex);	
}
