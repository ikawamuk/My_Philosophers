/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:25:50 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 09:50:40 by ikawamuk         ###   ########.fr       */
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
	// mallocしたもの: ctx->forks, philo, philo->finish, philo->finish_mutex
	// mutex_initしたもの: philo->finish_mutex, 各 &philo->meal_time_mutex
	// 　　　　　　　　　　  各philo->left_fork
	if (create_threads(philo) == -1)
	{
		// free_all();
		// mutex_destroy_all();
		return (-1);
	}
	// pthread_createしたもの 各 philo->thread
	
	return (0);
}