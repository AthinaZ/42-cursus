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
		t->philos[i]->fork_r = i;
		t->philos[i]->fork_l = (i + 1) % t->nb_philos;
		t->philos[i]->start_time = t->start_time;
		t->philos[i]->eat = t->t_eat;
		t->philos[i]->sleep = t->t_sleep;
		t->philos[i]->times = t->nb_must_eat;
		t->philos[i]->forks_mutex = t->forks_mutex;
		t->philos[i]->print_mutex = &t->print_mutex;
		pthread_mutex_init(&t->philos[i]->died, NULL);
	}
	return (0);
}

int	forks_create(t_args *t)
{
	int	i;

	i = 0;
	t->forks_mutex = malloc(sizeof(pthread_mutex_t) * t->nb_philos);
	if (!t->forks_mutex)
		return (1);
	pthread_mutex_init(&t->print_mutex, NULL);
	while (i < t->nb_philos)
	{
		pthread_mutex_init(&t->forks_mutex[i], NULL);
		i++;
	}
	return (0);
}

int	create_threads(t_args *t)
{
	int			i;
	pthread_t	*threads;

	i = 0;
	threads = malloc(sizeof(pthread_t) * t->nb_philos);
	if (!threads)
		return (1);
	while (i < t->nb_philos)
	{
		if (pthread_create(&threads[i], NULL, routine, (void *)t->philos[i]))
			return (1);
		pthread_detach(threads[i]);
		i++;
	}
	free(threads);
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
	if (forks_create(t) || philos_init(t))
		return (0);
	return (t);
}
