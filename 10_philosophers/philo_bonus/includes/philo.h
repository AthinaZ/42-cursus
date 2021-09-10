/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azouzoul <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 15:47:29 by azouzoul          #+#    #+#             */
/*   Updated: 2021/09/09 15:47:57 by azouzoul         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <sys/time.h>
# include <signal.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <fcntl.h>

# define	OFF			"\033[0m"
# define	RED			"\033[0;31m"
# define	CYAN		"\033[0;36m"
# define	PUR			"\033[0;35m"
# define	GREEN		"\033[0;32m"

typedef struct s_philo
{
	int				id;
	int				pid;
	unsigned long	last_eaten;
	unsigned long	start_time;
	int				eat;
	int				sleep;
	int				die;
	int				times;
	sem_t			*forks;
	sem_t			*print;
	sem_t			*died;
}				t_philo;

typedef struct s_args
{
	int				nb_philos;
	unsigned long	start_time;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				nb_must_eat;
	t_philo			**philos;
	sem_t			*forks;
	sem_t			*print;
}				t_args;

void			watermark(void);
int				ft_atoi(const char *str);
unsigned long	get_time(void);
unsigned long	time_ms(t_philo *p);
int				is_dead(t_philo *p);
void			sleep_or_think(t_philo *p);
void			getforks_eat(t_philo *p);
void			ft_usleep(unsigned long micro);
int				create_threads(t_args *t);
t_args			*init(int ac, char **av);
void			parse(t_args *t, int ac, char **av);
int				isallnum(char **av, int i, int j);
int				routine(void *philo);

#endif
