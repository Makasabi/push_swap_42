/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_chunks.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 17:39:07 by mrony             #+#    #+#             */
/*   Updated: 2023/02/23 23:17:31 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_chunks(t_info **data)
{
	(*data)->chunk = 3;
	(*data)->chunk += ((*data)->size - (*data)->max) / 100;
	(*data)->chunk -= ((*data)->size < 50);
}

static void	ft_cs_cont(int i, t_stack **a, t_stack **b, t_info **data)
{
	int	chk_sz;

	chk_sz = (*data)->size / (*data)->chunk;
	if (((*a)->tag == 1) || (!((*a)->rank < ((*data)->chunk - i + 1) * chk_sz)
			&& ((*a)->rank >= ((*data)->chunk - i) * chk_sz))
		|| (!((*a)->rank >= i * chk_sz) && ((*a)->rank < (i + 1) * chk_sz)))
		rr(a, b, data);
	else
		rb(a, b, data);
}

static void	ft_chunk_even(t_stack **a, t_stack **b, t_info **data)
{
	int	i;
	int	chk_sz;
	int	size;

	i = ((*data)->chunk / 2) + 1;
	chk_sz = (*data)->size / (*data)->chunk;
	while (i-- >= 0)
	{
		size = (*data)->a_size + 1;
		while (size-- && ft_all_tagged(a))
		{
			if (((*a)->rank < ((*data)->chunk - i + 1) * chk_sz)
				&& ((*a)->rank >= ((*data)->chunk - i) * chk_sz) && !(*a)->tag)
				pb(a, b, data);
			else if (((*a)->rank >= i * chk_sz)
				&& ((*a)->rank < (i + 1) * chk_sz) && !(*a)->tag)
			{
				pb(a, b, data);
				ft_cs_cont(i, a, b, data);
			}
			else
				ra(a, b, data);
		}
	}
}

static void	ft_chunk_odd(t_stack **a, t_stack **b, t_info **data)
{
	int	i;
	int	chk_sz;
	int	size;

	i = ((*data)->chunk / 2) + 1;
	chk_sz = (*data)->size / (*data)->chunk;
	while (i-- >= 0)
	{
		size = (*data)->a_size + 1;
		while (size-- && ft_all_tagged(a))
		{
			if (((*a)->rank < ((*data)->chunk - i + 1) * chk_sz)
				&& ((*a)->rank >= ((*data)->chunk - i) * chk_sz) && !(*a)->tag)
			{
				pb(a, b, data);
				ft_cs_cont(i, a, b, data);
			}
			else if (((*a)->rank >= i * chk_sz)
				&& ((*a)->rank < (i + 1) * chk_sz) && !(*a)->tag)
				pb(a, b, data);
			else
				ra(a, b, data);
		}
	}
}

void	ft_chunk_sort(t_stack **a, t_stack **b, t_info **data)
{
	if ((*data)->chunk % 2 == 0)
		ft_chunk_even(a, b, data);
	if ((*data)->chunk % 2 == 1)
		ft_chunk_odd(a, b, data);
}
