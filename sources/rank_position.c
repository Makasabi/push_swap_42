/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rank_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 15:41:09 by mrony             #+#    #+#             */
/*   Updated: 2023/02/15 12:05:43 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_pos(t_stack *stack)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		stack->pos = pos;
		stack = stack->next;
		pos++;
	}
}

static int	rank(int numb, int size, t_stack *stack)
{
	while (stack)
	{
		if (numb <= stack->numb)
			size--;
		stack = stack->next;
	}
	return (size);
}

void	ft_rank(t_stack *stack, t_info *data)
{
	t_stack	*i;

	i = stack;
	while (i)
	{
		i->rank = rank(i->numb, data->a_size, stack);
		i = i->next;
	}
}
