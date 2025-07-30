/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:57:51 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 00:54:46 by ikawamuk         ###   ########.fr       */
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
	pid_t	*pids;

	philo = set_philo(args);
	pids = malloc(sizeof(pid_t) * args.philo_num);
	if (!pids)
		return (-1);
	while (philo.id < args.philo_num)
	{
		pids[philo.id++] = forks();
		if (pids == 0)
			philo_loop(&philo);
	}
	set_monitor(philo, pids);
	run_simulation(&philo);
	free(pids);
	return (0);
}
