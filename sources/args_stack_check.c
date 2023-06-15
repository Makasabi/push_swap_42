/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_stack_check.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/31 16:36:44 by mrony             #+#    #+#             */
/*   Updated: 2023/02/24 12:43:14 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	is_duplicate(t_stack *stack, long i)
{
	while (stack->next != NULL)
	{
		stack = stack->next;
		if (i == stack->l_numb)
			return (1);
	}
	return (0);
}

static int	is_sorted(t_stack **stack)
{
	t_stack	*a;

	a = (*stack);
	while (a->next != NULL)
	{
		if (a->numb < a->next->numb)
			a = a->next;
		else if (a->numb > a->next->numb)
			return (0);
	}
	return (1);
}

int	stack_checking(t_stack **stack)
{
	t_stack	*a;

	a = (*stack);
	while (a)
	{
		if (is_duplicate(a, a->l_numb) == 1)
			return (1);
		if (a->l_numb > INT_MAX || a->l_numb < INT_MIN)
			return (1);
		a->numb = a->l_numb;
		a = a->next;
	}
	if (is_sorted(stack) == 1)
		return (2);
	return (0);
}

static int	is_charset(char c)
{
	if (c == 43 || c == 45)
		return (0);
	if (c >= 48 && c <= 57)
		return (0);
	return (1);
}

int	arg_checking(int ac, char **av)
{
	int	i;
	int	j;

	(void)ac;
	i = 1;
	j = 0;
	while (av[i])
	{
		while (av[i][j] != '\0')
		{
			if (is_charset(av[i][j]) == 1)
				return (1);
			if ((av[i][j] >= 48 && av[i][j] <= 57)
			&& (av[i][j + 1] == '-' || av[i][j + 1] == '+'))
				return (1);
			if (ft_strlen(av[i]) > 11)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}
