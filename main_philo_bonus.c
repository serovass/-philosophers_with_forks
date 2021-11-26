/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_philo_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gnaida <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 17:11:36 by gnaida            #+#    #+#             */
/*   Updated: 2021/11/26 17:11:46 by gnaida           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_parse_argc(int argc, char **argv, t_data *data)
{
	if (argc == 5 || argc == 6)
	{
		data->death_flag = 0;
		data->philos = ft_atoi(argv[1]);
		data->die_time = ft_atoi(argv[2]);
		data->eat_time = ft_atoi(argv[3]);
		data->sleep_time = ft_atoi(argv[4]);
		if (argc == 6)
			data->lunches = ft_atoi(argv[5]);
		else
			data->lunches = -1;
		if (data->philos <= 0 || data->philos > 200)
			;
		else if (data->die_time < 60)
			;
		else if (data->eat_time < 60)
			;
		else if (data->sleep_time < 60)
			;
		else if (data->lunches > 0 || data->lunches == -1)
			return (0);
	}
	ft_write_msg("wrong usage!!!\n");
	return (-1);
}

int	ft_create_philos(t_data *data, t_philo *philo)
{
	int i;

	philo = (t_philo *)malloc(sizeof(t_philo) * data->philos);
	if (philo == NULL)
		return (-1);
    i = 0;
	while (i < data->philos)
	{
		philo[i].philo_id = i + 1;
		philo[i].lunches_to_eat = data->lunches;
		philo[i].data = data;
		i++;
	}
	return (0);
}

void ft_philo_process(t_philo *philo, int philos_num, int i)
{
    while (i < philos_num)
    {
		philo[i].philo_pid = fork();
		if (philo[i].philo_pid == 0)
			//simulation_fanction(&philo[i]);//
		i += 2;
    }
}

int	main(int argc, char **argv)
{
	t_data	data;
	t_philo *philo;

	if (ft_parse_argc(argc, argv, &data) < 0)
		return (0);
	sem_unlink("sem_forks");
	sem_unlink("sem_msg");
	data.sem_forks = sem_open("sem_forks", O_CREAT, S_IRWXU, data.philos / 2);
	data.sem_msg = sem_open("sem_msg", S_IRWXU, O_CREAT, 1);
	if (ft_create_philos(&data, philo) < 0)
		return (0);
	ft_philo_process(philo, data.philos, 0);
	ft_philo_process(philo, data.philos, 1);
	waitpid(-1, NULL, 0);
	//kill_philos_process();//
	sem_close(data.sem_forks);
	sem_close(data.sem_msg);
	sem_unlink("sem_forks");
	sem_unlink("sem_msg");
	return (0);
}
