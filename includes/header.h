/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: threiss <threiss@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/20 16:20:45 by threiss           #+#    #+#             */
/*   Updated: 2021/10/25 18:48:05 by threiss          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

# include "../libft/libft.h"
# include <unistd.h>
# include <stdio.h>

typedef struct all_in_one
{
	t_list	*a;
	t_list	*cpy_a;
	t_list	*b;
	char	**split;
	int	free_ac;
}	t_all;

typedef	struct	s_data
{
	t_list	*max_a;
	t_list	*max_b;
	t_list	*min_a;
	t_list	*min_b;
	int	lst_size_a;
	int	lst_size_b;
	int	lst_size_orig;
	int	chunks;
	int	chunk_actu;
	t_list	*hold_first;
	t_list	*hold_sec;
	int	pivot;
}				t_data;

int	is_int(char *str);
int		ret_error_msg(char *msg, int ret);
int		error_handling(int ac, char **av);
int		check_doubles(int nb, int i, char **av);
void	create_lst(t_list **lst, char **split);
void	fill_struct(t_data *data, t_list *stack_a, t_list *stack_b);
t_list *get_max_lst(t_list *lst);
void	print_struct(t_data data);
void	add_index_a(t_list **stack_a, t_list **cpy_a);
void	pre_sort_a(t_list **cpy_a, int i);
void	lst_add_back(t_list **lst, int nb);
void	ft_lstadd_front(t_list **alst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int	ft_lstsize(t_list *lst);
t_list	*create_elem(int nb);
void	print_list(t_list *lst, t_list *lst2);
void	print_simple_list(t_list *lst);
void	push_swap(t_list **stack_a, t_list **stack_b);
int	is_sorted(t_list *stack_a);
int	is_sorted_but_mixed(t_list *lst, t_data *data);
int	b_is_sorted(t_list *stack_a);
void	swap_three(t_list **stack_a, t_list **stack_b);
void	swap_five(t_list **stack_a, t_list **stack_b);
void	swap_more(t_list **stack_a, t_list **stack_b);
void	swap_five_cond(t_list **a, t_list **b, t_data *data);
void	swap_operat(t_list **stack, char *op);
void	push_operat(t_list **from, t_list **to, char *op);
void	rotate_operat(t_list **lst, char *op);
void	rrotate_operat(t_list **lst, char *op);
void	cpy_lst(t_list **a, t_list **cpy_a);
int	get_next_line(int fd, char **line);
void	stdin_checker(t_list **a, t_list **b);
int	check_instructions(char *input, t_list **a, t_list **b);
void	init_all(t_all *all);
int	check_nd_prepare(int ac, char **av, t_all *all);
void	time_to_free(t_all *all, char **av);

#endif
