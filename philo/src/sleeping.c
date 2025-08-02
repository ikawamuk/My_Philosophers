/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 12:04:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/08/02 22:05:29 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	sleeping(t_philo *philo)
{
	uint64_t	start_sleep;
	uint64_t	now;

	start_sleep = print_state(philo, philo->id, "is sleeping");
	now = start_sleep;
	while (now - start_sleep < philo->ctx->sleep_time)
	{
		if (!is_runnning(philo))
			return (END);
		usleep(100);
		now = get_timestamp(philo->ctx->start);
	}
	usleep(500);
	return (0);
}
