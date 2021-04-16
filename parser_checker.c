/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:12:34 by rbourgea          #+#    #+#             */
/*   Updated: 2021/04/14 18:12:38 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void execute_instruction_2(t_data *data)
{
    if (data->buff[1] == 'a' && data->buff[2] == '\n')
        ra(data);
    else if (data->buff[1] == 'b' && data->buff[2] == '\n')
        rb(data);
    else if (data->buff[1] == 'r' && data->buff[2] == '\n')
        rr(data);
    else if (data->buff[1] == 'r' && data->buff[2] == 'a' && data->buff[3] == '\n')
        rra(data);
    else if (data->buff[1] == 'r' && data->buff[2] == 'b' && data->buff[3] == '\n')
        rrb(data);
    else if (data->buff[1] == 'r' && data->buff[2] == 'r' && data->buff[3] == '\n')
        rrr(data);
    else
        data->error = 1;
}

void execute_instruction_checker(t_data *data)
{
    if (data->buff[0] == 's' && data->buff[1] == 'a' && data->buff[2] == '\n')
        sa(data);
    else if (data->buff[0] == 's' && data->buff[1] == 'b' && data->buff[2] == '\n')
        sb(data);
    else if (data->buff[0] == 's' && data->buff[1] == 's' && data->buff[2] == '\n')
        ss(data);
    else if (data->buff[0] == 'p' && data->buff[1] == 'a' && data->buff[2] == '\n')
        pa(data);
    else if (data->buff[0] == 'p' && data->buff[1] == 'b' && data->buff[2] == '\n')
        pb(data);
    else if (data->buff[0] == 'r')
        execute_instruction_2(data);
    else
        data->error = 1;
}