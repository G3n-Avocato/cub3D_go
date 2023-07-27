/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_color.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:43:51 by lamasson          #+#    #+#             */
/*   Updated: 2023/07/27 19:13:20 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int check_data_rec_rgb(int **col, int j)
{
	int	i;

	i = 0;
	if (j != 3)
		return (1);
	while (i < 3)
	{
		if ((*col)[i] >= 0 && (*col)[i] <= 255)
			i++;
		else
			return (1);
	}
	return (0);
}

static int	ft_init_struct_rgb(int **col, char *line, int start, int i)
{
	int		j;
	char	*tmp;

	j = 0;
	while (line[i] && j < 3)
	{
		if (line[i] == ',' || (line[i] == '\n' && j == 2) \
			|| (line[i] == ' ' && j == 2) || (line[i] == '\t' && j == 2))
		{
			tmp = ft_substr(line, start, i - start);
			if (!tmp)
				exit (1);
			if (tmp[0] == '\0')
			{
				free(tmp);
				return (-1);
			}
			(*col)[j] = ft_atoi(tmp);
			free(tmp);
			j++;
			start = i + 1;
		}
		i++;
	}
	return (j);
}

static int	rec_rgb(char *line, int **col)
{
	int		i;
	int		j;
	int		start;

	i = 0;
	j = 0;
	while (!ft_isdigit(line[i]))
		i++;
	start = i;
	j = ft_init_struct_rgb(col, line, start, i);
	if (j == -1)
		return (1);
	if (check_data_rec_rgb(col, j) == 1)
		return (1);
	return (0);
}

static int	check_data_rgb_error(char *line)
{
	int	i;
	int	nb_v;
	int	cmp;

	i = 1;
	nb_v = 0;
	cmp = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	while (line[i])
	{
		if (line[i] == ',')
			nb_v++;
		if (line[i] == '\n')
			break ;
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else if ((line[i] != ',' && !ft_isdigit(line[i])) || nb_v > 2)
			return (1);
		else
			i++;
	}
//check fin de la ligne tkt
	return (0);
}

int	parsing_colors(char *line, t_data_fd *data, int id)
{
	int	b;
	
	b = check_data_rgb_error(line);
	if (id == 5 && b == 0)
		b = rec_rgb(line, &data->f);
	else if (id == 6 && b == 0)
		b = rec_rgb(line, &data->c);
	if (b > 0)
	{
		if (id == 5)
			printf("Error\nWrong data for element F\n");
		else if (id == 6)
			printf("Error\nWrong data for element C\n");
		return (1);
	}
	return (0);
}
