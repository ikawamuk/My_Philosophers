/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 02:43:46 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 20:37:37 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static int	alloc_flag(	bool **someone_died, uint64_t **full_cnt);
t_philo		set_philo(t_args args);
void		philo_loop(t_philo *philo);
static void	run_simulation(t_philo *philo);
static void	finish_simulation(t_philo *philo);

int	philo_bonus(t_args args)
{
	t_philo		philo;

	philo = set_philo(args);
	while (philo.id++ < args.philo_num)
	{
		philo.pid = fork();
		if (philo.pid == 0)
			philo_loop(&philo);
	}
	run_simulation(&philo);
	finish_simulation(&philo);
	return (0);
}

static void	run_simulation(t_philo *philo)
{
	uint64_t	i;

	i = 0;
	while (i++ < philo->args.philo_num)
		sem_post(philo->running);
	return ;
}

static void	finish_simulation(t_philo *philo)
{
	uint64_t	i;

	i = 0;
	while (i++ < philo->args.philo_num)
		sem_wait(philo->running);
	kill(0, SIGKILL);
	return ;
}
