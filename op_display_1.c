/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_display_1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:03:25 by rbourgea          #+#    #+#             */
/*   Updated: 2021/04/14 18:03:25 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void saw(t_data *data)
{
    int temp;

    if (data->spliter < 2)
        return;
    temp = data->list[data->spliter - 1];
    data->list[data->spliter - 1] = data->list[data->spliter - 2];
    data->list[data->spliter - 2] = temp;
    if (data->rrr == 0)
        ft_putstr("sa\n");
}

void sbw(t_data *data)
{
    int temp;

    if (data->spliter - data->size < 2)
        return;
    temp = data->list[data->spliter];
    data->list[data->spliter] = data->list[data->spliter + 1];
    data->list[data->spliter + 1] = temp;
    if (data->rrr == 0)
        ft_putstr("sb\n");
}

void ssw(t_data *data)
{
    data->rrr = 1;
    saw(data);
    sbw(data);
    data->rrr = 0;
    ft_putstr("ss\n");
}

void paw(t_data *data)
{
    if (data->spliter < data->size)
        data->spliter++;
    ft_putstr("pa\n");
}

void pbw(t_data *data)
{
    if (data->spliter > 0)
        data->spliter--;
    ft_putstr("pb\n");
}