/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:58:38 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/27 22:01:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int	sleeping(t_philo *philo, t_args args)
{
	uint64_t	start_sleep;
	uint64_t	now;

	start_sleep = print_state(philo, "is sleeping");
	now = start_sleep;
	while (now - start_sleep < args.sleep_time)
	{
		if (!is_running(philo))
			return (1);
		usleep(100);
		now = get_timestamp(philo->start);
	}
	return (0);
}