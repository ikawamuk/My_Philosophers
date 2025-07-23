/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_ctx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:26:08 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 09:35:18 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	set_ctx(t_args args, t_ctx *ctx)
{
	ctx->philo_num = args.philo_num;
	ctx->life_time = args.life_time;
	ctx->eat_time = args.eat_time;
	ctx->sleep_time = args.sleep_time;
	ctx->must_eat = args.must_eat;
	ctx->start = get_ms();
	ctx->forks = ft_calloc(ctx->philo_num, sizeof(pthread_mutex_t));
	if (!ctx->forks)
		return (-1);
	return (0);
}
