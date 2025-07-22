/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 07:14:36 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/23 07:43:38 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include <stdio.h>

int	perse_arg(int ac, char *av[], t_args *args);

int	main(int ac, char *av[])
{
	t_args	args;

	if (perse_arg(ac, av, &args) == -1)
		return (EXIT_FAILURE);
	printf("philo num: %lu\n", args.philo_num);
	printf("life_time: %lu\n", args.life_time);
	printf("eat time: %lu\n", args.eat_time);
	printf("sleep time: %lu\n", args.sleep_time);
	printf("must eat: %lu\n", args.must_eat);
	// if (philo(args) == -1)
	// {
	// 	printf("Error\n");
	// 	return (EXIT_FAILURE);
	// }
	return (0);
}
