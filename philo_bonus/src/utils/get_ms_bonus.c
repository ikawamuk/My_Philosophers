/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ms_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:08:49 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/26 13:37:11 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdint.h>
#include <sys/time.h>

uint64_t	get_ms(void)
{
	uint64_t		now;
	struct timeval	time;

	gettimeofday(&time, NULL);
	now = (uint64_t)(time.tv_sec) * 1000 + (uint64_t)(time.tv_usec) / 1000;
	return (now);
}
