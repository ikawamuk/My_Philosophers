/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 07:14:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/08/02 22:06:56 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	parse_arg(int ac, char *av[], t_args *args);

int	main(int ac, char *av[])
{
	t_args	args;

	if (parse_arg(ac, av, &args) == ERROR)
		return (EXIT_FAILURE);
	if (philo(args) == ERROR)
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
	return (0);
}
