/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_map_error.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 00:36:04 by lamasson          #+#    #+#             */
/*   Updated: 2023/07/31 01:30:11 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int check_map_char_line(char *line)
{
	int	i;

	i = 0;
	if (line[i] == )
	while (line[i])
	{
		if (line[i] == '0' || line[i] == '1')
			i++;
		else if (line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
			i++;
		else if (line[i] == '\n' || line[i] == ' ' || line[i] == '\t')
			i++;
		else
			return (1);
	}
	return (1);
}
