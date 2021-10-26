/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <threiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:47:46 by threiss           #+#    #+#             */
/*   Updated: 2021/10/26 14:03:42 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	swap_three_cond(t_list **a, t_data data)
{
	if (data.max_a->pos == data.lst_size_a - 1 && data.min_a->pos == 1)
		swap_operat(a, "sa");
	else if (data.max_a->pos == 0 && data.min_a->pos == data.lst_size_a - 1)
	{
		rotate_operat(a, "ra");
		swap_operat(a, "sa");
	}
	else if (data.max_a->pos == 0 && data.min_a->pos == 1)
		rotate_operat(a, "ra");
	else if (data.min_a->pos == 0 && data.max_a->pos == 1)
	{
		rrotate_operat(a, "rra");
		swap_operat(a, "sa");
	}
	else if (data.min_a->pos == data.lst_size_a - 1 && data.max_a->pos == 1)
		rrotate_operat(a, "rra");
}

void	middle_b_five(t_list **a, t_list **b)
{
	if (((*b)->index + 1) == (*a)->index)
		push_operat(b, a, "pa");
	else if ((*b)->index - 1 == (*a)->index)
	{
		push_operat(b, a, "pa");
		swap_operat(a, "sa");
	}
	else if ((*b)->index > ft_lstsize(*a) / 2)
		rrotate_operat(a, "rra");
	else
		rotate_operat(a, "ra");
}

void	swap_five_cond(t_list **a, t_list **b, t_data *data)
{
	if (is_sorted_but_mixed(*a, data) == 1 && !(*b))
	{
		if (data->min_a->pos > data->lst_size_a / 2)
			while (is_sorted(*a) != 1)
				rrotate_operat(a, "rra");
		else
			while (is_sorted(*a) != 1)
				rotate_operat(a, "ra");
	}
	else if (*b)
	{
		if ((*b)->val < data->min_a->val && is_sorted(*a) == 1)
			push_operat(b, a, "pa");
		else if ((*b)->val > (*data).max_a->val && is_sorted(*a) == 1)
		{
			push_operat(b, a, "pa");
			rotate_operat(a, "ra");
		}
		else
			middle_b_five(a, b);
	}
}

void	swap_five(t_list **a, t_list **b)
{
	t_data	data;

	data.lst_size_orig = ft_lstsize(*a);
	push_operat(a, b, "pb");
	if (data.lst_size_orig == 5)
		push_operat(a, b, "pb");
	fill_struct(&data, *a, *b);
	swap_three_cond(a, data);
	while (!(is_sorted(*a) == 1 && ft_lstsize(*a) == data.lst_size_orig))
	{
		fill_struct(&data, *a, *b);
		swap_five_cond(a, b, &data);
		if (is_sorted(*a) == 1 && ft_lstsize(*a) == data.lst_size_orig)
			break ;
	}
}

void	swap_three(t_list **stack_a, t_list **stack_b)
{
	t_data	data;

	data.lst_size_orig = ft_lstsize(*stack_a);
	fill_struct(&data, *stack_a, *stack_b);
	if (data.max_a->pos == data.lst_size_a - 1 && data.min_a->pos == 1)
		printf("sa\n");
	if (data.max_a->pos == 0 && data.min_a->pos == data.lst_size_a - 1)
		printf("ra\nsa\n");
	if (data.max_a->pos == 0 && data.min_a->pos == 1)
		printf("ra\n");
	if (data.min_a->pos == 0 && data.max_a->pos == 1)
		printf("rra\nsa\n");
	if (data.min_a->pos == data.lst_size_a - 1 && data.max_a->pos == 1)
		printf("rra\n");
}
