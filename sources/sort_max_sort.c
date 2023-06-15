/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:48:13 by mrony             #+#    #+#             */
/*   Updated: 2023/02/20 14:29:35 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_b_alone(int origin, t_stack **a, t_stack **b, t_info **data)
{
	if (origin >= (*data)->b_size / 2)
	{
		(*data)->moves = (*data)->b_size - origin;
		ft_op_loop(a, b, data, &rrb);
	}
	else
	{
		(*data)->moves = origin;
		ft_op_loop(a, b, data, &rb);
	}
}

void	ft_a_alone(int dest, t_stack **a, t_stack **b, t_info **data)
{
	if (dest >= (*data)->a_size / 2)
	{
		(*data)->moves = (*data)->a_size - dest;
		ft_op_loop(a, b, data, &rra);
	}
	else
	{
		(*data)->moves = dest;
		ft_op_loop(a, b, data, &ra);
	}
}

void	ft_both_up(t_stack *origin, t_stack **a, t_stack **b, t_info **data)
{
	int	dest;

	dest = ft_mem_a_pos(a, &origin);
	if (dest > origin->pos)
	{
		(*data)->moves = origin->pos;
		ft_op_loop(a, b, data, &rr);
		(*data)->moves = dest - origin->pos;
		ft_op_loop(a, b, data, &ra);
	}
	else if (origin->pos > dest)
	{
		(*data)->moves = dest;
		ft_op_loop(a, b, data, &rr);
		(*data)->moves = origin->pos - dest;
		ft_op_loop(a, b, data, &rb);
	}
	else
	{
		(*data)->moves = origin->pos;
		ft_op_loop(a, b, data, &rr);
	}
}

void	ft_both_down(t_stack *origin, t_stack **a, t_stack **b, t_info **data)
{
	int	dest;
	int	orgn;

	dest = (*data)->a_size - ft_mem_a_pos(a, &origin);
	orgn = (*data)->b_size - origin->pos;
	if (dest > orgn)
	{
		(*data)->moves = orgn;
		ft_op_loop(a, b, data, &rrr);
		(*data)->moves = dest - orgn;
		ft_op_loop(a, b, data, &rra);
	}
	else if (orgn > dest)
	{
		(*data)->moves = dest;
		ft_op_loop(a, b, data, &rrr);
		(*data)->moves = orgn - dest;
		ft_op_loop(a, b, data, &rrb);
	}
	else
	{
		(*data)->moves = orgn;
		ft_op_loop(a, b, data, &rrr);
	}
}

void	ft_move_bs(t_stack *origin, t_stack **a, t_stack **b, t_info **data)
{
	int	dest;

	dest = ft_mem_a_pos(a, &origin);
	if (((dest < (*data)->a_size / 2) && (origin->pos < (*data)->b_size / 2))
		&& ((*data)->a_size > 1 && (*data)->b_size > 1))
		ft_both_up(origin, a, b, data);
	else if (((dest >= (*data)->a_size / 2)
			&& (origin->pos >= (*data)->b_size / 2))
		&& ((*data)->a_size > 1 && (*data)->b_size > 1))
		ft_both_down(origin, a, b, data);
	else
	{
		ft_b_alone(origin->pos, a, b, data);
		ft_a_alone(dest, a, b, data);
	}
	pa(a, b, data);
}
