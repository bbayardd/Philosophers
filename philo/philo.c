/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:05:18 by bbayard           #+#    #+#             */
/*   Updated: 2022/02/10 12:05:21 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_v_a(t_pg *p_g, int i, char **a, int argc)
{
	p_g[i].num_of_phl = ft_atoi(a[1]);
	p_g[i].t_die = ft_atoi(a[2]);
	p_g[i].t_eat = ft_atoi(a[3]);
	p_g[i].t_sleep = ft_atoi(a[4]);
	if (p_g[i].t_die <= 60 || p_g[i].t_eat <= 60
		|| p_g[i].t_sleep <= 60 || (argc == 6 && ft_atoi(a[5]) == -1))
		return (1);
	if (argc == 6)
		p_g[i].num_meals = ft_atoi(a[5]);
	else
		p_g[i].num_meals = -1;
	if (i != 2)
	{
		p_g[i].frst_p = i + 1;
		p_g[i].lst_p = p_g[i].num_of_phl - 1 - (p_g[i].num_of_phl % 2) + i;
	}
	else
		p_g[i].frst_p = p_g[i].num_of_phl;
	p_g[i].p_kind = i;
	p_g[i].last_eat = ft_time();
	p_g[i].l_m = p_g[i].last_eat;
	p_g[i].eat_count = 0;
	return (0);
}

int	main(int argc, char **argv)
{
	t_pg			*p_g;
	int				l_pg;
	int				i;
	pthread_mutex_t	std_out;

	if ((argc != 5 && argc != 6) || ft_atoi(argv[1]) == -1)
		return (ft_error("Wrong argument!", NULL, 0));
	l_pg = ft_atoi(argv[1]);
	if (l_pg == 1)
		return (one_philo(argv));
	p_g = malloc(sizeof (t_pg) * ((l_pg % 2) + 2));
	if (!p_g)
		return (0);
	i = -1;
	while (++i < (l_pg % 2) + 2)
	{
		pthread_mutex_init(&p_g[i].fork, NULL);
		if (i != 0)
			p_g[i].fork_r = &p_g[i - 1].fork;
		if (check_v_a(p_g, i, argv, argc))
			return (ft_error("Wrong argument!", p_g, i));
	}
	p_g[0].num_of_gp = i;
	group_philo(p_g, std_out);
	free(p_g);
}
