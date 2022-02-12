/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:06:05 by bbayard           #+#    #+#             */
/*   Updated: 2022/02/10 12:06:07 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	mirror_str(char *str, char *str_2)
{
	while (*str)
	{
		if (*str == *str_2++)
			str++;
		else
			return (0);
	}
	return (1);
}

int	ft_error(char *str, t_pg *pg, int n)
{
	int	i;

	i = -1;
	printf("%s\n", str);
	if (pg != NULL)
	{
		while (++i > n)
			free(&pg[i]);
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int		sign;
	int		num;
	long	l_num;

	sign = 1;
	num = 0;
	l_num = 0;
	if (!*str)
		return (-1);
	while ((*str >= 9 && *str <= 13) || *str == ' ')
		return (-1);
	if (*str == '-' || *str == '+')
		return (-1);
	while (*str >= '0' && *str <= '9')
	{
		num = (num * 10) + (*str - '0') * sign;
		l_num = (l_num * 10) + (*str++ - '0') * sign;
		if (sign > 0 && l_num < 0)
			return (-1);
	}
	if (num == 0)
		return (-1);
	return (num);
}

unsigned long	ft_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

void	destroy_mutex(t_pg *p_g, pthread_mutex_t alive_or,
	pthread_mutex_t meals, pthread_mutex_t std_out)
{
	int	i;

	i = -1;
	while (++i < p_g[0].num_of_gp)
		pthread_mutex_destroy(&p_g[i].fork);
	pthread_mutex_destroy(&alive_or);
	pthread_mutex_destroy(&meals);
	pthread_mutex_destroy(&std_out);
}
