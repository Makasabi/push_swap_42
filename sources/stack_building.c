/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_building.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 11:07:22 by mrony             #+#    #+#             */
/*   Updated: 2023/02/15 12:12:25 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_nodeadd_front(t_stack **stack, t_stack *newnode)
{
	if (stack && newnode)
	{
		newnode->next = *stack;
		*stack = newnode;
	}
}

void	ft_nodeadd_back(t_stack **stack, t_stack *newnode)
{
	t_stack	*tmp;

	if (stack && newnode)
	{
		if (*stack == NULL)
			*stack = newnode;
		else
		{
			tmp = ft_lastnode(*stack);
			tmp->next = newnode;
		}
	}
}

t_stack	*ft_lastnode(t_stack *stack)
{
	while (stack && stack->next)
	{
		stack = stack->next;
	}
	return (stack);
}

t_stack	*ft_newnode(long numb, int pos)
{
	t_stack	*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->l_numb = numb;
	node->pos = pos;
	node->tag = 0;
	node->ptr = NULL;
	node->next = NULL;
	return (node);
}

t_stack	*build_stack(int nu_args, char **numbs, t_info *data)
{
	int		i;
	int		pos;
	t_stack	*stack;
	t_stack	*new_node;

	i = 1;
	pos = 0;
	stack = ft_newnode(ft_atoi(numbs[i]), pos);
	if (!stack)
		return (NULL);
	data->size = nu_args - 1;
	data->a_size = nu_args - 1;
	i++;
	pos++;
	while (i < nu_args)
	{
		new_node = ft_newnode(ft_atoi(numbs[i]), pos);
		if (!new_node)
			return (NULL);
		ft_nodeadd_back(&stack, new_node);
		i++;
		pos++;
	}
	return (stack);
}
