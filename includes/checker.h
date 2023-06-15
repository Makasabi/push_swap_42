/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:13:51 by mrony             #+#    #+#             */
/*   Updated: 2023/02/23 23:18:00 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/includes/libft.h"
# include <limits.h>

/////// DATA STRUCTURE ///////

typedef struct s_stack
{
	int				numb;
	long			l_numb;
	struct s_stack	*next;
}				t_stack;

typedef struct s_info
{
	int		size;
	int		a_size;
	int		b_size;
}			t_info;

/////// FUNCTIONS ///////

// SETTING // 

/* checks.c*/
int		arg_checking(int ac, char **av);
int		is_sorted(t_stack **stack);
int		stack_checking(t_stack **stack);

/* stack_building.c */
t_stack	*build_stack(int nu_args, char **numbs, t_info *data);
t_stack	*ft_newnode(long numb);
t_stack	*ft_lastnode(t_stack *stack);
void	ft_nodeadd_front(t_stack **stack, t_stack *newnode);
void	ft_nodeadd_back(t_stack **stack, t_stack *newnode);

// OPERATIONS //

/* execute_ops.c */
void	ft_id_ops(t_list **ops, t_stack **a, t_stack **b, t_info **data);

/* op_swap.c | op_push.c | op_rotate.c | op_r_rotate.c */
void	sa(t_stack **a_stack, t_stack **b_stack, t_info **data);
void	sb(t_stack **a_stack, t_stack **b_stack, t_info **data);
void	ss(t_stack **a_stack, t_stack **b_stack, t_info **data);
void	pa(t_stack **a_stack, t_stack **b_stack, t_info **data);
void	pb(t_stack **a_stack, t_stack **b_stack, t_info **data);
void	ra(t_stack **a_stack, t_stack **b_stack, t_info **data);
void	rb(t_stack **a_stack, t_stack **b_stack, t_info **data);
void	rr(t_stack **a_stack, t_stack **b_stack, t_info **data);
void	rra(t_stack **a_stack, t_stack **b_stack, t_info **data);
void	rrb(t_stack **a_stack, t_stack **b_stack, t_info **data);
void	rrr(t_stack **a_stack, t_stack **b_stack, t_info **data);

// FREE //
/* free_stack.c */
void	ft_free_stacks(t_stack **a_stack, t_stack **b_stack);
void	ft_stackdelone(t_stack *stack);
void	ft_stackclear(t_stack **stack);

#endif