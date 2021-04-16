/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_1.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:01:49 by rbourgea          #+#    #+#             */
/*   Updated: 2021/04/14 18:31:06 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_data *data)
{
	int temp;

	if (data->spliter < 2)
		return ;
	temp = data->list[data->spliter - 1];
	data->list[data->spliter - 1] = data->list[data->spliter - 2];
	data->list[data->spliter - 2] = temp;
}

void	sb(t_data *data)
{
	int temp;

	if (data->spliter - data->size < 2)
		return ;
	temp = data->list[data->spliter];
	data->list[data->spliter] = data->list[data->spliter + 1];
	data->list[data->spliter + 1] = temp;
}

void	ss(t_data *data)
{
	data->aaa = 1;
	sa(data);
	sb(data);
	data->aaa = 0;
}

void	pa(t_data *data)
{
	if (data->spliter < data->size)
		data->spliter++;
}

void	pb(t_data *data)
{
	if (data->spliter > 0)
		data->spliter--;
}