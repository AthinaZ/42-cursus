/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:48:22 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/09 15:48:25 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	sleep_or_think(t_philo *p)
{
	pthread_mutex_lock(p->print_mutex);
	printf("%6lu ms | Philo %4d | is sleeping\n", time_ms(p), p->id);
	pthread_mutex_unlock(p->print_mutex);
	ft_usleep(p->sleep);
	pthread_mutex_lock(p->print_mutex);
	printf("%6lu ms | Philo %4d | is thinking\n", time_ms(p), p->id);
	pthread_mutex_unlock(p->print_mutex);
}

void	getforks_eat(t_philo *p)
{
	pthread_mutex_lock(&(p->died));
	pthread_mutex_lock(p->print_mutex);
	printf("%6lu ms | Philo %4d | has taken a left fork\n",
		time_ms(p), p->id);
	printf("%6lu ms | Philo %4d | has taken a right fork\n",
		time_ms(p), p->id);
	printf("%6lu ms | Philo %4d | IS EATING\n",
		time_ms(p), p->id);
	pthread_mutex_unlock(p->print_mutex);
	p->last_eaten = get_time();
	pthread_mutex_unlock(&(p->died));
	ft_usleep(p->eat);
}

int	one_philo(t_args *t)
{
	if (t->nb_philos == 1)
		printf("     0 ms | Philo    1 | has taken a fork\n");
	return (0);
}

int	is_dead(t_args *t)
{
	int	i;
	int	done;

	while (1)
	{
		i = -1;
		done = 0;
		while (++i < t->nb_philos)
		{
			if (t->philos[i]->times == 0)
				continue ;
			done++;
			pthread_mutex_lock(&(t->philos[i]->died));
			if (get_time() - t->philos[i]->last_eaten > (unsigned long)t->t_die)
			{
				pthread_mutex_lock(&(t->print_mutex));
				printf("%6lu ms | Philo %4d | died\n",
					time_ms(t->philos[i]), i + 1);
				return (1);
			}
			pthread_mutex_unlock(&(t->philos[i]->died));
		}
		if (done == 0)
			return (0);
	}
}
