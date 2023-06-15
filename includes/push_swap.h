/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:54:26 by mrony             #+#    #+#             */
/*   Updated: 2023/02/20 15:06:40 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/includes/libft.h"
# include <limits.h>

/////// DATA STRUCTURE ///////

typedef struct s_stack
{
	int				numb;
	int				pos;
	int				rank;
	long			l_numb;
	int				tag;
	struct s_stack	*ptr;
	struct s_stack	*next;
}				t_stack;

typedef struct s_info
{
	int		size;
	int		a_size;
	int		b_size;
	int		chunk;
	int		max;
	int		moves;
}			t_info;

/////// FUNCTIONS ///////

// SETTING // 

/* args_stack_check.c */
int		arg_checking(int ac, char **av);
int		stack_checking(t_stack **stack);

/* stack_building.c */
t_stack	*build_stack(int nu_args, char **numbs, t_info *data);
t_stack	*ft_newnode(long numb, int pos);
t_stack	*ft_lastnode(t_stack *stack);
void	ft_nodeadd_front(t_stack **stack, t_stack *newnode);
void	ft_nodeadd_back(t_stack **stack, t_stack *newnode);

/* rank_position.c*/
void	ft_pos(t_stack *stack);
void	ft_rank(t_stack *stack, t_info *data);

// SORTING //

/* sort_5.c | sort_3.c */
void	ft_sort_2(t_stack **stack, t_stack **other, t_info **data);
void	ft_sort_3(t_stack **stack, t_stack **other, t_info **data);
void	ft_sort_5(t_stack **a_stack, t_stack **b_stack, t_info **data);

/* sort_max.c | sort_max_lis.c | sort_max_chunks.c |
sort_max_count_ops.c | sort_max_utils.c */
void	ft_sort_max(t_stack **a_stack, t_stack **b_stack, t_info **data);
void	ft_lis(t_stack **a_stack, t_info **data);
void	ft_chunks(t_info **data);
void	ft_chunk_sort(t_stack **a, t_stack **b, t_info **data);
int		ft_all_tagged(t_stack **a);
t_stack	*ft_comp(t_stack **a, t_stack **b, t_info **data);
int		ft_is_smallest(t_stack **a, int rank);
int		ft_pos_smallest(t_stack **a);
int		ft_is_biggest(t_stack **a, int rank);
int		ft_mem_a_pos(t_stack **a, t_stack **ij);
void	ft_move_bs(t_stack *origin, t_stack **a, t_stack **b, t_info **data);
void	ft_op_loop(t_stack **a, t_stack **b, t_info **data, void (*f)());

// OPERATIONS //

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

/////// PRINTING ///////
void	print_header(t_stack **a_stack, t_stack **b_stack, t_info **data);
void	print_stack(t_stack **a_stack, t_stack **b_stack);
//int		ft_checker(t_stack **a_stack, t_stack **b_stack);

/////// MACROS ///////
//# define PRINT print_header(&a_stack, &b_stack, &data);
//print_stack(&a_stack, &b_stack);

#endif