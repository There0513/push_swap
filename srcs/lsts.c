/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <threiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/27 13:13:07 by threiss           #+#    #+#             */
/*   Updated: 2021/10/24 22:28:12 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

 void	ft_lstadd_front(t_list **alst, t_list *new)
{
	new->next = *alst;
	*alst = new;
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst)
		while (lst->next)
			lst = lst->next;
	return (lst);
}

t_list	*create_elem(int nb)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (0);
	new->val = nb;
	new->next = 0;
	return (new);
}

void	lst_add_back(t_list **lst, int nb)
{
	t_list	*lst_tmp;

	if (*lst == 0)
	{
		*lst = create_elem(nb);
		return ;
	}
	lst_tmp = *lst;
	while (lst_tmp->next)
		lst_tmp = lst_tmp->next;
	lst_tmp->next = create_elem(nb);
}

void	create_lst(t_list **lst, char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		lst_add_back(lst, ft_atoll(split[i]));
}
