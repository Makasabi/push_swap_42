/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:36:57 by mrony             #+#    #+#             */
/*   Updated: 2023/02/20 13:52:11 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_stack **a_stack, t_stack **b_stack, t_info **data)
{
	t_stack	*tmp;

	(void)data;
	if ((*a_stack) == NULL || (*a_stack)->next == NULL)
		return ;
	(void)a_stack;
	tmp = (*a_stack);
	(*a_stack) = (*a_stack)->next;
	tmp->next = (*a_stack)->next;
	(*a_stack)->next = tmp;
	if ((*b_stack) == NULL)
	{
		(*a_stack)->pos = 0;
		(*a_stack)->next->pos = 1;
	}
	ft_printf("sa\n");
}

void	sb(t_stack **a_stack, t_stack **b_stack, t_info **data)
{
	t_stack	*tmp;

	(void)data;
	if ((*b_stack) == NULL || (*b_stack)->next == NULL)
		return ;
	(void)a_stack;
	tmp = (*b_stack);
	(*b_stack) = (*b_stack)->next;
	tmp->next = (*b_stack)->next;
	(*b_stack)->next = tmp;
	ft_printf("sb\n");
}

void	ss(t_stack **a_stack, t_stack **b_stack, t_info **data)
{
	t_stack	*a_tmp;
	t_stack	*b_tmp;

	(void)data;
	if (((*a_stack) == NULL || (*a_stack)->next == NULL)
		&& ((*b_stack) == NULL || (*b_stack)->next == NULL))
		return ;
	a_tmp = (*a_stack);
	(*a_stack) = (*a_stack)->next;
	a_tmp->next = (*a_stack)->next;
	(*a_stack)->next = a_tmp;
	b_tmp = (*b_stack);
	(*b_stack) = (*b_stack)->next;
	b_tmp->next = (*b_stack)->next;
	(*b_stack)->next = b_tmp;
	if ((*b_stack) == NULL)
	{
		(*a_stack)->pos = 0;
		(*a_stack)->next->pos = 1;
	}
	ft_printf("ss\n");
}
