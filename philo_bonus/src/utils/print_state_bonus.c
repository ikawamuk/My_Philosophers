/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_state_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 21:56:19 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 01:20:40 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

uint64_t	print_state(t_philo *philo, char *state)
{
	uint64_t	time;

	sem_wait(philo->sems.print);
	time = get_timestamp(philo->start);
	printf("%lu\t%lu %s\n", time, philo->id, state);
	sem_post(philo->sems.print);
	return (time);
}
