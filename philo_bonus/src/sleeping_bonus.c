/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 01:19:19 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 02:04:45 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	sleeping(t_philo *philo)
{
	uint64_t	start_sleep;
	uint64_t	now;

	start_sleep = print_state(philo, "is sleeping");
	now = start_sleep;
	while (now - start_sleep < philo->args.sleep_time)
	{
		usleep(100);
		now = get_timestamp(philo->start);
	}
	usleep(200);
	return ;
}
