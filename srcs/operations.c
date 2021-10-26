/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <threiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 13:39:00 by threiss           #+#    #+#             */
/*   Updated: 2021/10/25 19:30:53 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*	sa : swap the first 2 elements at the top of stack a.
 **	sb : swap the first 2 elements at the top of stack b.
 **	ss : -> sa + sb
 */
void	swap_operat(t_list **lst, char *op)
{
	t_list	*first;
	t_list	*sec;
	t_list	*third;

	if ((*lst) && (*lst)->next)
	{
		first = *lst;
		sec = (*lst)->next;
		third = (*lst)->next->next;
		*lst = (*lst)->next;
		sec->next = first;
		(*lst)->next->next = third;
	}
	if (op[0] != 'x')
		printf("%s\n", op);
}

/*	pa : take the first element at the top of b and put it at the top of a.
 **	pb : take the first element at the top of a and put it at the top of b.
 */
void	push_operat(t_list **from, t_list **to, char *op)
{
	t_list	*tmp;

	if (*from)
	{
		tmp = *from;
		*from = (*from)->next;
		ft_lstadd_front(to, tmp);
	}
	printf("%s\n", op);
}

/*	ra : shift up all elements. first becomes last
 **	rb : shift up all elements. first becomes last
 **	rr : ra and rb at the same time. -> ra + rb
 */
void	rotate_operat(t_list **lst, char *op)
{
	t_list	*beginn;
	t_list	*last;

	if (*lst)
	{
		beginn = *lst;
		*lst = (*lst)->next;
		last = ft_lstlast(*lst);
		last->next = beginn;
		beginn->next = 0;
	}
	if (op[0] != 'x')
		printf("%s\n", op);
	else if (op[1] == 'r' && op[2] == 'r')
		printf("rr\n");
}

/*	rra : shift down all elements. last becomes first
 **	rrb : shift down all elements. last becomes first
 **	rrr : rra + rrb
 */
void	rrotate_operat(t_list **lst, char *op)
{
	t_list	*last;
	t_list	*tmp;

	if (*lst)
	{
		tmp = *lst;
		last = ft_lstlast(*lst);
		ft_lstadd_front(lst, last);
		while (tmp)
		{
			if (tmp->next->val == last->val)
				tmp->next = 0;
			tmp = tmp->next;
		}
		if (op[0] != 'x')
			printf("%s\n", op);
		else if (op[1] == 'r' && op[2] == 'r')
			printf("rrr\n");
	}
}
