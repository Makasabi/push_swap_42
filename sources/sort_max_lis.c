/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_max_lis.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 17:43:38 by mrony             #+#    #+#             */
/*   Updated: 2023/02/20 14:26:04 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_l_numb_init(t_stack **stack)
{	
	t_stack	*j;

	j = (*stack);
	while (j)
	{
		j->l_numb = 1;
		j = j->next;
	}
}

static int	ft_find_max_lis(t_stack **stack)
{
	t_stack	*j;
	int		max;

	j = (*stack);
	max = j->l_numb;
	while (j->next)
	{
		if (j->l_numb < j->next->l_numb && max < j->next->l_numb)
			max = j->next->l_numb;
		j = j->next;
	}
	return (max);
}

static void	ft_tag_lis(t_stack **a, t_info **data)
{
	t_stack	*i;

	i = (*a)->next;
	while (i->l_numb < (*data)->max)
	{
		i = i->next;
	}
	i->tag = 1;
	while (i->ptr != NULL)
	{
		i = i->ptr;
		i->tag = 1;
	}
}

void	ft_lis(t_stack **a, t_info **data)
{
	t_stack	*j;
	t_stack	*i;

	j = (*a);
	i = (*a)->next;
	ft_l_numb_init(a);
	while (i)
	{
		j = (*a);
		while (j != i)
		{
			if (i->rank > j->rank && i->l_numb <= j->l_numb + 1)
			{
				i->l_numb = j->l_numb + 1;
				i->ptr = j;
			}
			j = j->next;
		}
		i = i->next;
	}
	(*data)->max = ft_find_max_lis(a);
	ft_tag_lis(a, data);
}
