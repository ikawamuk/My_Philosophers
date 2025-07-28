/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:03:15 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/28 22:32:20 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_philo	set_philo(uint64_t id, bool *is_running, t_sems *sem)
{
	t_philo	philo;

	philo.id = id;
	philo.pid = -1;
	philo.is_running = is_running;
	philo.running = sem->running;
	philo.forks = sem->forks;
	philo.print = sem->print;
	philo.meal = sem->meal;
	philo.start = 0;
	philo.last_meal_time = 0;
	philo.eat_cnt = 0;
	return (philo);
}
