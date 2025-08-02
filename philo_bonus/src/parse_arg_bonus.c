/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 08:04:29 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/08/02 22:00:49 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int			validate(int ac, char *av[]);
static int	convert_argv(int ac, char *av[], t_args *args);
static int	invalid_value(int ac, t_args args);

int	parse_arg(int ac, char *av[], t_args *args)
{
	if (validate(ac, av) == -1)
		return (-1);
	if (convert_argv(ac, av, args) == -1)
	{
		printf("Argument is too large\n");
		return (-1);
	}
	if (invalid_value(ac, *args) == -1)
		return (-1);
	return (0);
}

static int	convert_argv(int ac, char *av[], t_args *args)
{
	if (digits_to_uint(av[1], &args->philo_num) == -1)
		return (-1);
	if (digits_to_uint(av[2], &args->life_time) == -1)
		return (-1);
	if (digits_to_uint(av[3], &args->eat_time) == -1)
		return (-1);
	if (digits_to_uint(av[4], &args->sleep_time) == -1)
		return (-1);
	if (ac == 6)
	{
		if (digits_to_uint(av[5], &args->must_eat) == -1)
			return (-1);
	}
	else
		args->must_eat = 0;
	return (0);
}

static int	invalid_value(int ac, t_args args)
{
	if (args.philo_num == 0)
	{
		printf("number of philo has to be greater than 0\n");
		return (-1);
	}
	if (args.life_time == 0)
	{
		printf("time to die has to be greater than 0\n");
		return (-1);
	}
	if (ac == 6 && args.must_eat == 0)
	{
		printf("must_eat has to be greater than 0\n");
		return (-1);
	}
	return (0);
}
