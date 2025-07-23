/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 09:37:11 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 09:39:52 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	UTILS_H
# define UTILS_H

# include <stdint.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <sys/time.h>
# include "config.h"

int	digits_to_uint(char *str, uint64_t *rev);
void	*ft_calloc(size_t nmemb, size_t size);
uint64_t	get_ms(void);

#endif