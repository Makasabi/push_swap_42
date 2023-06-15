/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:36:24 by mrony             #+#    #+#             */
/*   Updated: 2023/02/24 13:34:09 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_stack **a_stack, t_stack **b_stack, t_info **data)
{
	t_stack	*last;

	(void)(*data);
	(void)(*b_stack);
	if ((*a_stack) == NULL || (*a_stack)->next == NULL)
		return ;
	last = ft_lastnode((*a_stack));
	last->next = (*a_stack);
	(*a_stack) = (*a_stack)->next;
	last = last->next;
	last->next = NULL;
	ft_printf("ra\n");
}

void	rb(t_stack **a_stack, t_stack **b_stack, t_info **data)
{
	t_stack	*last;

	(void)(*data);
	(void)(*a_stack);
	if ((*b_stack) == NULL || (*b_stack)->next == NULL)
		return ;
	last = ft_lastnode((*b_stack));
	last->next = (*b_stack);
	(*b_stack) = (*b_stack)->next;
	last = last->next;
	last->next = NULL;
	ft_printf("rb\n");
}

void	rr(t_stack **a_stack, t_stack **b_stack, t_info **data)
{
	t_stack	*last;

	if ((*data)->a_size < 2 || (*data)->b_size < 2)
		return ;
	if (((*b_stack) == NULL || (*b_stack)->next == NULL)
		&& ((*a_stack) == NULL || (*a_stack)->next == NULL))
		return ;
	last = ft_lastnode((*a_stack));
	last->next = (*a_stack);
	(*a_stack) = (*a_stack)->next;
	last = last->next;
	last->next = NULL;
	last = ft_lastnode((*b_stack));
	last->next = (*b_stack);
	(*b_stack) = (*b_stack)->next;
	last = last->next;
	last->next = NULL;
	ft_printf("rr\n");
}
