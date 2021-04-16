/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:14:58 by rbourgea          #+#    #+#             */
/*   Updated: 2021/04/14 18:37:40 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <time.h>

void	printf_color(char *s, t_data *data)
{
	(void)data;
	if (!s)
		return ;
	if (data->color && data->coloration == 31)
		printf("\033[0;31m");
	else if (data->color && data->coloration == 32)
		printf("\033[0;32m");
	else if (data->color && data->coloration == 34)
		printf("\033[0;34m");
	else if (data->color && data->coloration == 35)
		printf("\033[0;35m");
	else if (data->color && data->coloration == 36)
		printf("\033[0;36m");
	printf("%s", s);
	if (data->color)
		printf("\033[0m");
}

void	manage_bonus(t_data *data, int *ac, char ***av)
{
	if (*ac < 2)
		return ;
	if ((*av)[1][0] == '-' && (*av)[1][1] == 'n' && (*av)[1][2] == '\0')
	{
		(*ac)--;
		(*av)++;
		data->spliter--;
		data->size--;
		data->ac--;
		data->show_number = 1;
		manage_bonus(data, ac, av);
	}
	if (*ac < 2)
		return ;
	if ((*av)[1][0] == '-' && (*av)[1][1] == 'c' && (*av)[1][2] == '\0')
	{
		(*ac)--;
		(*av)++;
		data->spliter--;
		data->size--;
		data->ac--;
		data->color = 1;
		manage_bonus(data, ac, av);
	}
}