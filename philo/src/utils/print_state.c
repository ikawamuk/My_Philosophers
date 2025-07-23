/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:45:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/24 00:42:06 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

uint64_t	print_state(t_philo *philo, uint64_t id, char *state)
{
	uint64_t	time;

	pthread_mutex_lock(&philo->cmn->finished_mutex);
	pthread_mutex_lock(&philo->cmn->print_mutex);
	time = get_timestamp(philo->ctx->start);
	if (!philo->cmn->finished)
		printf("%lu\t%lu %s\n", time, id, state);
	pthread_mutex_unlock(&philo->cmn->print_mutex);
	pthread_mutex_unlock(&philo->cmn->finished_mutex);
	return (time);
}
