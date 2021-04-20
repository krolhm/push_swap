/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 17:59:32 by rbourgea          #+#    #+#             */
/*   Updated: 2021/04/14 18:31:22 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_data *data)
{
	int i;
	int temp;

	i = data->spliter - 1;
	if (data->spliter < 2)
		return ;
	temp = data->list[i];
	while (i > 0)
	{
		data->list[i] = data->list[i - 1];
		i--;
	}
	data->list[i] = temp;
}

void	rb(t_data *data)
{
	int i;
	int temp;

	i = data->spliter;
	if (data->size - data->spliter < 2)
		return ;
	temp = data->list[i];
	while (i < data->size - 1)
	{
		data->list[i] = data->list[i + 1];
		i++;
	}
	data->list[i] = temp;
}

void	rr(t_data *data)
{
	data->aaa = 1;
	ra(data);
	rb(data);
	data->aaa = 0;
}
