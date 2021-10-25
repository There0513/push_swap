/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <threiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/04 15:56:04 by threiss           #+#    #+#             */
/*   Updated: 2021/10/25 18:57:15 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	stdin_checker(t_list **a, t_list **b)
{
	char	*input;
	int	r;

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

int	get_next_line(int fd, char **line)
{
	char	*input;
	char	buf[2];
	char	*tmp;
	int	r;

	input = malloc(sizeof(char));
	if (!line || !input)
		return (-1);
	input[0] = 0;
	buf[1] = 0;
	r = read(fd, buf, 1);
	while (r > 0)
	{
		tmp = input;
		if (buf[0] == '\n')
		{
			*line = input;
			return (1);
		}
		input = ft_strjoin(input, buf);
		if (!input)
		{
			free(tmp);
			return (-1);
		}
		free(tmp);
		r = read(fd, buf, 1);
	}
	*line = input;
	free(input);
	return (0);
}
