/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:29:25 by lamasson          #+#    #+#             */
/*   Updated: 2023/07/31 22:17:30 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	ft_tab_tab(t_data_fd *data)
{
	while (data->input->i < 8)
	{
		data->tab[data->input->j][data->input->i] = ' ';
		data->input->i++;
	}
	return (1);
}

static int	ft_input_pos_player(t_data_fd *data, char *line, int i)
{
	if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' || line[i] == 'E')
	{	
		if (data->input->pos_j != 'A')
			return (1);
		data->input->pos_j = line[i];
		data->input->pos_s[0] = i;
		data->input->pos_s[1] = data->input->j;
		data->tab[data->input->j][data->input->i] = line[i];
	}
	return (0);
}

static int	ft_fill_tab_map(t_data_fd *data, char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == ' ' || line[i] == '\n')
			data->tab[data->input->j][data->input->i] = ' ';
		else if (line[i] == '\t')
		{
			i = i + ft_tab_tab(data);
			continue ;
		}
		else if (ft_input_pos_player(data, line, i) == 1)
				return (1);
		else
			data->tab[data->input->j][data->input->i] = line[i];
		data->input->i++;
		i++;
	}
	data->tab[data->input->j][data->input->i] = '\0';
	return (0);
}

int	ft_parsing_map(t_data_fd *data, char *line)
{
	if (ft_find_map(line) == 1)
		return (0); //si 1 normalement \n avant la map in file 
	if (ft_fill_tab_map(data, line) == 1)
	{
		printf("Error\nToo many positions for the player on the map\n");
		return (1);
	}
	data->input->j++;
	data->input->i = 0;
	return (0);
}
