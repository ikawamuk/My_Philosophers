/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:27:23 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 13:55:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	update_philo_status(t_philo *philo, uint64_t *start_eat);

int	eating(t_philo *philo)
{
	uint64_t	start_eat;
	uint64_t	now;
	bool		finished;

	update_philo_status(philo, &start_eat);
	print_state(philo, philo->id, "is eating");
	now = start_eat;
	while (now - start_eat < philo->ctx->eat_time)
	{
		pthread_mutex_lock(&philo->cmn->finished_mutex);
		finished = philo->cmn->finished;
		pthread_mutex_unlock(&philo->cmn->finished_mutex);
		if (finished)
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

static void	update_philo_status(t_philo *philo, uint64_t *start_eat)
{
	pthread_mutex_lock(&philo->meal_mutex);
	philo->last_meal_time = get_timestamp(philo->ctx->start);
	*start_eat = philo->last_meal_time;
	philo->eat_cnt++;
	pthread_mutex_unlock(&philo->meal_mutex);
	return ;
}
