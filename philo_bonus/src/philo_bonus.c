/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 02:43:46 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 13:48:31 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

static int	alloc_flag(	bool **someone_died, uint64_t **full_cnt);
t_philo		set_philo(t_args args, bool *someone_died, uint64_t *full_cnt);
void		philo_loop(t_philo *philo);
static int	run_simulation(t_philo *philo);

int	philo_bonus(t_args args)
{
	t_philo		philo;
	bool		*someone_died;
	uint64_t	*full_cnt;

	someone_died = NULL;
	full_cnt = NULL;
	if (alloc_flag(&someone_died, &full_cnt) == -1)
		return (-1);
	philo = set_philo(args, someone_died, full_cnt);
	while (philo.id++ <= args.philo_num)
	{
		philo.pid = fork();
		if (philo.pid == 0)
			philo_loop(&philo);
	}
	run_simulation(&philo);
	while (args.philo_num--)
		waitpid(-1, NULL, 0);
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

static int	alloc_flag(	bool **someone_died, uint64_t **full_cnt)
{
	*someone_died = ft_calloc(1, sizeof(bool));
	if (!someone_died)
		return (-1);
	*full_cnt = ft_calloc(1, sizeof(uint64_t));
	if (!full_cnt)
	{
		free(*someone_died);
		return (-1);
	}
	return (0);
}
