/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_r_rotate_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:36:53 by mrony             #+#    #+#             */
/*   Updated: 2023/02/24 13:33:11 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	rra(t_stack **a_stack, t_stack **b_stack, t_info **data)
{
	t_stack	*last;

	(void)(*data);
	(void)(*b_stack);
	if ((*a_stack) == NULL || (*a_stack)->next == NULL)
		return ;
	last = (*a_stack);
	while (last->next->next != NULL)
		last = last->next;
	last->next->next = (*a_stack);
	(*a_stack) = last->next;
	last->next = NULL;
}

void	rrb(t_stack **a_stack, t_stack **b_stack, t_info **data)
{
	t_stack	*last;

	(void)(*data);
	(void)(*a_stack);
	if ((*b_stack) == NULL || (*b_stack)->next == NULL)
		return ;
	last = (*b_stack);
	while (last->next->next != NULL)
		last = last->next;
	last->next->next = (*b_stack);
	(*b_stack) = last->next;
	last->next = NULL;
}

void	rrr(t_stack **a_stack, t_stack **b_stack, t_info **data)
{
	t_stack	*last;

	if ((*data)->a_size < 2 || (*data)->b_size < 2)
		return ;
	if (((*a_stack) == NULL || (*a_stack)->next == NULL)
		&& ((*b_stack) == NULL || (*b_stack)->next == NULL))
		return ;
	last = (*a_stack);
	while (last->next->next != NULL)
		last = last->next;
	last->next->next = (*a_stack);
	(*a_stack) = last->next;
	last->next = NULL;
	last = (*b_stack);
	while (last->next->next != NULL)
		last = last->next;
	last->next->next = (*b_stack);
	(*b_stack) = last->next;
	last->next = NULL;
}
