/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 02:43:46 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 12:36:12 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_philo		set_philo(t_args args, bool *someone_died, uint64_t *full_cnt);
void		philo_loop(t_philo *philo);
static int	run_simulation(t_philo *philo);

int	philo_bonus(t_args args)
{
	t_philo		philo;
	bool		someone_died;
	uint64_t	full_cnt;

	philo = set_philo(args, &someone_died, &full_cnt);
	while (philo.id++ < args.philo_num)
	{
		philo.pid = fork();
		if (philo.pid == 0)
			philo_loop(&philo);
	}
	run_simulation(&philo);
	return (0);
}

static int	run_simulation(t_philo *philo)
{
	uint64_t	i;

	*philo->someone_died = false;
	*philo->full_cnt = 0;
	i = 0;
	while (i++ < philo->args.philo_num)
		sem_post(philo->running);
	return (0);
}
