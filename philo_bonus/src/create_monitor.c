/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_monitor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 22:40:34 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/28 22:45:37 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	monitor_loop();

void	create_monitor(t_philo *philo, t_args args)
{
	uint64_t	i;

	i = 0;
	while (i < args.philo_num)
	{
		pthread_create(philo->thread, NULL, monitor_loop, (void *)&philo[i]);
		i++;
	}
	return (0);
}
