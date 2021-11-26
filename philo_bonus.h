/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:12:07 by gnaida            #+#    #+#             */
/*   Updated: 2021/11/26 17:12:10 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <pthread.h>
#include <semaphore.h>
#include <unistd.h>

typedef struct s_data
{
	int		philos;
	int		die_time;
	int		eat_time;
	int		sleep_time;
	int		lunches;
	int		death_flag;
	sem_t	*sem_forks;
	sem_t	*sem_msg;
	sem_t	*sem_lunch_time;
}	t_data;

typedef struct s_philo
{
	pid_t			philo_pid;
	int				philo_id;
	unsigned long	simulation_start;
	unsigned long	last_time_ate;
	int				lunches_to_eat;
	t_data			*data;
}	t_philo;

int				ft_atoi(const char *str);
void			ft_write_msg(char *msg);
unsigned long	ft_get_time_in_millis(void);
void			ft_wait_for_time(unsigned long wait_time, t_philo *philo);
int				ft_check_if_death(t_philo *philo);
void			simulation_fanction(t_philo *philo);
void			ft_putnbr_fd(int n, int fd);

#endif
