/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 16:14:08 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/27 21:55:02 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

t_philo	set_philo(uint64_t id, sem_t *running, sem_t *forks, sem_t *print);
void	philo_process(t_philo *philo, t_args args);

int	philo_bonus(t_args args)
{
	sem_t		*running_sem;
	sem_t		*forks_sem;
	sem_t		*print_sem;
	uint64_t	i;
	t_philo		*philo;

	sem_unlink(SEM_RUNNING);
	running_sem = sem_open(SEM_RUNNING, O_CREAT, 0644, 0);  // set_sem()
	sem_unlink(SEM_FORKS);
	forks_sem = sem_open(SEM_RUNNING, O_CREAT, 0644, args.philo_num);
	sem_unlink(SEM_PRINT);
	print_sem = sem_open(SEM_RUNNING, O_CREAT, 0644, 1); 
	
	philo = ft_calloc(args.philo_num, sizeof(t_philo));
	if (!philo)
		return (-1);
	i = 0;
	while (i++ < args.philo_num)
	{
		philo[i] = set_philo(i + 1, running_sem, forks_sem, print_sem);
		philo[i].pid = fork();
		if (philo[i].pid == 0)	
			philo_process(&philo[i], args);
	}
	run_simulation(args.philo_num, running_sem);
	return (0);
}

static int	run_simulation(uint64_t philo_num, sem_t *running_sem)
{
	uint64_t	i;

	i = 0;
	while (i++ < philo_num)
		sem_post(running_sem);
	return (0);
}