/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:53:41 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/24 00:57:22 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int			thinking(t_philo *philo);
int			eating(t_philo *philo);
int			sleeping(t_philo *philo);
static void	take_break(t_philo *philo);
static void	odd_case_sleep(t_philo *philo);

void	*philo_loop(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	take_break(philo);
	while (1)
	{
		if (thinking(philo) == 1)
			break ;
		if (eating(philo) == 1)
			break ;
		if (sleeping(philo) == 1)
			break ;
	}
	return (NULL);
}

static void	take_break(t_philo *philo)
{
	if ((philo->ctx->philo_num % 2) == 0)
	{
		if ((philo->id - 1) % 2 == 0)
			usleep(philo->ctx->eat_time * 1000);
	}
	else
		odd_case_sleep(philo);
}

static void	odd_case_sleep(t_philo *philo)
{
	uint64_t	break_time;

	if ((philo->id - 1) % 2 == 0)
	{
		break_time = philo->ctx->eat_time / philo->ctx->philo_num;
		break_time *= 2 * philo->ctx->philo_num - philo->id - 1;
	}
	else
	{
		break_time = philo->ctx->eat_time / philo->ctx->philo_num;
		break_time *= philo->ctx->philo_num - philo->id - 1;		
	}
	usleep(1000 * break_time);
	return ;
}
