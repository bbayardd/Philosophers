/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:05:32 by bbayard           #+#    #+#             */
/*   Updated: 2022/02/10 12:05:37 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	one_philo(char **a)
{
	int		t_d;
	long	real_time;

	real_time = ft_time();
	t_d = ft_atoi(a[2]);
	if (t_d <= 60 || ft_atoi(a[3]) <= 60
		|| ft_atoi(a[4]) <= -1)
		return (ft_error("Wrong argument!", NULL, 0));
	printf("%ld 1 has taken a fort\n", real_time - real_time);
	printf("%d 1 died\n", t_d + 1);
	return (0);
}

void	*sum_eat(void *p_g)
{
	t_pg	*pg;
	int		i;

	pg = (t_pg *)p_g;
	i = -1;
	if (pg->num_meals != 0)
		pthread_mutex_lock(pg->meals);
	while (pg->num_meals != 0 && ++i < pg->num_of_gp)
		pthread_mutex_lock(pg->meals);
	printf("End simulation!\n");
	pthread_mutex_unlock(pg->alive_or);
	return (NULL);
}

void	*p_died(void *p_g)
{
	t_pg	*pg;

	pg = (t_pg *)p_g;
	while (1)
	{
		if ((int)(ft_time() - pg->l_m) > pg->t_die)
		{
			pthread_mutex_lock(pg->std_out);
			die_message(pg, (ft_time() - pg->l_m));
			pthread_mutex_unlock(pg->alive_or);
			pthread_mutex_unlock(pg->std_out);
			return (NULL);
		}
		else if (pg->num_meals != -1 && pg->eat_count >= pg->num_meals)
		{
			usleep(pg->num_of_phl);
			pthread_mutex_unlock(pg->meals);
			return (NULL);
		}
	}
}

void	*philo_act(void *p_g)
{
	t_pg		*pg;
	pthread_t	dskrp;

	pg = (t_pg *)p_g;
	pthread_create(&dskrp, NULL, p_died, pg);
	usleep(pg->t_eat * pg->p_kind);
	while (pg->num_meals > pg->eat_count || pg->num_meals == -1)
	{
		pthread_mutex_lock(&pg->fork);
		pthread_mutex_lock(pg->fork_r);
		pthread_mutex_lock(pg->std_out);
		print_message(pg, "has taken a fork");
		print_message(pg, "eating");
		pthread_mutex_unlock(pg->std_out);
		pg->l_m = ft_time();
		usleep(pg->t_eat * 1000);
		pthread_mutex_unlock(&pg->fork);
		pthread_mutex_unlock(pg->fork_r);
		pg->eat_count++;
		print_message(pg, "sleeping");
		usleep(pg->t_sleep * 1000);
		print_message(pg, "thinking");
	}
	return (NULL);
}

void	group_philo(t_pg *p_g, pthread_mutex_t std_out)
{
	pthread_t		dskrpt;
	pthread_mutex_t	alive_or;
	pthread_mutex_t	meals;
	int				i;

	i = -1;
	pthread_mutex_init(&alive_or, NULL);
	pthread_mutex_init(&meals, NULL);
	pthread_mutex_init(&std_out, NULL);
	pthread_mutex_lock(&alive_or);
	p_g[0].fork_r = &p_g[p_g->num_of_gp - 1].fork;
	while (++i < p_g[0].num_of_gp)
	{
		p_g[i].meals = &meals;
		p_g[i].alive_or = &alive_or;
		p_g[i].std_out = &std_out;
		pthread_create(&dskrpt, NULL, philo_act, &p_g[i]);
	}
	if (p_g[0].num_meals != -1)
		pthread_create(&dskrpt, NULL, sum_eat, &p_g[0]);
	pthread_mutex_lock(&alive_or);
	destroy_mutex(p_g, alive_or, meals, std_out);
}
