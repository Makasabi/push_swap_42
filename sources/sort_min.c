/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_min.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:15:00 by mrony             #+#    #+#             */
/*   Updated: 2023/02/24 11:52:07 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_sort_2(t_stack **stack, t_stack **other, t_info **data)
{
	t_stack	*a;

	a = (*stack);
	if (a->numb > a->next->numb)
	{
		sa(stack, other, data);
		return ;
	}
	else
		return ;
}

static void	a_smaller_next(t_stack *a, t_stack **a_stack,
t_stack **b_stack, t_info **data)
{
	if (a->next->numb < a->next->next->numb)
		return ;
	else if (a->next->numb > a->next->next->numb)
	{
		if (a->next->next->numb > a->numb)
		{
			sa(a_stack, b_stack, data);
			ra(a_stack, b_stack, data);
			return ;
		}
		else if (a->next->next->numb < a->numb)
		{
			rra(a_stack, b_stack, data);
			return ;
		}
	}
}

static void	a_bigger_next(t_stack *a, t_stack **a_stack,
t_stack **b_stack, t_info **data)
{
	if (a->next->numb > a->next->next->numb)
	{
		ra(a_stack, b_stack, data);
		sa(a_stack, b_stack, data);
		return ;
	}
	else if (a->next->numb < a->next->next->numb)
	{
		if (a->next->next->numb > a->numb)
		{
			sa(a_stack, b_stack, data);
			return ;
		}
		else if (a->next->next->numb < a->numb)
		{
			ra(a_stack, b_stack, data);
			return ;
		}
	}
}

void	ft_sort_3(t_stack **stack, t_stack **other, t_info **data)
{
	t_stack	*a;

	a = (*stack);
	if (a->numb < a->next->numb)
	{
		a_smaller_next(a, stack, other, data);
		return ;
	}
	else if (a->numb > a->next->numb)
	{
		a_bigger_next(a, stack, other, data);
		return ;
	}
}

void	ft_sort_5(t_stack **a_stack, t_stack **b_stack, t_info **data)
{
	t_stack	*a;
	t_stack	*b;

	a = (*a_stack);
	while ((*data)->a_size > 3)
	{
		if (a->rank < 1 && (*data)->size == 4)
			pb(a_stack, b_stack, data);
		else if (a->rank < 2 && (*data)->size == 5)
			pb(a_stack, b_stack, data);
		else
			ra(a_stack, b_stack, data);
		a = (*a_stack);
	}
	ft_sort_3(a_stack, b_stack, data);
	b = (*b_stack);
	if ((*data)->b_size == 2 && b->numb < b->next->numb)
		sb(a_stack, b_stack, data);
	while ((*data)->a_size < (*data)->size)
	{
		pa(a_stack, b_stack, data);
	}
}
