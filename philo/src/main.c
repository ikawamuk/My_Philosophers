/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 07:14:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/08/02 22:00:23 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	parse_arg(int ac, char *av[], t_args *args);

int	main(int ac, char *av[])
{
	t_args	args;

	if (parse_arg(ac, av, &args) == -1)
		return (EXIT_FAILURE);
	if (philo(args) == -1)
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
	return (0);
}
