/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:25:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 10:27:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			set_structure(t_args args, t_ctx *ctx, t_philo **philosophers);
int			create_threads(t_philo *philo);
static void	join_threads(t_ctx ctx, t_philo *philo);
static void	clear_resouce(t_ctx *ctx, t_philo **philo);

int	philo(t_args args)
{
	t_ctx	ctx;
	t_philo	*philo;

	if (set_structure(args, &ctx, &philo) == -1)
		return (-1);
	if (create_threads(philo) == -1)
	{
		clear_resouce(&ctx, &philo);
		return (-1);
	}
	monitor_loop(philo);
	join_threads(ctx, philo);
	clear_resouce(&ctx, &philo);
	return (0);
}

static void	clear_resouce(t_ctx *ctx, t_philo **philo)
{
	uint64_t	i;

	pthread_mutex_destroy((*philo)->finished_mutex);
	i = 0;
	while (i < ctx->philo_num)
	{
		pthread_mutex_destroy(&(*philo[i]).meal_time_mutex);
		pthread_mutex_destroy((*philo)[i].left_fork);
		i++;
	}
	free((*philo)->finished_mutex);
	free((*philo)->finished);
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
