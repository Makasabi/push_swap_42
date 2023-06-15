/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_ops.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 15:34:11 by mrony             #+#    #+#             */
/*   Updated: 2023/02/23 14:21:58 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	ft_call_s_ops(char *op, t_stack **a, t_stack **b, t_info **data)
{
	if (op[1] == 'a')
		sa(a, b, data);
	else if (op[1] == 'b')
		sb(a, b, data);
	else if (op[1] == 's')
		ss(a, b, data);
}

static void	ft_call_p_ops(char *op, t_stack **a, t_stack **b, t_info **data)
{
	if (op[1] == 'a')
		pa(a, b, data);
	else if (op[1] == 'b')
		pb(a, b, data);
}

static void	ft_call_r_ops(char *op, t_stack **a, t_stack **b, t_info **data)
{
	if (op[1] == 'a')
		ra(a, b, data);
	else if (op[1] == 'b')
		rb(a, b, data);
}

static void	ft_call_rr_ops(char *op, t_stack **a, t_stack **b, t_info **data)
{
	if (op[2] == 'a')
		rra(a, b, data);
	else if (op[2] == 'b')
		rrb(a, b, data);
	else if (op[2] == 'r')
		rrr(a, b, data);
	else if (op[2] == '\n')
		rr(a, b, data);
}

void	ft_id_ops(t_list **ops, t_stack **a, t_stack **b, t_info **data)
{
	t_list *cpy;

	cpy = (*ops);
	while (cpy)
	{
		if (((char *)cpy->content)[0] == 's')
			ft_call_s_ops((char *)cpy->content, a, b, data);
		else if (((char *)cpy->content)[0] == 'p')
			ft_call_p_ops((char *)cpy->content, a, b, data);
		else if (((char *)cpy->content)[0] == 'r')
		{
			if (((char *)cpy->content)[1] == 'r')
				ft_call_rr_ops(((char *)cpy->content), a, b, data);
			if (((char *)cpy->content)[1] == 'a' || ((char *)cpy->content)[1] == 'b')
				ft_call_r_ops(((char *)cpy->content), a, b, data);
		}
		cpy = cpy->next;
	}
	
}