/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:49:08 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/09 15:49:10 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long	get_time(void)
{
	unsigned long	time;
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	time = tv.tv_sec * 1000 + tv.tv_usec / 1000;
	return (time);
}

unsigned long	time_ms(t_philo *p)
{
	unsigned long	now;
	unsigned long	relative;

	now = get_time();
	relative = now - p->start_time;
	return (relative);
}

void	ft_usleep(unsigned long ms)
{
	unsigned long	target;
	unsigned long	start;

	start = get_time();
	target = start + ms;
	while (start < target)
	{
		start = get_time();
		if (start >= target)
			return ;
		usleep((target - start) * 500);
	}
}
