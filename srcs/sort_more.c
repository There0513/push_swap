/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_more.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <threiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 16:27:49 by threiss           #+#    #+#             */
/*   Updated: 2021/10/14 17:01:27 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	sort_a(t_list **a, t_list **b, t_data *data)
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
