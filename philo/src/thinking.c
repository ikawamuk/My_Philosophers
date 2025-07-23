/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:37:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/24 04:00:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	take_fork(t_philo *philo, pthread_mutex_t *fork);

int	thinking(t_philo *philo)
{
	print_state(philo, philo->id, "is thinking");
	if (take_fork(philo, philo->left_fork) == -1)
		return (1);
	if (take_fork(philo, philo->right_fork) == -1)
	{
		pthread_mutex_unlock(philo->left_fork);
		return (1);
	}
	return (0);
}

static int	take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	if (!is_runnning(philo))
		return (-1);
	if (philo->ctx->philo_num != 1)
		pthread_mutex_lock(fork);
	print_state(philo, philo->id, "has taken a fork");
	if (philo->ctx->philo_num == 1)
	{
		usleep(1000 * philo->ctx->life_time);
		return (-1);
	}
	return (0);
}
