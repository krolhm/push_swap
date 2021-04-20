/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbourgea <rbourgea@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/12 20:02:51 by rbourgea          #+#    #+#             */
/*   Updated: 2021/04/14 19:56:53 by rbourgea         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	quick_sort_ultimate(t_data *data)
{
	int pivot;
	int pivot_min;
	int pivot_max;

	pivot = median(data, 0, data->size);
	pivot_min = data->pivot_min;
	pivot_max = data->pivot_max;
	push_half_b(data, pivot);
	manage_half_on_b(data, pivot_min, pivot - 1);
	while (data->list[data->spliter - 1] < pivot)
		raw(data);
	while (data->list[data->spliter - 1] >= pivot)
		pbw(data);
	manage_half_on_b(data, pivot, pivot_max);
	rotate_remainer(data, pivot);
}

void	quick_sort(t_data *data)
{
	int pivot;

	pivot = median(data, 0, data->size);
	push_half_b(data, pivot);
	insersion_sort_b(data, data->pivot_min, pivot);
	push_remainer_a_to_b(data, pivot);
	insersion_sort_b(data, pivot, data->pivot_max);
	rotate_remainer(data, pivot);
}

void	sort(t_data *data)
{
	if (already_sorted(data))
		return ;
	if (data->size == 1)
		return ;
	else if (data->size == 2)
		sort_two_top_a(data);
	else if (data->size == 3)
		sort_only_three(data);
	else if (data->size < 6)
		sort_four_five(data);
	else if (data->size < 300)
		quick_sort(data);
	else
		quick_sort_ultimate(data);
}

int		main_2(char **av, char ***tab, t_data *data, int i)
{
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
	sort(data);
	free(data->list);
	if (data->ac == 2)
		ft_free(*tab, ft_nbr_str(av[1], ' '));
	return (0);
}

int		main(int ac, char **av)
{
	int		i;
	t_data	data;
	char	**tab;

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
	if (!(data.list = malloc(sizeof(int) * data.size)))
		return (free_tab_print_error(ac, av, &tab));
	return (main_2(av, &tab, &data, i));
}
