/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:57:51 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 00:36:11 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_philo	set_philo(t_args args);
void	philo_loop(t_philo *philo);
void	run_simulation(t_philo *philo);
void	finish_simulation(t_philo *philo);


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
	run_simulation(&philo);
	finish_simulation(&philo);
	free(pids);
	return (0);
}
