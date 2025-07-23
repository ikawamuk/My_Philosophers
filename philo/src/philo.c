/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:25:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 09:35:13 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "config.h"

int	set_structure(t_args args, t_ctx *ctx, t_philo **philosophers);

int	philo(t_args args)
{
	t_ctx	ctx;
	t_philo	*philo;

	if (set_structure(args, &ctx, &philo) == -1)
		return (-1);
	return (0);
}