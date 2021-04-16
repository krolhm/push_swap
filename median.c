/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:06:52 by rbourgea          #+#    #+#             */
/*   Updated: 2021/04/14 18:06:57 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void sort_list(int **dup, int len)
{
    int i;
    int j;
    int temp;

    i = 0;
    while (i < len)
    {
        j = i + 1;
        while (j < len)
        {
            if ((*dup)[i] > (*dup)[j])
            {
                temp = (*dup)[i];
                (*dup)[i] = (*dup)[j];
                (*dup)[j] = temp;
            }
            j++;
        }
        i++;
    }
}

int median(t_data *data, int begin, int end)
{
    int i;
    int *dup;

    i = begin;
    if (!(dup = malloc(sizeof(int) * (end - begin))))
    {
        data->error = 1;
        return (0);
    }
    while (i < end)
    {
        dup[i - begin] = data->list[i];
        i++;
    }
    sort_list(&dup, end - begin);
    i = dup[(end - begin) / 2];
    data->pivot_min = dup[0];
    data->pivot_max = dup[end - begin - 1];
    free(dup);
    return (i);
}