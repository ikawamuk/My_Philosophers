/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:57:51 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 01:02:29 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_philo	set_philo(t_args args);
void	philo_loop(t_philo *philo);
void	set_monitor(t_philo *philo, pid_t *pids);
void	run_simulation(t_philo *philo);


int	philo_bonus(t_args args)
{
	t_philo	philo;

	philo = set_philo(args);
	philo.pids = malloc(sizeof(pid_t) * args.philo_num);
	if (!philo.pids)
		return (-1);
	while (philo.id < args.philo_num)
	{
		philo.pids[philo.id] = fork();
		if (philo.pids[philo.id++] == 0)
			philo_loop(&philo);
		sleep(3);
		sem_post(philo.sems.dead);
	}
	set_monitor(&philo, philo.pids);
	run_simulation(&philo);
	free(philo.pids);
	return (0);
}
