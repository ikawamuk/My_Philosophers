/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:40:08 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/30 23:55:34 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_BONUS_H
# define UTILS_BONUS_H

# include "config_bonus.h"

int			digits_to_uint(char *str, uint64_t *rev);
uint64_t	get_ms(void);
uint64_t	get_timestamp(uint64_t start);
bool		is_finished(t_philo *philo);
uint64_t	print_state(t_philo *philo, char *state);

#endif