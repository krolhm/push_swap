/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:00:09 by rbourgea          #+#    #+#             */
/*   Updated: 2021/04/14 18:31:35 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_data *data)
{
	int i;
	int temp;

	i = 0;
	if (data->spliter < 2)
		return ;
	temp = data->list[0];
	while (i < data->spliter - 1)
	{
		data->list[i] = data->list[i + 1];
		i++;
	}
	data->list[i] = temp;
}

void	rrb(t_data *data)
{
	int i;
	int temp;

	i = data->size - 1;
	if (data->size - data->spliter < 2)
		return ;
	temp = data->list[i];
	while (i > data->spliter)
	{
		data->list[i] = data->list[i - 1];
		i--;
	}
	data->list[i] = temp;
}

void	rrr(t_data *data)
{
	data->aaa = 1;
	rra(data);
	rrb(data);
	data->aaa = 0;
}
