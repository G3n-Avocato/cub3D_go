/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:25:53 by lamasson          #+#    #+#             */
/*   Updated: 2023/07/30 00:46:33 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "libft/libft.h"

int	ft_find_map(char *line, t_data_fd *data)
{
	int	i;
	int	b;

	b = 0;
	i = 0;
	while (line[i] && line[i] != '\n')
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else if (ft_isdigit(line[i]))
		{
			b = 1;
			i++;
		}
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'W' \
			|| line[i] == 'E')
		{
			data->input[0]->c_point = line[i];
			i++;
		}
		else
			return (1);
	}
	if (line[i] == '\n' && b == 0)
		return (1);
	return (0);
}

int	rec_data_map(char *line, int fd, t_data_fd *data)
{
	int	tmp;

	data->input[0]->y = 1;
	data->input[0]->x = ft_strlen(line);
	while (line && ft_find_map(line, data) == 0)
	{
		if (data->input[0]->c_point != 'A' && data->input[0]->pos_s[0] == -5)
		{
			data->input[0]->pos_s[0] = data->input[0]->x;
			data->input[0]->pos_s[1] = data->input[0]->y;
		}
		line = get_next_line(fd);
		tmp = ft_strlen(line);
		if (tmp > data->input[0]->x)
			data->input[0]->x = tmp;
		free(line);
		data->input[0]->y++;
	}
	if (line)
	{
		while (line)
		{
			free(line);
			line = get_next_line(fd);
		}
		return (1);
	}
	return (0);
}
///le bordel ............... 
int	first_read_map(char *path, t_data_fd *data)
{
	int		fd;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		if (ft_find_map(line, data) == 0)
			break ;
		free(line);
		line = get_next_line(fd);
	}
	rec_data_map(line, fd, data);
}
