/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/14 18:14:02 by rbourgea          #+#    #+#             */
/*   Updated: 2021/04/19 18:04:27 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void bn_or_number_of_instructions(t_data *data)
{
    if (data->show_number)
        printf("\t[%d Instructions]\n", data->instuctions);
    else
        printf("\n");
}

void ok_or_ko(t_data *data)
{
    int i;

    i = 0;
    if (data->size != data->spliter)
    {
        write(1, "KO", 2);
        bn_or_number_of_instructions(data);
        return;
    }
    while (i < data->size - 1)
    {
        if (data->list[i] > data->list[i + 1])
            i++;
        else
        {
            write(1, "KO", 2);
            bn_or_number_of_instructions(data);
            return;
        }
    }
    if (data->color)
        printf("\033[0;32m");
    write(1, "OK", 2);
    bn_or_number_of_instructions(data);
}

int main_3(char **av, int i, char ***tab, t_data *data)
{
    char c;

    while (read(0, &c, 1) > 0)
    {
        data->buff[i] = c;
        i++;
        if (c == '\n')
        {
            i = 0;
            data->instuctions++;
            execute_instruction_checker(data);
        }
        if (data->error)
            return (ft_free_print_error(data, data->ac, av, tab));
    }
    ok_or_ko(data);
    free(data->list);
    if (data->ac == 2)
        ft_free(*tab, ft_nbr_str(av[1], ' '));
    return (0);
}

int main_2(char **av, int i, char ***tab, t_data *data)
{
    if (!(data->list = malloc(sizeof(int) * data->size)))
        return (free_tab_print_error(data->ac, av, tab));
    while (i > 0)
    {
        if (data->ac == 2)
        {
            data->list[data->spliter - i] = ft_atoi((*tab)[i - 1], data);
            security_duplicates(data, data->spliter - i);
        }
        else
        {
            data->list[data->ac - i - 1] = ft_atoi(av[i], data);
            security_duplicates(data, data->ac - i - 1);
        }
        if (data->error == 1)
            return (ft_free_print_error(data, data->ac, av, tab));
        i--;
    }
    i = 0;
    data->instuctions = 0;
    return (main_3(av, i, tab, data));
}

int main(int ac, char **av)
{
    int i;
    t_data data;
    char **tab;

    if (ac == 1)
        return (0);
    initialize_main(&data, ac);
    manage_bonus(&data, &ac, &av);
    i = ac - 1;
    if (ac > 10000)
        return (ft_error());
    if (ac == 2)
    {
        i = ft_nbr_str(av[1], ' ');
        if (i > 10000)
            return (ft_error());
        tab = ft_split(av[1], ' ');
        data.spliter = i;
        data.size = i;
    }
    return (main_2(av, i, &tab, &data));
}