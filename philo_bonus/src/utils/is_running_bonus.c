/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_running_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 22:02:15 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/27 22:04:16 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

bool	is_running(t_philo *philo)
{
	bool	running;

	sem_wait(philo->running);
	running = philo->is_running;
	sem_post(philo->running);
	return (running);
}