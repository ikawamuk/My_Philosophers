/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:06:46 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 09:40:00 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	print_usage(char *path);
static bool	is_number(char *str);
static int	ft_isdigit(int c);

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

static int	print_usage(char *path)
{
	printf("Usage: %s "\
		"<number_of_philosophers> "\
		"<time_to_die> "\
		"<time_to_eat> "\
		"<time_to_sleep> "\
		"[number_of_times_each_philosopher_must_eat]\n", path);
	return (-1);
}

static int	ft_isdigit(int c)
{
	return ('0' <= c && c <= '9');
}
