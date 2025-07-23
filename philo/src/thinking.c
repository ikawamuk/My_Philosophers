/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:37:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 13:05:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	take_fork(t_philo *philo, pthread_mutex_t *fork);

int	thinking(t_philo *philo)
{
	print_state(philo, philo->id, "is thinking");
	if (philo->id % 2 == 0)
		usleep(200);
	if (take_fork(philo, philo->left_fork) == -1)
		return (1);
	if (take_fork(philo, philo->right_fork) == -1)
	{
		pthread_mutex_unlock(philo->left_fork);	
		return (1);
	}
	// }
	// else
	// {
	// 	if (take_fork(philo, philo->right_fork) == -1)
	// 		return (1);
	// 	if (take_fork(philo, philo->left_fork) == -1)
	// 	{
	// 		pthread_mutex_unlock(philo->right_fork);	
	// 		return (1);
	// 	}			
	// }
	return (0);
}

static int	take_fork(t_philo *philo, pthread_mutex_t *fork)
{
	bool		finished;

	pthread_mutex_lock(&philo->cmn->finished_mutex);
	finished = philo->cmn->finished;
	pthread_mutex_unlock(&philo->cmn->finished_mutex);
	if (finished)
		return (-1);
	pthread_mutex_lock(fork);
	print_state(philo, philo->id, "has taken a fork");
	return (0);
}