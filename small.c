/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:57:37 by rbourgea          #+#    #+#             */
/*   Updated: 2021/04/14 17:57:43 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_min_three_b_to_a(t_data *data)
{
	if (data->list[data->spliter] > data->list[data->spliter + 1] &&
	data->list[data->spliter] > data->list[data->spliter + 2])
		paw(data);
	else if (data->list[data->spliter + 1] > data->list[data->spliter] &&
	data->list[data->spliter + 1] > data->list[data->spliter + 2])
	{
		rbw(data);
		paw(data);
	}
	else if (data->list[data->spliter + 2] > data->list[data->spliter] &&
	data->list[data->spliter + 2] > data->list[data->spliter + 1])
	{
		rrbw(data);
		paw(data);
	}
}

void	push_min_thwo_b_to_a(t_data *data)
{
	if (data->list[data->spliter] > data->list[data->spliter + 1])
		paw(data);
	else
	{
		rbw(data);
		paw(data);
	}
}

void	sort_two_top_a(t_data *data)
{
	if (data->list[data->spliter - 1] > data->list[data->spliter - 2])
		saw(data);
}

void	sort_only_three(t_data *data)
{
	if (data->list[data->spliter - 1] < data->list[data->spliter - 3] &&
	data->list[data->spliter - 3] < data->list[data->spliter - 2])
	{
		raw(data);
		saw(data);
		rraw(data);
	}
	else if (data->list[data->spliter - 2] < data->list[data->spliter - 1] &&
	data->list[data->spliter - 1] < data->list[data->spliter - 3])
		saw(data);
	else if (data->list[data->spliter - 3] < data->list[data->spliter - 1] &&
	data->list[data->spliter - 1] < data->list[data->spliter - 2])
		rraw(data);
	else if (data->list[data->spliter - 2] < data->list[data->spliter - 3] &&
	data->list[data->spliter - 3] < data->list[data->spliter - 1])
		raw(data);
	else if (data->list[data->spliter - 3] < data->list[data->spliter - 2] &&
	data->list[data->spliter - 2] < data->list[data->spliter - 1])
	{
		saw(data);
		rraw(data);
	}
}

void	sort_four_five(t_data *data)
{
	int i;
	int pivot;

	i = 0;
	pivot = median(data, 0, data->size);
	while (i < data->size)
	{
		if (data->list[data->spliter - 1] <= pivot)
			pbw(data);
		else
			raw(data);
		i++;
	}
	if (data->size == 5)
	{
		if (data->list[0] < data->list[1])
			raw(data);
	}
	push_min_three_b_to_a(data);
	push_min_thwo_b_to_a(data);
	paw(data);
}
