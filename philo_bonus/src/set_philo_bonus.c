/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:03:15 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 00:58:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_philo	set_philo(uint64_t id, bool *flag, t_sems sem, t_args args)
{
	t_philo	philo;

	philo.id = id;
	philo.pid = -1;
	philo.is_running = flag;
	philo.sem = sem;
	philo.start = 0;
	philo.last_meal_time = 0;
	philo.eat_cnt = 0;
	philo.args = args;
	return (philo);
}
