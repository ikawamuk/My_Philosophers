/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_process_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 01:05:52 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 01:16:24 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	*philo_process(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	sem_post(philo->sems.dead);
	exit(0);
	return (arg);
}
