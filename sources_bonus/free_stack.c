/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 13:29:55 by mrony             #+#    #+#             */
/*   Updated: 2023/02/23 15:12:37 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	ft_free_stacks(t_stack **a_stack, t_stack **b_stack)
{
	if (a_stack)
		ft_stackclear(a_stack);
	if (b_stack)
		ft_stackclear(b_stack);
}

void	ft_stackdelone(t_stack *stack)
{
	if (!stack)
		return ;
	else
	{
		free(stack);
	}
}

void	ft_stackclear(t_stack **stack)
{
	t_stack	*tmp;

	if (stack)
	{
		while (*stack)
		{
			tmp = (*stack)->next;
			ft_stackdelone(*stack);
			(*stack) = tmp;
		}
	}
}