/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:25:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/24 00:44:45 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			set_ctx(t_args args, t_ctx *ctx);
int			set_philosophers(t_cmn *cmn, t_ctx *ctx, t_philo **philosophers);
static void	set_common(t_cmn *cmn);
int			create_threads(t_philo *philo);
void		monitor_loop(t_philo *philo);
static void	join_threads(t_ctx ctx, t_philo *philo);
static void	clear_resouce(t_cmn *cmn, t_ctx *ctx, t_philo *philo);

int	philo(t_args args)
{
	t_cmn		cmn;
	t_ctx		ctx;
	t_philo		*philo;

	set_common(&cmn);
	if (set_ctx(args, &ctx) == -1)
		return (-1);
	if (set_philosophers(&cmn, &ctx, &philo) == -1)
	{
		pthread_mutex_destroy(&cmn.finished_mutex);
		pthread_mutex_destroy(&cmn.print_mutex);
		free(ctx.forks);
		return (-1);
	}
	ctx.start = get_ms();
	create_threads(philo);
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
	uint64_t	i;

	i = 0;
	while (i < ctx.philo_num)
	{
		printf("thread finished: %lu\n", philo[i].thread);
		pthread_join(philo[i++].thread, NULL);
	}
	return ;
}

static void	set_common(t_cmn *cmn)
{
	cmn->finished = 0;
	pthread_mutex_init(&cmn->finished_mutex, NULL);
	pthread_mutex_init(&cmn->print_mutex, NULL);
	return ;
}
