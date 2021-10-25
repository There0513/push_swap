/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <threiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:13:49 by threiss           #+#    #+#             */
/*   Updated: 2021/10/25 22:53:48 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

void	choose_swap(t_list **stack_a, t_list **stack_b)
{
	if (ft_lstsize(*stack_a) == 2)
		printf("sa\n");
	else if (ft_lstsize(*stack_a) <= 3)
		swap_three(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) <= 5)
		swap_five(stack_a, stack_b);
	else if (ft_lstsize(*stack_a) <= 5000)
		swap_more(stack_a, stack_b);
}

int	main(int ac, char **av)
{
	t_all	all;

	init_all(&all);
	if (check_nd_prepare(ac, av, &all) != 1)
		return (0);
	create_lst(&all.a, all.split);
	create_lst(&all.cpy_a, all.split);
	add_index_a(&all.a, &all.cpy_a);
	if (is_sorted(all.a) == 1)
		return (0);
	choose_swap(&all.a, &all.b);
	time_to_free(&all, av);
	return (0);
}
