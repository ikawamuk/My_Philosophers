/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:35:49 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/08/02 22:00:47 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>

int	parse_arg(int ac, char *av[], t_args *args);

int	main(int ac, char *av[])
{
	t_args	args;

	if (perse_arg(ac, av, &args) == -1)
		return (EXIT_FAILURE);
	if (philo_bonus(args) == -1)
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
	return (0);
}
