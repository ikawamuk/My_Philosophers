/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:56:19 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 14:08:25 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

uint64_t	print_state(t_philo *philo, char *state)
{
	uint64_t	time;

	sem_wait(philo->running);
	sem_wait(philo->print);
	time = get_timestamp(philo->start);
	if (!is_finished(philo))
		printf("%lu\t%lu %s\n", time, philo->id, state);
	sem_post(philo->print);
	sem_post(philo->running);
	return (time);
}
