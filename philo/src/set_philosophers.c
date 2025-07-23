/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:26:40 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 11:52:07 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static void	set_philo(t_philo *philo, uint64_t i, t_cmn *cmn, t_ctx *ctx);

int	set_philosophers(t_cmn *cmn, t_ctx *ctx, t_philo **philosophers)
{
	uint64_t		i;

	*philosophers = ft_calloc(ctx->philo_num, sizeof(t_philo));
	if (!*philosophers)
		return (-1);
	i = 0;
	while (i < ctx->philo_num)
	{
		set_philo(&(*philosophers)[i], i, cmn, ctx);
		i++;
	}
	return (0);
}

static void	set_philo(t_philo *philo, uint64_t i, t_cmn *cmn, t_ctx *ctx)
{
	philo->id = i + 1;
	philo->thread = 0;
	philo->left_fork = &ctx->forks[i];
	pthread_mutex_init(philo->left_fork, NULL);
	if (i + 1 < ctx->philo_num)
		philo->right_fork = &ctx->forks[i + 1];
	else
		philo->right_fork = &ctx->forks[0];
	philo->last_meal_time = 0;
	philo->eat_cnt = 0;
	pthread_mutex_init(&philo->meal_mutex, NULL);
	philo->cmn = cmn;
	philo->ctx = ctx;
	return ;
}
