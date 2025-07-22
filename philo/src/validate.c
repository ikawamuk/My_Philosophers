/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:06:46 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 08:08:26 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>

int	validate(int ac, char *av[])
{
	int	i;

	if (ac != 5 && ac != 6)
		return (print_usage(av[0]));
	i = 1;
	while (i < ac)
		if (!is_number(av[i++]))
		{
			printf("Arguments may only contain digits 0-9");
			return (-1);
		}
	return (0);
}

static bool	is_number(char *str)
{
	if (!str || !*str)
		return (false);
	while (*str)
	{
		if (!ft_isdigit(*str++))
			return (false);
	}
	return (true);
}
