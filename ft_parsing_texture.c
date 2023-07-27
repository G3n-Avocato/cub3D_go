/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_texture.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:02:23 by lamasson          #+#    #+#             */
/*   Updated: 2023/07/27 16:20:46 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	check_id(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == '\n')
		return (-2);
	while (line[i])
	{
		if (line[i] == 'N' && line[i + 1] == 'O')
			return (1);
		if (line[i] == 'S' && line[i + 1] == 'O')
			return (2);
		if (line[i] == 'W' && line[i + 1] == 'E')
			return (3);
		if (line[i] == 'E' && line[i + 1] == 'A')
			return (4);
		if (line[i] == 'F')
			return (5);
		if (line[i] == 'C')
			return (6);
		i++;
	}
	return (-1);
}

static char	*rec_path_text(char *line)
{
	int	i;
	int	start;
	char	*path;

	i = 0;
	while (line[i] != '.' && line[i + 1] != '/')
		i++;
	start = i;
	while (line[i] != '\0')
	{
		if (line[i] == ' ' || line[i] == '\t' || line[i] == '\n')
			break ;
		i++;
	}
	path = ft_substr(line, start, i - start);
	if (!path)
		return (NULL);
	return (path);
}

static int	parsing_texture(char *line, t_data_fd *data, int id)
{
	char	*path;

	path = rec_path_text(line);
	if (!path)
	{
		//parsing erreur
		return (1);
	}
	if (id == 1)
		data->path_no = path;
	else if (id == 2)
		data->path_so = path;
	else if (id == 3)
		data->path_we = path;
	else if (id == 4)
		data->path_ea = path;
	return (0);
}

int	ft_parse_line(char *line, t_data_fd *data)
{
	int	i;
	int	b;
	int	id;	

	i = 0;
	b = 0;
	id = check_id(line);
	if (id >= 1 && id <= 4)
		b = parsing_texture(line, data, id);
	else if (id == 5 || id == 6)
		b = parsing_colors(line, data, id);
	else if (id == -2)
		return (0);
	else
	{
//		parse_error();
		return (1);
	}
	if (b == 1)
		return (1);
	return (0);
}
