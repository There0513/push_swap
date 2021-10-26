/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <threiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:53:34 by threiss           #+#    #+#             */
/*   Updated: 2021/10/26 14:59:03 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	check_instructions2(char *input, t_list **a, t_list **b)
{
	if (ft_strncmp("rr", input, 3) == 0)
	{
		rotate_operat(a, "xx");
		rotate_operat(b, "xx");
		printf("rr\n");
	}
	else if (ft_strncmp("rra", input, 4) == 0)
		rrotate_operat(a, "rra");
	else if (ft_strncmp("rrb", input, 4) == 0)
		rrotate_operat(b, "rrb");
	else if (ft_strncmp("rrr", input, 4) == 0)
	{
		rrotate_operat(a, "xrx");
		rrotate_operat(b, "rrr");
	}
	else if (input[0] == 0)
		return (-1);
	else
		ret_error_msg("Instruction does not exist. You can try again:", 0);
	print_list(*a, *b);
	return (0);
}

int	check_instructions(char *input, t_list **a, t_list **b)
{
	if (ft_strncmp("sa", input, 3) == 0)
		swap_operat(a, "sa");
	else if (ft_strncmp("sb", input, 3) == 0)
		swap_operat(b, "sb");
	else if (ft_strncmp("ss", input, 3) == 0)
	{
		swap_operat(a, "xx");
		swap_operat(b, "xx");
		printf("ss\n");
	}
	else if (ft_strncmp("pa", input, 3) == 0)
		push_operat(b, a, "pa");
	else if (ft_strncmp("pb", input, 3) == 0)
		push_operat(a, b, "pb");
	else if (ft_strncmp("ra", input, 3) == 0)
		rotate_operat(a, "ra");
	else if (ft_strncmp("rb", input, 3) == 0)
		rotate_operat(b, "rb");
	else
		return (check_instructions2(input, a, b));
	print_list(*a, *b);
	return (0);
}

void	ko_free_b(t_all *all)
{
	printf("KO\n");
	ft_lstclear(&all->b, free);
	free(all->b);
}

int	main(int ac, char **av)
{
	t_all	all;

	init_all(&all);
	if (check_nd_prepare(ac, av, &all) != 1)
	{
		time_to_free(&all);
		return (0);
	}
	create_lst(&all.a, all.split);
	create_lst(&all.cpy_a, all.split);
	add_index_a(&all.a, &all.cpy_a);
	if (is_sorted(all.a) == 1)
	{
		time_to_free(&all);
		return (0);
	}
	stdin_checker(&all.a, &all.b);
	print_list(all.a, all.b);
	if (is_sorted(all.a) == 1 && ft_lstsize(all.b) == 0)
		printf("OK\n");
	else
		ko_free_b(&all);
	time_to_free(&all);
	return (0);
}
