/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:43:38 by mrony             #+#    #+#             */
/*   Updated: 2023/02/20 17:18:05 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_mem_a_pos(t_stack **a, t_stack **ij)
{
	t_stack	*cpy;

	cpy = (*a);
	if (ft_is_biggest(a, (*ij)->rank) == 0)
		return (ft_pos_smallest(a));
	else if (ft_is_smallest(a, (*ij)->rank) == 0)
		return (ft_pos_smallest(a));
	while (cpy->next != NULL)
	{
		if (cpy->rank < (*ij)->rank && cpy->next->rank > (*ij)->rank)
			return (cpy->next->pos);
		cpy = cpy->next;
	}
	return (0);
}

static int	ft_count_ifs(int mem_a_pos, int mem_b_pos)
{
	if (mem_a_pos > mem_b_pos)
		return (mem_a_pos);
	else if (mem_a_pos < mem_b_pos)
		return (mem_b_pos);
	else
		return (mem_a_pos);
}

static int	ft_count(t_stack **a, t_stack **ij, t_info **data)
{
	int	mem_a_pos;
	int	mem_b_pos;

	mem_a_pos = ft_mem_a_pos(a, ij);
	mem_b_pos = (*ij)->pos;
	if ((mem_a_pos < (*data)->a_size / 2) && (mem_b_pos < (*data)->b_size / 2))
	{
		return (ft_count_ifs(mem_a_pos, mem_b_pos));
	}
	else if ((mem_a_pos <= (*data)->a_size / 2)
		&& (mem_b_pos <= (*data)->b_size / 2))
	{
		mem_a_pos = (*data)->a_size - mem_a_pos;
		mem_b_pos = (*data)->b_size - mem_b_pos;
		return (ft_count_ifs(mem_a_pos, mem_b_pos));
	}
	else
	{
		if (mem_a_pos > (*data)->a_size / 2)
			mem_a_pos = (*data)->a_size - mem_a_pos;
		if (mem_b_pos > (*data)->b_size / 2)
			mem_b_pos = (*data)->b_size - mem_b_pos;
		return (mem_a_pos + mem_b_pos);
	}
}

t_stack	*ft_comp(t_stack **a, t_stack **b, t_info **data)
{
	t_stack	*i;
	t_stack	*j;

	i = (*b);
	j = (*b)->next;
	while (j)
	{
		while (i != j && j->next != NULL)
		{
			if (ft_count(a, &i, data) <= ft_count(a, &j, data))
			{
				j = j->next;
				continue ;
			}
			else
				i = j;
		}
		if (!(ft_count(a, &i, data) <= ft_count(a, &j, data)))
			i = j;
		j = j->next;
	}
	return (i);
}

void	ft_sort_max(t_stack **a_stack, t_stack **b_stack, t_info **data)
{
	t_stack	*best;

	ft_lis(a_stack, data);
	ft_chunks(data);
	ft_chunk_sort(a_stack, b_stack, data);
	while (*b_stack)
	{
		ft_pos(*a_stack);
		ft_pos(*b_stack);
		best = ft_comp(a_stack, b_stack, data);
		ft_move_bs(best, a_stack, b_stack, data);
	}
	ft_pos(*a_stack);
	best = (*a_stack);
	while (best->rank != 0)
		best = best->next;
	while ((*a_stack)->pos != best->pos)
	{
		if (best->pos <= (*data)->a_size / 2)
			ra(a_stack, b_stack, data);
		else
			rra(a_stack, b_stack, data);
	}
}
