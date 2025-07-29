/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 11:45:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 11:57:43 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_philo	set_philo(t_args args, bool *is_running)
{
	t_philo	philo;

	philo.id = 0;
	philo.pid = -1;
	philo.thread = -1;
	philo.args = args;
	philo.start = 0;
	philo.last_meal_time = 0;
	philo.eat_cnt = 0;
	philo.is_running = is_running;
	philo.forks = sem_open(SEM_FORKS, O_CREAT, 600, args.philo_num);
	philo.running = sem_open(SEM_RUNNING, O_CREAT, 600, 0);
	philo.print = sem_open(SEM_PRINT, O_CREAT, 600, 1);
	philo.meal = NULL;
	return (philo);
}