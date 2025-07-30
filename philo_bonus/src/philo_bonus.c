/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/30 23:57:51 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 00:14:54 by ikawamuk         ###   ########.fr       */
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

	philo = set_philo(args);
	while (philo.id++ < args.philo_num)
	{
		philo.pid = forks();
		if (philo.pid == 0)
			philo_loop(&philo);
	}
	run_simulation(&philo);
	finish_simulation(&philo);
	return (0);
}
