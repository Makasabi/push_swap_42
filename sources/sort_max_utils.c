/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 17:23:22 by mrony             #+#    #+#             */
/*   Updated: 2023/02/20 14:30:57 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_op_loop(t_stack **a, t_stack **b, t_info **data, void (*f)())
{
	while ((*data)->moves > 0)
	{
		f(a, b, data);
		(*data)->moves--;
	}
}

int	ft_is_smallest(t_stack **a, int rank)
{
	t_stack	*cpy;

	cpy = (*a);
	while (cpy)
	{
		if (rank > cpy->rank)
			return (1);
		if (cpy->next == NULL)
			break ;
		cpy = cpy->next;
	}
	return (0);
}

int	ft_pos_smallest(t_stack **a)
{
	t_stack	*i;
	t_stack	*j;

	i = (*a);
	j = (*a)->next;
	while (j)
	{
		while (i != j)
		{
			if (j->rank < i->rank)
				return (j->pos);
			else
				i = j;
		}
		if (j->next == NULL)
			break ;
		j = j->next;
	}
	return ((*a)->pos);
}

int	ft_is_biggest(t_stack **a, int rank)
{
	t_stack	*cpy;

	cpy = (*a);
	while (cpy)
	{
		if (rank < cpy->rank)
			return (1);
		if (cpy->next == NULL)
			break ;
		cpy = cpy->next;
	}
	return (0);
}

int	ft_all_tagged(t_stack **a)
{
	t_stack	*cpy;

	cpy = (*a);
	while (cpy)
	{
		if (cpy->tag != 1)
			return (1);
		if (cpy->next == NULL)
			break ;
		cpy = cpy->next;
	}
	return (0);
}
