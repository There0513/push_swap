/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <threiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:56:04 by threiss           #+#    #+#             */
/*   Updated: 2021/10/26 14:58:10 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	stdin_checker(t_list **a, t_list **b)
{
	char	*input;
	int		r;

	input = NULL;
	r = get_next_line(0, &input);
	while (r > 0)
	{
		if (check_instructions(input, a, b) == -1)
			break ;
		free(input);
		r = get_next_line(0, &input);
	}
	free(input);
}

int	gnl2(char *tmp, char **input, char *buf, char **line)
{
	if (buf[0] == '\n')
	{
		*line = *input;
		return (1);
	}
	*input = ft_strjoin(*input, buf);
	if (!*input)
	{
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (0);
}

int	get_next_line(int r, char **line)
{
	char	*input;
	char	buf[2];
	char	*tmp;
	int		ret;

	ret = 0;
	input = malloc(sizeof(char));
	if (!line || !input)
		return (-1);
	input[0] = 0;
	buf[1] = 0;
	r = read(0, buf, 1);
	while (r > 0)
	{
		tmp = input;
		ret = gnl2(tmp, &input, buf, line);
		if (ret != 0)
			return (ret);
		r = read(0, buf, 1);
	}
	*line = input;
	free(input);
	return (0);
}
