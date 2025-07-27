/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:03:15 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/27 21:52:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_philo	set_philo(uint64_t id, sem_t *running, sem_t *forks, sem_t *print)
{
	t_philo	philo;

	philo.id = id;
	philo.pid = -1;
	philo.running = running;
	philo.forks = forks;
	philo.print = print;
	philo.start = 0;
	philo.last_meal_time = 0;
	philo.eat_cnt = 0;
	return (philo);
}
