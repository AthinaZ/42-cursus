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

void	*routine(void *philo)
{
	t_philo	*p;
	int		start;

	start = 1;
	p = (t_philo *)philo;
	while (p->times != 0)
	{
		if (start && p->id % 2 == 0)
			ft_usleep(p->eat);
		pthread_mutex_lock(&(p->forks_mutex[p->fork_l]));
		pthread_mutex_lock(&(p->forks_mutex[p->fork_r]));
		getforks_eat(p);
		pthread_mutex_unlock(&(p->forks_mutex[p->fork_l]));
		pthread_mutex_unlock(&(p->forks_mutex[p->fork_r]));
		sleep_or_think(p);
		(p->times)--;
		start = 0;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	t_args	*t;
	int		i;

	t = init(argc, argv);
	if (!t || create_threads(t))
	{
		printf(""RED"*****  Argument Error... Try Again!!  *****"OFF"\n\n");
		return (1);
	}
	one_philo(t);
	is_dead(t);
	i = 0;
	while (i < t->nb_philos)
	{
		pthread_mutex_destroy(&t->philos[i]->died);
		free(t->philos[i]);
		pthread_mutex_destroy(&t->forks_mutex[i++]);
	}
	pthread_mutex_destroy(&t->print_mutex);
	free(t->philos);
	free(t->forks_mutex);
	free(t);
	return (0);
}
