/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <threiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 12:30:40 by threiss           #+#    #+#             */
/*   Updated: 2021/10/26 14:51:51 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	is_int(char *str)
{
	int	i;

	i = -1;
	if (str[i + 1] == '-' || str[i + 1] == '+')
	{
		if (ft_strlen(str) == 1)
			return (-1);
		i++;
	}
	while (str[++i])
		if (ft_isdigit(str[i]) != 1)
			return (-1);
	return (1);
}

int	ret_error_msg(char *msg, int ret)
{
	write(2, "Error\n", 6);
	printf("%s\n", msg);
	return (ret);
}

int	check_doubles(int nb, int i, char **split)
{
	int	j;

	j = -1;
	while (++j < i)
		if (nb == ft_atoll(split[j]))
			return (-1);
	return (1);
}

int	error_handling(int ac, char **split)
{
	int	i;

	i = -1;
	if (ac < 2)
		return (-1);
	if (ac > 5000)
		return (-1);
	while (++i < ac - 1)
	{
		if (ft_strlen(split[i]) == 0)
			return (ret_error_msg("No integer.", -1));
		if (ft_strncmp(split[i], "", 1) == 0)
			return (ret_error_msg("No integer.", -1));
		if (is_int(split[i]) != 1)
			return (ret_error_msg("No integer.", -1));
		if (ft_atoll(split[i]) > 2147483646 || ft_atoll(split[i]) < -2147483646)
			return (ret_error_msg("Attention int min int max.", -1));
		if (check_doubles(ft_atoll(split[i]), i, split) != 1)
			return (ret_error_msg("Attention doubles.", -1));
	}
	return (1);
}
