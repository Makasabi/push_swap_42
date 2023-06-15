/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 17:52:09 by mrony             #+#    #+#             */
/*   Updated: 2023/02/20 13:57:30 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	ft_init_data(t_info *data)
{
	data->a_size = 0;
	data->b_size = 0;
	data->size = 0;
	data->chunk = 0;
	data->max = 0;
	data->moves = 0;
}

static void	ft_resolution(t_stack *a_stack, t_info *data)
{
	t_stack	*b_stack;

	b_stack = NULL;
	if (data->size == 2)
		ft_sort_2(&a_stack, &b_stack, &data);
	else if (data->size == 3)
		ft_sort_3(&a_stack, &b_stack, &data);
	else if (data->size > 3 && data->size <= 5)
		ft_sort_5(&a_stack, &b_stack, &data);
	else if (data->size > 5)
		ft_sort_max(&a_stack, &b_stack, &data);
	ft_free_stacks(&a_stack, &b_stack);
	return ;
}

int	main(int ac, char **av)
{
	t_stack	*a_stack;
	t_info	data;

	if (ac <= 2)
		return (0);
	if (arg_checking(ac, av) == 1)
		return (write(2, "Error\n", 6), 1);
	ft_init_data(&data);
	a_stack = build_stack(ac, av, &data);
	if (!a_stack)
		return (ft_stackclear(&a_stack), 1);
	if (stack_checking(&a_stack) == 1)
		return (ft_stackclear(&a_stack), write(2, "Error\n", 6), 1);
	if (stack_checking(&a_stack) == 2)
		return (ft_stackclear(&a_stack), 0);
	ft_rank(a_stack, &data);
	ft_resolution(a_stack, &data);
	return (0);
}
