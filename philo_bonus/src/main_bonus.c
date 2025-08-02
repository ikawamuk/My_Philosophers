/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:35:49 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/08/02 22:06:30 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"
#include <stdio.h>

int	parse_arg(int ac, char *av[], t_args *args);

int	main(int ac, char *av[])
{
	t_args	args;

	if (perse_arg(ac, av, &args) == ERROR)
		return (EXIT_FAILURE);
	if (philo_bonus(args) == ERROR)
	{
		printf("Error\n");
		return (EXIT_FAILURE);
	}
	return (0);
}
