/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:39:21 by bbayard           #+#    #+#             */
/*   Updated: 2022/02/10 14:39:23 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_nbr(unsigned long n)
{
	char	t;

	if (n < 10)
	{
		t = n + '0';
		write(1, &t, 1);
	}
	else
	{
		put_nbr(n / 10);
		t = n % 10 + '0';
		write(1, &t, 1);
	}
}

int	die_message(t_pg *p, unsigned long time)
{
	put_nbr(time);
	write(1, " ", 1);
	put_nbr(p->frst_p);
	write(1, " died\n", 6);
	return (0);
}

int	print_message(t_pg *p, char *action)
{
	int				x;
	unsigned long	time;
	int				z;

	x = p->frst_p;
	time = ft_time();
	z = mirror_str(action, "has taken a fork");
	while (x < p->lst_p)
	{
		if (z)
			printf("%ld %d %s\n", time - p->last_eat, x, action);
		printf("%ld %d %s\n", time - p->last_eat, x, action);
		x = x + 2;
	}
	if (z)
		printf("%ld %d %s\n", time - p->last_eat, x, action);
	printf("%ld %d %s\n", time - p->last_eat, x, action);
	return (0);
}
