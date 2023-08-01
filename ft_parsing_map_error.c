/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:36:04 by lamasson          #+#    #+#             */
/*   Updated: 2023/08/01 18:02:14 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_pos_player(t_data_fd *data)
{
	if (data->input->pos_j == 'A')
	{
		printf("Error\nNo position for the player on the map\n");
		return (1);
	}
	return (0);
}

static int	find_start_end_horizon(t_data_fd *data)
{
	int start = -1;
	int end = -1;
	int	i = 0;
	int	j = 0;

	while (data->tab[j][i])
	{
		if (data->tab[j][i] == '1') 
		{
			if (start == -1)
				start = i;
			else
				end = i;
			i++;
		}
		else if (data->tab[j][i] == ' ')
			i++;
		else
			return (1);
	}
	printf("start = %d\nend = %d\n", start, end);
	return (0);
}


int	second_read_map(t_data_fd *data)
{
	//int	i = 0;
	//int j = 0;
	if (check_pos_player(data) == 1)
		return (1);
	find_start_end_horizon(data);
/*
	while (data->tab[j])
	{
		while (data->tab[j][i])
		{
			if (data->tab[j][i] == ' ')
				i++;
			if (data->tab[j][i] == '1')


			i++;
		}
		j++;
	}
*/
	return (0);
}
