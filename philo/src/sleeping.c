/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:04:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 12:08:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	sleeping(t_philo *philo)
{
	uint64_t	start_sleep;
	uint64_t	now;
	bool		finished;

	start_sleep = get_timestamp(philo->ctx->start);
	now = start_sleep;
	while (now - start_sleep < philo->ctx->sleep_time)
	{
		pthread_mutex_lock(&philo->cmn->finished_mutex);
		finished = philo->cmn->finished;
		pthread_mutex_lock(&philo->cmn->finished_mutex);
		if (finished)
			return (1);
		usleep(100);
		now = get_timestamp(philo->ctx->start);
	}
	return (0);
}
