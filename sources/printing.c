/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 17:14:43 by mrony             #+#    #+#             */
/*   Updated: 2023/02/20 17:15:28 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	print_stack(t_stack **a_stack, t_stack **b_stack)
{
	t_stack	*a;
	t_stack	*b;

	a = (*a_stack);
	b = (*b_stack);
	while (a || b)
	{
		if (b == NULL && a)
		{
			ft_printf("%d\t%d\t%d\t|\n", a->numb, a->pos, a->rank);
			a = a->next;
		}
		if (a == NULL && b)
		{
			ft_printf("\t\t\t|%d\t%d\t%d\t\t\n", b->numb, b->pos, b->rank);
			b = b->next;
		}
		if (a != NULL && b != NULL)
		{
			ft_printf("%d\t%d\t%d\t|%d\t%d\t%d\t\t\n",
				a->numb, a->pos, a->rank, b->numb, b->pos, b->rank);
			a = a->next;
			b = b->next;
		}
	}
}

void	print_header(t_stack **a_stack, t_stack **b_stack, t_info **data)
{
	t_stack	*a;
	t_stack	*b;

	a = (*a_stack);
	b = (*b_stack);
	if (b == NULL)
	{
		ft_printf("\nStack A\t\t\tsize %d\t|Stack B\n", (*data)->a_size);
		ft_printf("Nu\tPos\tRank\tTag\t|Nu\tPos\tRank\t\n");
		return ;
	}
	if (a == NULL)
	{
		ft_printf("\nStack A\t\t\t\t|Stack B\tsize %d\n", (*data)->b_size);
		ft_printf("Nu\tPos\tRank\t|Nu\tPos\tRank\t\n");
		return ;
	}
	ft_printf("\nStack A\t\t\tsize %d\t|Stack B\t\tsize %d\n",
		(*data)->a_size, (*data)->b_size);
	ft_printf("Nu\tPos\tRank\t|Nu\tPos\tRank\t\n");
	return ;
}
