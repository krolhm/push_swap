/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_display_3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:04:35 by rbourgea          #+#    #+#             */
/*   Updated: 2021/04/14 18:04:41 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rraw(t_data *data)
{
	int	i;
	int	temp;

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
	if (data->rrr == 0)
		ft_putstr("rra\n");
}

void	rrbw(t_data *data)
{
	int	i;
	int	temp;

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
	if (data->rrr == 0)
		ft_putstr("rrb\n");
}

void	rrrw(t_data *data)
{
	data->rrr = 1;
	rraw(data);
	rrbw(data);
	data->rrr = 0;
	ft_putstr("rrr\n");
}
