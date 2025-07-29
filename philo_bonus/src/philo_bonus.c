/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/29 02:43:46 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/29 11:54:23 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_philo	set_philo(t_args args, bool *is_running);

int	philo_bonus(t_args args)
{
	t_philo	philo;
	bool	is_running;

	philo = set_philo(args, &is_running);
	return (0);
}