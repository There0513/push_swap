/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <threiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:46:38 by threiss           #+#    #+#             */
/*   Updated: 2021/10/25 23:15:23 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	is_sorted(t_list *lst)
{
	int	min_index;
	t_list	*tmp;

	tmp = lst;
	min_index = tmp->index;
	if (tmp != 0)
	{
		tmp = tmp->next;
		while (tmp)
		{
			if (min_index + 1 != tmp->index)
				return (-1);
			min_index = tmp->index;
			tmp = tmp->next;
		}
	}
	return (1);
}

int	is_sorted_but_mixed(t_list *lst, t_data *data)
{
	int	index;

	index = 0;
	if (lst != 0)
	{
		index = lst->index;
		while (lst->next)
		{
			if (lst->next->index > index
				|| lst->next->index == data->min_a->index)
					lst = lst->next;
			else
				return (-1);
			index = lst->index;
		}
	}
	return (1);
}

int	b_is_sorted(t_list *lst)
{
	int	max;

	max = lst->val;
	if (lst != 0)
	{
		while (lst)
		{
			if (lst->val > max)
				return (-1);
			max = lst->val;
			lst = lst->next;
		}
	}
	return (1);
}

void	pre_sort_a(t_list **cpy_a, int i)
{
	int	min;
	t_list	*beginn;

	beginn = *cpy_a;
	while ((*cpy_a)->next)
	{
		if ((*cpy_a)->next->val < (*cpy_a)->val)
		{
			min = (*cpy_a)->next->val;
			(*cpy_a)->next->val = (*cpy_a)->val;
			(*cpy_a)->val = min;
			*cpy_a = beginn;
		}
		else
			*cpy_a = (*cpy_a)->next;
	}
	*cpy_a = beginn;
	i = 0;
	while ((*cpy_a)->next)
	{
		(*cpy_a)->index = i++;
		*cpy_a = (*cpy_a)->next;
	}
	(*cpy_a)->index = i;
	*cpy_a = beginn;
}

void	add_index_a(t_list **stack_a, t_list **cpy_a)
{
	t_list	*beginn;
	t_list	*tmp1;
	t_list	*tmp2;

	beginn = *stack_a;
	tmp1 = *stack_a;
	tmp2 = *cpy_a;
	pre_sort_a(&tmp2, 0);
	while (tmp2)
	{
		while (tmp1)
		{
			if (tmp2->val == tmp1->val)
				tmp1->index = tmp2->index;
			tmp1 = tmp1->next;
		}
		tmp1 = beginn;
		tmp2 = tmp2->next;
	}
}
