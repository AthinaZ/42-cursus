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
	sem_wait(p->print);
	printf("%6lu ms  |  Philo %4d  |  is sleeping\n", time_ms(p), p->id);
	sem_post(p->print);
	ft_usleep(p->sleep);
	sem_wait(p->print);
	printf("%6lu ms  |  Philo %4d  |  is thinking\n", time_ms(p), p->id);
	sem_post(p->print);
}

void	getforks_eat(t_philo *p)
{
	sem_wait(p->died);
	sem_wait(p->print);
	printf("%6lu ms  |  Philo %4d  |  has taken a left fork\n",
		time_ms(p), p->id);
	printf("%6lu ms  |  Philo %4d  |  has taken a right fork\n",
		time_ms(p), p->id);
	printf("%6lu ms  |  Philo %4d  |  IS EATING\n",
		time_ms(p), p->id);
	sem_post(p->print);
	p->last_eaten = get_time();
	sem_post(p->died);
	ft_usleep(p->eat);
}

int	is_dead(t_philo *p)
{
	while (1)
	{
		sem_wait(p->died);
		if (get_time() - p->last_eaten > (unsigned long)p->die)
		{
			sem_wait(p->print);
			printf("%6lu ms  |  Philo %4d  |  died\n",
				time_ms(p), p->id);
			exit(1);
		}
		sem_post(p->died);
		if (p->times == 0)
			exit(0);
		usleep(500);
	}
	return (0);
}
