/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_is_running.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/24 03:58:24 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/24 03:59:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

bool	is_runnning(t_philo *philo)
{
	bool		running;

	pthread_mutex_lock(&philo->cmn->running_mutex);
	running = philo->cmn->running;
	pthread_mutex_unlock(&philo->cmn->running_mutex);
	return (running);
}
