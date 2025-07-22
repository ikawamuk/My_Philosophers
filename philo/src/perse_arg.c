/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perse_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/21 18:17:12 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 07:46:15 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdio.h>
#include "config.h"

int			validate(int ac, char *av[]);
static int	invalid_value_check(char *av[], int *i, uint64_t (*num)[5]);
int			digits_to_uint(char *str, uint64_t *rev);
int			print_invalid_arg(char *str);

int	perse_arg(int ac, char *av[], t_args *args)
{
	uint64_t	num[5];
	int			i;

	if (validate(ac, av) == -1)
		return (-1);
	if (invalid_value_check(av, &i, &num) == -1)
		return (-1);
	args->philo_num = num[0];
	args->life_time = num[1];
	args->eat_time = num[2];
	args->sleep_time = num[3];
	if (i == 6)
		args->must_eat = num[4];
	else
		args->must_eat = 0;
	return (0);
}

static int	invalid_value_check(char *av[], int *i, uint64_t (*num)[5])
{
	*i = 1;
	while (av[*i])
	{
		if (digits_to_uint(av[*i], &(*num)[*i - 1]) == 1)
			return (print_invalid_arg("Argument is too large"));
		(*i)++;
	}
	if (*num[0] == 0)
		return (print_invalid_arg("number of philo has to be greater than 0"));
	if (*num[1] == 0)
		return (print_invalid_arg("time to die has to be greater than 0"));
	if (*i == 6)
	{
		if (*num[4] == 0)
			return (print_invalid_arg("must_eat has to be greater than 0"));
	}
	return (0);
}
