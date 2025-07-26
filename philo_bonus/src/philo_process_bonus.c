/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:35:47 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/26 16:58:11 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int	philo_process(uint64_t id, sem_t *running_sem, t_args args)
{
	uint64_t	start;

	sem_wait(running_sem);
	start = get_ms();
	if (id % 2 == 0)
			usleep(1000 * args.eat_time / 3);
	return (0);
}