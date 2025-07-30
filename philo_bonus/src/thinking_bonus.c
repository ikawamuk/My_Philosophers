/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thinking_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 02:10:48 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 03:33:06 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	thinking(t_philo *philo)
{
	print_state(philo, "is thinking");
	usleep(200);
	if (philo->args.philo_num != 1)
		sem_wait(philo->sems.forks);
	print_state(philo, "has taken a fork");
	if (philo->args.philo_num == 1)
	{
		usleep(1000 * philo->args.life_time);
		usleep(1000);
		return ;
	}
	sem_wait(philo->sems.forks);
	print_state(philo, "has taken a fork");
	return ;
}
