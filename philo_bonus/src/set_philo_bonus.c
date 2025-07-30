/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philo_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 00:15:01 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 00:17:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_philo	set_philo(t_args args)
{
	t_philo	philo;

	philo.id = 0;
	philo.pid = -1;
	philo.thread = -1;
	philo.args = args;
	philo.start = 0;
	philo.last_meal_time = 0;
	philo.eat_cnt = 0;
	
	sem_unlink(SEM_FORKS);
	philo.forks = sem_open(SEM_FORKS, O_CREAT, 600, args.philo_num);
	sem_unlink(SEM_PRINT);
	philo.print = sem_open(SEM_PRINT, O_CREAT, 600, 1);
	return (philo);	
}
