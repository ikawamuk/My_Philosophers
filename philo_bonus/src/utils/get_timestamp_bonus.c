/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_timestamp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/22 00:39:25 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 10:41:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <sys/time.h>
#include <stdio.h>

uint64_t	get_ms(void);

uint64_t	get_timestamp(uint64_t start)
{
	uint64_t	now;

	now = get_ms();
	return (now - start);
}
