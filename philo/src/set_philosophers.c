/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_philosophers.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:26:40 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 09:42:36 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	alloc_finished_flag(bool **flag, pthread_mutex_t **mutex);
static void	set_philo(t_philo *philo, uint64_t i, t_ctx *ctx);
static void	set_fin_flag(t_philo *philo, bool *flag, pthread_mutex_t *mutex);

int	set_philosophers(t_ctx *ctx, t_philo **philosophers)
{
	bool			*finished_flag;
	pthread_mutex_t	*finished_mutex;
	uint64_t		i;

	*philosophers = ft_calloc(ctx->philo_num, sizeof(t_philo));
	if (!*philosophers)
		return (-1);
	if (alloc_finished_flag(&finished_flag, &finished_mutex) == -1)
	{
		free(philosophers);
		return (-1);
	}
	i = 0;
	while (i < ctx->philo_num)
	{
		set_philo(&(*philosophers)[i], i, ctx);
		set_fin_flag(&(*philosophers)[i], finished_flag, finished_mutex);
		i++;
	}
	return (0);
}

static void	set_fin_flag(t_philo *philo, bool *flag, pthread_mutex_t *mutex)
{
	philo->finished = flag;
	philo->finished_mutex = mutex;
}

static void	set_philo(t_philo *philo, uint64_t i, t_ctx *ctx)
{
	philo->left_fork = &ctx->forks[i];
	pthread_mutex_init(philo->left_fork, NULL);
	if (i + 1 < ctx->philo_num)
		philo->right_fork = &ctx->forks[i + 1];
	else
		philo->right_fork = &ctx->forks[0];
	philo->last_meal_time = 0;
	pthread_mutex_init(&philo->meal_time_mutex, NULL);
	philo->id = i + 1;
	philo->ctx = ctx;
	return ;
}

static int	alloc_finished_flag(bool **flag, pthread_mutex_t **mutex)
{
	*flag = ft_calloc(1, sizeof(bool));
	if (!*flag)
		return (-1);
	*mutex = ft_calloc(1, sizeof(pthread_mutex_t));
	if (!*mutex)
	{
		free(*flag);
		return (-1);
	}
	pthread_mutex_init(*mutex, NULL);	
	return (0);
}
