/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 11:43:16 by mrony             #+#    #+#             */
/*   Updated: 2023/02/23 15:13:19 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

static void	ft_init_data(t_info *data)
{
	data->a_size = 0;
	data->b_size = 0;
	data->size = 0;
}

t_list	*ft_build_op_list(t_list *ops)
{
	t_list	*new_node;
	char	*line;
	
	line = get_next_line(0);
	ops = ft_lstnew(line);
	if (!ops)
		return(NULL);
	while (1)
	{
		line = get_next_line(0);
		if (!line)
			break;
		new_node = ft_lstnew(line);
		if (!new_node)
			return (NULL);
		ft_lstadd_back(&ops, new_node);
	}
	return (ops);
}

int	ft_check_ops(t_list **ops)
{
	t_list	*cpy;

	cpy = (*ops);
	while (cpy)
	{
		if (ft_strnstr("pa\npb\nsa\nsb\nss\nra\nrb\nrr\nrra\nrrb\nrrr\n",
        (cpy)->content, 36) == NULL)
			return (1);
		if (ft_strlen((cpy)->content) < 3)
			return (1);
		(cpy) = (cpy)->next;
	}
	return (0);
}

static void ft_resolution(t_stack *a, t_info *data, t_list *ops)
{
	t_stack	*b;

	b = NULL;
	(void)data;
	if (ops != NULL)
		ft_id_ops(&ops, &a, &b, &data);
	else 
		return ;
    if (is_sorted(&a) == 1 && b == NULL)
        ft_printf("OK\n");
    else
        ft_printf("KO\n");
    ft_free_stacks(&a, &b);
}

int	main(int ac, char **av)
{
	t_stack	*a;
	t_info	data;
	t_list	*ops;
	
	if (ac <= 2)
		return (0);
	if (arg_checking(ac, av) == 1)
		return (write(2, "Error\n", 6), 1);
	ft_init_data(&data);
	a = build_stack(ac, av, &data);
	if (!a)
		return (ft_stackclear(&a), 1);
	if (stack_checking(&a) == 1)
		return (ft_stackclear(&a), write(2, "Error\n", 6), 1);
	if (stack_checking(&a) == 2)
		return (ft_stackclear(&a), 0);
	ops = ft_build_op_list(ops);
	if (!ops)
		ft_lstclear(&ops, free);
	if (ft_check_ops(&ops) == 1)
		return (ft_stackclear(&a), ft_lstclear(&ops, free), write(2, "Error\n", 6), 1);
	ft_resolution(a, &data, ops);
	ft_lstclear(&ops, free);
}
