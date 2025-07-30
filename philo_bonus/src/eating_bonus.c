/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/31 01:21:51 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/31 02:13:29 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

void	eating(t_philo *philo)
{
	uint64_t	start_eat;
	uint64_t	now;

	start_eat = print_state(philo, "is eating");
	now = start_eat;
	while (now - start_eat < philo->args.eat_time)
	{
		usleep(100);
		now = get_timestamp(philo->start);
	}
	usleep(200);	
	return ;	
}
