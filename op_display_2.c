/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_display_2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:03:57 by rbourgea          #+#    #+#             */
/*   Updated: 2021/04/14 18:04:06 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	raw(t_data *data)
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
	if (data->rrr == 0)
		ft_putstr("ra\n");
}

void	rbw(t_data *data)
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
	if (data->rrr == 0)
		ft_putstr("rb\n");
}

void	rrw(t_data *data)
{
	data->rrr = 1;
	raw(data);
	rbw(data);
	data->rrr = 0;
	ft_putstr("rr\n");
}