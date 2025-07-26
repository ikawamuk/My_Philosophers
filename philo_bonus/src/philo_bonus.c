/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ikawamuk <ikawamuk@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/26 12:39:28 by ikawamuk          #+#    #+#             */
/*   Updated: 2025/07/26 13:34:01 by ikawamuk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils_bonus.h"

int	philo_bonus(t_args args)
{
	sem_t		*forks;
	uint64_t	i;
	pid_t		pid;

	sem_unlink(SEM_NAME);
	forks = sem_open(SEM_NAME, O_CREAT, 600, args.philo_num);

	// 子プロセスの処理
	i = 0;
	while (i++ < 0)
	{
			pid = fork();
		if (pid == 0)
		{
			sem_wait(forks);
			printf("%lu has taken a fork\n", i);
			sem_wait(forks);
			sem_close(forks);
			exit(0);
		}
	}
	
	sem_unlink(SEM_NAME);
	if (sem_close(forks) == -1)
		return (1);
	return (0);
}