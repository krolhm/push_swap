/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:07:40 by rbourgea          #+#    #+#             */
/*   Updated: 2021/04/12 20:07:45 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_error(void)
{
	ft_putstr_fd("Error\n", 0);
	return (0);
}

void	push_remainer_a_to_b(t_data *data, int pivot)
{
	while (data->list[data->spliter - 1] < pivot)
		raw(data);
	while (data->list[data->spliter - 1] >= pivot)
		pbw(data);
}

void	rotate_remainer(t_data *data, int pivot)
{
	while (data->list[data->spliter - 1] >= pivot)
		raw(data);
}

void	raw_optimize(t_data *data, int *i)
{
	if (*i < data->rotation && data->direction > 0)
	{
		rrw(data);
		(*i)++;
	}
	else
		raw(data);
}

void	rraw_optimize(t_data *data, int *i)
{
	if (*i < data->rotation && data->direction < 0)
	{
		rrrw(data);
		(*i)++;
	}
	else
		rraw(data);
}
