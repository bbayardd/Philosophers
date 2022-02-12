/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbayard <bbayard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:06:23 by bbayard           #+#    #+#             */
/*   Updated: 2022/02/10 12:06:26 by bbayard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>

# include <pthread.h>
# include <signal.h>
# include <sys/wait.h>
# include <sys/time.h>

typedef struct philosophers {
	int				num_of_phl;
	int				num_of_gp;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				num_meals;
	int				frst_p;
	unsigned long	last_eat;
	int				lst_p;
	unsigned long	l_m;
	int				p_kind;
	int				eat_count;
	pthread_mutex_t	*alive_or;
	pthread_mutex_t	*meals;
	pthread_mutex_t	fork;
	pthread_mutex_t	*fork_r;
	pthread_mutex_t	*std_out;
}		t_pg;

int				ft_atoi(char *str);
int				one_philo(char **argv);
unsigned long	ft_time(void);
int				ft_error(char *str, t_pg *pg, int n);
int				mirror_str(char *str, char *str_2);
void			group_philo(t_pg *p_g, pthread_mutex_t std_out);
int				print_message(t_pg *p, char *action);
int				die_message(t_pg *p, unsigned long time);
void			destroy_mutex(t_pg *p_g, pthread_mutex_t alive_or,
					pthread_mutex_t meals, pthread_mutex_t std_out);

#endif
