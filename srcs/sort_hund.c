/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hund.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <threiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:55:12 by threiss           #+#    #+#             */
/*   Updated: 2021/10/15 19:30:36 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void rotate_hold(t_list **a, t_list **b, t_data *data)
{
	while (--data->hold_first->pos + 1)
	{
		if (data->lst_size_b > 1 && data->min_b->pos == 0)
		{
			rotate_operat(a, "xrx");
			rotate_operat(b, "xrr");
		}
		else
			rotate_operat(a, "ra");
		fill_struct(data, *a, *b);
	}
}

void re_rotate_hold(t_list **a, t_list **b, t_data *data, int rra)
{
	while (rra--)
	{
		if (data->lst_size_b > 1 && data->max_b->pos == data->lst_size_b - 1)
		{
			rrotate_operat(a, "xrx");
			rrotate_operat(b, "xrr");
		}
		else
			rrotate_operat(a, "rra");
		fill_struct(data, *a, *b);
	}
}

/*
**	 push-b chunk by chunk
*/
void push_chunks(t_list **a, t_list **b, t_data *data)
{
	int rra;

	while (data->chunk_actu < data->lst_size_orig)
	{
		while (data->lst_size_b < data->chunk_actu)
		{
			rra = data->lst_size_a - data->hold_sec->pos;
			if (data->hold_first->pos < rra)
				rotate_hold(a, b, data);
			else
				re_rotate_hold(a, b, data, rra);
			push_operat(a, b, "pb");
			fill_struct(data, *a, *b);
		}
		data->chunk_actu += data->chunks;
	}
}

/*
**	last chunk stays in stack_a -> order stack_a before going on
*/
void swap_more_cond(t_list **a, t_list **b, t_data *data)
{
	while (ft_lstsize(*b) > 0)
	{
		while (ft_lstsize(*b) > 0 && (*b)->val == data->max_b->val)
		{
			push_operat(b, a, "pa");
			data->max_b = get_max_lst(*b);
		}
		if (ft_lstsize(*b) > 1 && data->max_b->pos <= ft_lstsize(*b) / 2)
		{
			while ((*b)->val != data->max_b->val)
			{
				rotate_operat(b, "rb");
				data->max_b = get_max_lst(*b);
			}
		}
		else if (ft_lstsize(*b) > 1)
		{
			while ((*b)->val != data->max_b->val)
			{
				rrotate_operat(b, "rrb");
				data->max_b = get_max_lst(*b);
			}
		}
	}
}

void sort_a(t_list **a, t_list **b, t_data *data)
{
	while (is_sorted(*a) != 1)
	{
		if (is_sorted_but_mixed(*a, data) == 1)
			rotate_operat(a, "ra");
		if ((*a)->val == data->min_a->val)
			push_operat(a, b, "pb");
		else if ((*a)->val > (*a)->next->val)
			swap_operat(a, "sa");
		else
			rotate_operat(a, "ra");
		fill_struct(data, *a, *b);
	}
}

void swap_more(t_list **stack_a, t_list **stack_b)
{
	t_data data;
	double mult;

	mult = 0.0;
	data.lst_size_orig = ft_lstsize(*stack_a);
	data.lst_size_a = ft_lstsize(*stack_a);
	if (data.lst_size_a < 80)
		mult = 0.06;
	if (data.lst_size_a < 250)
		mult = 0.059;
	if (data.lst_size_a >= 250)
		mult = 0.0218;
	data.chunks = data.lst_size_a / (data.lst_size_a * mult);
	data.chunk_actu = data.lst_size_a / (data.lst_size_a * mult);
	fill_struct(&data, *stack_a, *stack_b);
	push_chunks(stack_a, stack_b, &data);
	sort_a(stack_a, stack_b, &data);
	swap_more_cond(stack_a, stack_b, &data);
}