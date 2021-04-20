/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:13:39 by rbourgea          #+#    #+#             */
/*   Updated: 2021/04/14 18:40:43 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_best_move_b_2(t_data *data, int i)
{
	if (data->relative == 1)
		data->lock_b = 0;
	else if (data->relative == 2)
		data->lock_b = 1;
	else if (data->relative == 3)
		data->lock_a = 1;
	else if (data->relative == 4)
		data->lock_a = 0;
	data->bool_first_move = 0;
	while (i < data->rotation)
	{
		if (data->direction > 0)
			rbw(data);
		else
			rrbw(data);
		i++;
	}
	data->last_relative = data->relative;
	paw(data);
}

void	execute_best_move_b(t_data *data, int min, int max)
{
	int	i;

	i = 0;
	if (!data->bool_first_move)
	{
		if (data->list[data->spliter - 1] < data->val &&
			data->list[data->spliter - 1] >= min &&
			data->list[data->spliter - 1] < max)
			raw_optimize(data, &i);
		if (data->list[data->spliter - 1] < data->val &&
			data->list[data->spliter - 1] >= min &&
			data->list[data->spliter - 1] < max)
			raw_optimize(data, &i);
		if (data->list[data->spliter - 1] < data->val &&
			data->list[data->spliter - 1] >= min &&
			data->list[data->spliter - 1] < max)
			raw_optimize(data, &i);
		if (data->list[0] > data->val && data->list[0] >= min
			&& data->list[0] < max)
			rraw_optimize(data, &i);
		if (data->list[0] > data->val && data->list[0] >= min
			&& data->list[0] < max)
			rraw_optimize(data, &i);
	}
	execute_best_move_b_2(data, i);
}
