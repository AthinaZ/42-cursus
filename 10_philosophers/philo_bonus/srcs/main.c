/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:48:51 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/09 15:48:53 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	routine(void *philo)
{
	t_philo	*p;
	int		start;

	start = 1;
	p = (t_philo *)philo;
	while (p->times != 0)
	{
		sem_wait(p->forks);
		sem_wait(p->forks);
		getforks_eat(p);
		sem_post(p->forks);
		sem_post(p->forks);
		sleep_or_think(p);
		(p->times)--;
		start = 0;
	}
	return (0);
}

void	stop(t_args *t)
{
	int	i;

	i = 0;
	while (i < t->nb_philos)
	{
		sem_close(t->philos[i]->died);
		sem_unlink("/s_died");
		free(t->philos[i++]);
	}
	sem_close(t->print);
	sem_close(t->forks);
	sem_unlink("/s_forks");
	sem_unlink("/s_print");
	free(t->philos);
	free(t);
}

int	one_philo(t_args *t)
{
	if (t->nb_philos == 1)
		printf("     0 ms  |  Philo    1  |  has taken a fork\n");
	return (0);
}

int	main(int argc, char **argv)
{
	t_args	*t;
	int		i;
	int		ret;

	t = init(argc, argv);
	if (!t || create_threads(t))
	{
		printf(""RED"*****  Argument Error... Try Again!!  *****"OFF"\n\n");
		return (1);
	}
	one_philo(t);
	i = -1;
	while (++i < t->nb_philos)
	{
		waitpid(-1, &ret, WUNTRACED);
		if (ret != 0)
		{
			i = -1;
			while (++i < t->nb_philos)
				kill(t->philos[i]->pid, SIGINT);
		}
	}
	stop(t);
	return (0);
}
