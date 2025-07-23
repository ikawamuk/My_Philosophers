/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_structure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:06:07 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 09:40:05 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	set_ctx(t_args args, t_ctx *ctx);
int	set_philosophers(t_ctx *ctx, t_philo **philosophers);

int	set_structure(t_args args, t_ctx *ctx, t_philo **philosophers)
{
	if (set_ctx(args, ctx) == -1)
		return (-1);
	if (set_philosophers(ctx, philosophers) == -1)
	{
		free(ctx->forks);
		return (-1);
	}
	return (0);
}
