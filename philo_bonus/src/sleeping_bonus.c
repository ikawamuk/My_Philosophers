/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 12:29:24 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 17:51:18 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int	sleeping(t_philo *philo)
{
	uint64_t	start_sleep;
	uint64_t	now;

	start_sleep = print_state(philo, "is sleeping");
	now = start_sleep;
	while (now - start_sleep < philo->args.sleep_time)
	{
		if (is_finished(philo))
			return (1);
		usleep(100);
		now = get_timestamp(philo->start);
	}
	usleep(100);
	return (0);
}
