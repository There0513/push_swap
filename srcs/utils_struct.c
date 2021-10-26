/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <threiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 10:20:35 by threiss           #+#    #+#             */
/*   Updated: 2021/10/26 14:08:23 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
 **	1E99 = infinity
 */

t_list	*get_min_lst(t_list *lst)
{
	double	min;
	t_list	*ret;
	int		pos;

	min = 1E99;
	ret = NULL;
	pos = 0;
	if (lst != 0)
	{
		min = lst->val;
		while (lst)
		{
			if (lst->val <= min)
			{
				min = lst->val;
				ret = lst;
				ret->pos = pos;
			}
			lst = lst->next;
			pos++;
		}
	}
	return (ret);
}

t_list	*get_max_lst(t_list *lst)
{
	double	max;
	t_list	*ret;
	int		pos;

	max = 1E99;
	ret = NULL;
	pos = 0;
	if (lst != 0)
	{
		max = lst->val;
		while (lst)
		{
			if (lst->val >= max)
			{
				max = lst->val;
				ret = lst;
				ret->pos = pos;
			}
			lst = lst->next;
			pos++;
		}
	}
	return (ret);
}

t_list	*get_hold_first(t_list *lst, t_data *data)
{
	t_list	*ret;
	int		pos;

	ret = NULL;
	pos = 0;
	if (lst != 0)
	{
		while (lst)
		{
			if (lst->index <= data->chunk_actu)
			{
				ret = lst;
				ret->pos = pos;
				return (ret);
			}
			lst = lst->next;
			pos++;
		}
	}
	return (ret);
}

t_list	*get_hold_sec(t_list *lst, t_data *data)
{
	t_list	*ret;
	int		pos;

	ret = NULL;
	pos = 0;
	if (lst != 0)
	{
		while (lst)
		{
			if (lst->index <= data->chunk_actu)
			{
				ret = lst;
				ret->pos = pos;
			}
			lst = lst->next;
			pos++;
		}
	}
	return (ret);
}

void	fill_struct(t_data *data, t_list *stack_a, t_list *stack_b)
{
	data->max_a = get_max_lst(stack_a);
	data->max_b = get_max_lst(stack_b);
	data->min_a = get_min_lst(stack_a);
	data->min_b = get_min_lst(stack_b);
	data->lst_size_a = ft_lstsize(stack_a);
	data->lst_size_b = ft_lstsize(stack_b);
	if (data->lst_size_orig > 5)
	{
		data->hold_first = get_hold_first(stack_a, data);
		data->hold_sec = get_hold_sec(stack_a, data);
	}
}
