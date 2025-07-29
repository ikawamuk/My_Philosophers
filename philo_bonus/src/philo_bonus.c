/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 02:43:46 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 12:02:51 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_philo		set_philo(t_args args, bool *is_running);
void		philo_process(t_philo *philo);
static int	run_simulation(t_philo *philo);

int	philo_bonus(t_args args)
{
	t_philo	philo;
	bool	is_running;

	philo = set_philo(args, &is_running);
	while (philo.id++ < args.philo_num)
	{
		philo.pid = fork();
		if (philo.pid == 0)
			philo_process(&philo);
	}
	run_simulation(&philo);
	return (0);
}

static int	run_simulation(t_philo *philo)
{
	uint64_t	i;

	*philo->is_running = true;
	i = 0;
	while (i++ < philo->args.philo_num)
		sem_post(philo->running);
	return (0);
}
