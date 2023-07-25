/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:43:51 by lamasson          #+#    #+#             */
/*   Updated: 2023/07/25 13:43:22 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int rec_rgb(char *line, int	*col)
{
	int		i;
	int		j;
	char	*tmp;
	int		start;

	i = 0;
	j = 0;
	col = malloc(sizeof(int) * 3);
	while (!ft_isdigit(line[i]))
		i++;
	start = i;
	while (line[i] && j < 3)
	{
		if (line[i] == ',')
		{
			tmp = ft_substr(line, start, i - start);
			if (!tmp)
				return (1);
			col[j] = ft_atoi(tmp);
			j++;
			i++;
			start = i;
		}
		else
			i++;
	}
	return (0);
}


int	parsing_colors(char *line, t_data_fd *data, int id)
{
	int	b;
	
	b = 0;
	if (id == 5)
		b = rec_rgb(line, data->f);
	else if (id == 6)
		b = rec_rgb(line, data->c);
	if (b == 1)
		return (1);
	return (0);
}
