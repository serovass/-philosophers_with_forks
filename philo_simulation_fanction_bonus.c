/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_simulation_fanction_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:12:51 by gnaida            #+#    #+#             */
/*   Updated: 2021/11/26 17:12:55 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

static void	ft_write_philo_msg(t_philo *philo, char *msg)
{
    sem_wait(philo->data->sem_msg);
	ft_putnbr_fd((int)ft_get_time_in_millis() \
			- (int)philo->simulation_start, 1);
	write(1, " ", 1);
	ft_putnbr_fd(philo->philo_id, 1);
	ft_write_msg(msg);
	if (msg[1] == 'd')
		exit (-1);
    sem_post(philo->data->sem_msg);
}

int	ft_check_if_death(t_philo *philo)
{
	if ((ft_get_time_in_millis() - philo->last_time_ate) > \
			(unsigned long)philo->data->die_time)
	{
		ft_write_philo_msg(philo, " died\n");
		return (1);
	}
	return (0);
}

static void	ft_eat(t_philo *philo)
{
	if (philo->data->philos == 1)
	{
		while (!ft_check_if_death(philo))
			usleep(100);
		return ;
	}
    sem_wait(philo->data->sem_forks);
	ft_write_philo_msg(philo, " has taken a fork\n");
    ft_write_philo_msg(philo, " has taken a fork\n");
	if (ft_check_if_death(philo))
		exit (-1);
	ft_write_philo_msg(philo, " is eating\n");
    sem_wait(philo->data->sem_lunch_time);
	philo->last_time_ate = ft_get_time_in_millis();
    sem_post(philo->data->sem_lunch_time);
	ft_wait_for_time(philo->data->eat_time, philo);
    sem_post(philo->data->sem_forks);
}

void	simulation_fanction(t_philo *philo)
{
	philo->simulation_start = ft_get_time_in_millis();
	philo->last_time_ate = philo->simulation_start;
	while (1)
	{
		if (ft_check_if_death(philo))
			exit (-1);
		if (philo->lunches_to_eat == 0)
			exit (-1);
		ft_eat(philo);
		if (philo->lunches_to_eat > 0)
			philo->lunches_to_eat--;
		if (ft_check_if_death(philo))
			exit (-1);
		ft_write_philo_msg(philo, " is sleeping\n");
		ft_wait_for_time(philo->data->sleep_time, philo);
		if (ft_check_if_death(philo))
			exit (-1);
		ft_write_philo_msg(philo, " is thinking\n");
		if (philo->data->philos % 2)
			ft_wait_for_time(1, philo);
	}
}
