/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 11:45:43 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 12:16:28 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

void	print_state(t_philo *philo, uint64_t id, char *state)
{
	uint64_t	time;
	bool		finished;

	pthread_mutex_lock(&philo->cmn->finished_mutex);
	finished = philo->cmn->finished;
	pthread_mutex_unlock(&philo->cmn->finished_mutex);
	pthread_mutex_lock(&philo->cmn->print_mutex);
	time = get_timestamp(philo->ctx->start);
	if (!finished)
		printf("%lu\t%lu %s\n", time, id, state);
	pthread_mutex_unlock(&philo->cmn->print_mutex);
	return ;
}
