/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   digits_to_uint.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 17:17:45 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 08:10:59 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

int	digits_to_uint(char *str, uint64_t *rev)
{
	int			i;
	int			digit;

	*rev = 0;
	i = 0;
	while (str[i])
	{
		digit = str[i] - '0';
		if (i > 19 || *rev > (UINT64_MAX - digit) / 10)
			return (-1);
		*rev *= 10;
		*rev = *rev + digit;
		i++;
	}
	return (0);
}
