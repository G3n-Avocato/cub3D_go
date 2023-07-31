/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:36:04 by lamasson          #+#    #+#             */
/*   Updated: 2023/07/31 23:29:26 by lamasson         ###   ########.fr       */
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

int	check_wall_one()


int	second_read_map(t_data_fd *data)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	if (check_pos_player(data) == 1)
		return (1);
	while (data->tab[j])
	{
		while (data->tab[i])
		{



			i++;
		}
		j++;
	}

}
