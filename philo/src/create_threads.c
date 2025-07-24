/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_threads.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:53:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/25 00:05:04 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	*philo_loop(void *arg);

int	create_threads(t_philo *philo)
{
	uint64_t	i;

	i = 0;
	while (i < philo->ctx->philo_num)
	{
		pthread_create(&philo[i].thread, NULL, philo_loop, (void *)&philo[i]);
		i++;
	}
	return (0);
}
