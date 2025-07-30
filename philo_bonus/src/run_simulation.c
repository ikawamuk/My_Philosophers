/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_simulation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 00:31:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 00:32:08 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	run_simulation(t_philo *philo)
{
	uint64_t	i;

	i = 0;
	while (i++ < philo->args.philo_num)
		sem_post(philo->sems.start);
	return ;
}
