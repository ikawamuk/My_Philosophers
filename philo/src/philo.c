/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:25:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 11:43:15 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"


static void	join_threads(t_ctx ctx, t_philo *philo);
static void	clear_resouce(t_cmn *cmn, t_ctx *ctx, t_philo *philo);

int	philo(t_args args)
{
	t_cmn		cmn;
	t_ctx		ctx;
	t_philo		*philo;

	if (set_structure(args, &cmn, &ctx, &philo) == -1)
		return (-1);
	if (create_threads(philo) == -1)
	{
		clear_resouce(&cmn, &ctx, &philo);
		return (-1);
	}
	monitor_loop(philo);
	join_threads(ctx, philo);
	clear_resouce(&cmn, &ctx, philo);
	return (0);
}

static void	clear_resouce(t_cmn *cmn, t_ctx *ctx, t_philo *philos)
{
	uint64_t	i;

	pthread_mutex_destroy(&cmn->finished_mutex);
	pthread_mutex_destroy(&cmn->print_mutex);
	i = 0;
	while (i < ctx->philo_num)
	{
		pthread_mutex_destroy(philos[i].left_fork);
		pthread_mutex_destroy(&philos[i].meal_mutex);
		i++;
	}
	free(philos);
	free(ctx->forks);
	return ;
}

static void	join_threads(t_ctx ctx, t_philo *philo)
{
	uint64_t i;

	i = 0;
	while (i < ctx.philo_num)
		pthread_join(philo[i++].thread, NULL);
	return ;
}
