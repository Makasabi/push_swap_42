/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:36:50 by mrony             #+#    #+#             */
/*   Updated: 2023/02/17 14:26:25 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_stack **origin, t_stack **dest, int trigger)
{
	t_stack	*tmp;

	if (trigger == 0)
	{
		(*origin)->next = (*dest);
		(*dest) = (*origin);
		(*origin) = NULL;
		return ;
	}
	if (trigger == 1)
	{
		(*dest) = (*origin);
		(*origin) = (*origin)->next;
		(*dest)->next = NULL;
		return ;
	}
	if (trigger == 2)
	{
		tmp = (*origin)->next;
		(*origin)->next = (*dest);
		(*dest) = (*origin);
		(*origin) = tmp;
		return ;
	}
}

void	pb(t_stack **a_stack, t_stack **b_stack, t_info **data)
{
	int	trigger;

	trigger = 2;
	if ((*a_stack) == NULL)
		return ;
	if ((*a_stack)->next == NULL)
		trigger = 0;
	if ((*b_stack) == NULL)
		trigger = 1;
	push(a_stack, b_stack, trigger);
	ft_printf("pb\n");
	(*data)->a_size -= 1;
	(*data)->b_size += 1;
}

void	pa(t_stack **a_stack, t_stack **b_stack, t_info **data)
{
	int	trigger;

	trigger = 2;
	if ((*b_stack) == NULL)
		return ;
	if ((*b_stack)->next == NULL)
		trigger = 0;
	if ((*a_stack) == NULL)
		trigger = 1;
	push(b_stack, a_stack, trigger);
	ft_printf("pa\n");
	(*data)->a_size += 1;
	(*data)->b_size -= 1;
}
