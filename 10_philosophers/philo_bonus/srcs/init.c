/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:48:35 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/09 15:48:38 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	philos_init(t_args *t)
{
	int	i;

	t->philos = malloc(sizeof(t_philo *) * t->nb_philos);
	if (!t->philos)
		return (1);
	i = -1;
	while (++i < t->nb_philos)
	{
		t->philos[i] = malloc(sizeof(t_philo));
		if (!t->philos[i])
			return (1);
		t->philos[i]->id = i + 1;
		t->philos[i]->last_eaten = t->start_time;
		t->philos[i]->start_time = t->start_time;
		t->philos[i]->eat = t->t_eat;
		t->philos[i]->sleep = t->t_sleep;
		t->philos[i]->die = t->t_die;
		t->philos[i]->times = t->nb_must_eat;
		t->philos[i]->forks = t->forks;
		t->philos[i]->print = t->print;
		sem_unlink("/s_died");
		t->philos[i]->died = sem_open("/s_died", O_CREAT | O_EXCL, 01411, 1);
	}
	return (0);
}

int	create_threads(t_args *t)
{
	int			i;
	pthread_t	thread;

	i = 0;
	while (i < t->nb_philos)
	{
		t->philos[i]->pid = fork();
		if (t->philos[i]->pid == 0)
		{
			if (pthread_create(&thread, NULL, (void *)is_dead,
					(void *)t->philos[i]))
				return (1);
			pthread_detach(thread);
			routine(t->philos[i]);
			exit(1);
		}
		i++;
	}
	return (0);
}

int	init_forks(t_args *t)
{
	sem_unlink("/s_forks");
	sem_unlink("/s_print");
	t->forks = sem_open("/s_forks", O_CREAT | O_EXCL, 01411, t->nb_philos);
	t->print = sem_open("/s_print", O_CREAT | O_EXCL, 01411, 1);
	if (!t->forks || !t->print)
		return (1);
	return (0);
}

t_args	*init(int ac, char **av)
{
	t_args	*t;

	watermark();
	if (ac < 5 || ac > 6)
		return (0);
	t = malloc(sizeof(t_args));
	if (!t)
		return (0);
	if (isallnum(av, 0, 1))
		parse(t, ac, av);
	if (t->nb_philos > 200 || t->t_die < 60 || t->t_eat < 60 || t->t_sleep < 60)
	{
		free(t);
		return (0);
	}
	t->start_time = get_time();
	if (init_forks(t) || philos_init(t))
		return (0);
	return (t);
}
