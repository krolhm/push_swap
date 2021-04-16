/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   others_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:06:29 by rbourgea          #+#    #+#             */
/*   Updated: 2021/04/14 18:40:37 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int ft_free_print_error(t_data *data, int ac, char **av, char ***tab)
{
    free(data->list);
    if (ac == 2)
        ft_free(*tab, ft_nbr_str(av[1], ' '));
    ft_putstr_fd("Error\n", 0);
    return (0);
}

void security_duplicates(t_data *data, int nbr)
{
    int val;

    val = data->list[nbr];
    nbr--;
    while (nbr >= 0)
    {
        if (data->list[nbr] == val)
            data->error = 1;
        nbr--;
    }
}

int already_sorted(t_data *data)
{
    int i;

    i = 1;
    while (i < data->size)
    {
        if (data->list[i - 1] < data->list[i])
            return (0);
        i++;
    }
    return (1);
}

int free_tab_print_error(int ac, char **av, char ***tab)
{
    if (ac == 2)
        ft_free(*tab, ft_nbr_str(av[1], ' '));
    ft_putstr_fd("Error\n", 0);
    return (0);
}