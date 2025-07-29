/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:28:51 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 14:24:06 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static int	take_fork(t_philo *philo);

int	thinking(t_philo *philo)
{
	print_state(philo, "is thinking");
	usleep(200);
	if (take_fork(philo) == -1)
		return (1);
	if (take_fork(philo) == -1)
	{
		sem_post(philo->forks);
		return (1);
	}
	return (0);
}

static int	take_fork(t_philo *philo)
{
	if (is_finished(philo))
		return (-1);
	if (philo->args.philo_num != 1)
		sem_wait(philo->forks);
	print_state(philo, "has taken a fork");
	if (philo->args.philo_num == 1)
	{
		usleep(1000 * philo->args.life_time);
		return (-1);
	}
	return (0);
}
