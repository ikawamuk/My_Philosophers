/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:37:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/08/02 22:05:14 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	take_fork(t_philo *philo, pthread_mutex_t *fork);

int	thinking(t_philo *philo)
{
	print_state(philo, philo->id, "is thinking");
	if (take_fork(philo, philo->right_fork) == END)
		return (END);
	if (take_fork(philo, philo->left_fork) == END)
	{
		pthread_mutex_unlock(philo->right_fork);
		return (END);
	}
	return (0);
}

static int	take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	if (!is_runnning(philo))
		return (END);
	if (philo->ctx->philo_num != 1)
		pthread_mutex_lock(fork);
	print_state(philo, philo->id, "has taken a fork");
	if (philo->ctx->philo_num == 1)
	{
		usleep(1000 * philo->ctx->life_time);
		return (END);
	}
	return (0);
}
