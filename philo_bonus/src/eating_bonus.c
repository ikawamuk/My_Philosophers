/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/27 20:59:10 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/28 22:34:11 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int	eating(t_philo *philo, t_args args)
{
	uint64_t	start_eat;
	uint64_t	now;

	
	return (0);
}

static void	update_philo_state(t_philo *philo, uint64_t *start, uint64_t *now)
{
	sem_wait(philo->meal);
	
}