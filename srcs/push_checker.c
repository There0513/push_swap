/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <threiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:52:56 by threiss           #+#    #+#             */
/*   Updated: 2021/10/25 23:08:08 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void time_to_free(t_all *all, char **av)
{
	(void)av;
	int i;

	i = -1;
	ft_lstclear(&all->a, free);
	ft_lstclear(&all->cpy_a, free);
	while (all->split[++i])
		free(all->split[i]);
	free(all->split);
}

void init_all(t_all *all)
{
	all->a = 0;
	all->cpy_a = 0;
	all->b = 0;
	all->split = 0;
}

int check_one_arg(int ac, t_all *all)
{
	int i;
	i = -1;
	while (++i < ac)
	{
		if (ft_strncmp(all->split[i], "", 1) == 0)
			return (ret_error_msg("No integer.", -1));
		if (is_int(all->split[i]) != 1)
			return (ret_error_msg("No integer.", -1));
		if (ft_atoll(all->split[i]) > 2147483646 || ft_atoll(all->split[i]) < -2147483646)
			return (ret_error_msg("Attention int min int max.", -1));
		if (check_doubles(ft_atoll(all->split[i]), i, all->split) != 1)
			return (ret_error_msg("Attention doubles.", -1));
	}
	return (0);
}

int arg_ac_two(t_all *all, char **av, int *ac)
{
	int i;

	i = 0;
	all->split = ft_split(av[1], ' ');
	while (all->split[i])
		i++;
	if (i == 1)
	{
		if (check_one_arg(i, all) != 0)
			return (-1);
		*ac = 2;
	}
	return (0);
}

int check_nd_prepare(int ac, char **av, t_all *all)
{
	int i;
	int j;

	i = 0;
	if (ac == 2)
	{
		if (arg_ac_two(all, av, &ac) == -1)
			return (-1);
	}
	else
	{
		all->split = malloc((sizeof(char *) * ac));
		if (!all->split)
			return (-1);
		j = -1;
		while (av[++i])
			all->split[++j] = ft_strdup(av[i]);
		all->split[++j] = 0;
	}
	if (ac < 2)
		return (ret_error_msg("No arguments given.", -1));
	if (error_handling(ac, all->split) == -1)
		return (0);
	return (1);
}
