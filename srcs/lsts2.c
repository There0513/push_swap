/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsts2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <threiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:15:16 by threiss           #+#    #+#             */
/*   Updated: 2021/10/25 18:59:21 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

void	print_simple_list(t_list *lst)
{
	t_list	*cpy_a;

	cpy_a = lst;
	while (cpy_a)
	{
		printf("%6d\ti = %d\n", cpy_a->val, cpy_a->index);
		cpy_a = cpy_a->next;
	}
	printf("\n");
}

void	print_list(t_list *lst, t_list *lst2)
{
	t_list	*cpy_a;
	t_list	*cpy_b;

	cpy_a = lst;
	cpy_b = lst2;
	printf("*******a:\n");
	while (cpy_a)
	{
		printf("%6d\ti = %d |\n", cpy_a->val, cpy_a->index);
		cpy_a = cpy_a->next;
	}
	printf("\t\t*******b:\n");
	while (cpy_b)
	{
		printf("\t\t|%6d\ti = %d\n", cpy_b->val, cpy_b->index);
		cpy_b = cpy_b->next;
	}
	printf("___________________\n");
}
