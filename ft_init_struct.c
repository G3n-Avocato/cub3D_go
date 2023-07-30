/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_struct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:02:42 by lamasson          #+#    #+#             */
/*   Updated: 2023/07/30 11:17:47 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	ft_free_struct(t_data_fd *data)
{
	if (data->path_no)
		free(data->path_no);
	if (data->path_so)
		free(data->path_so);
	if (data->path_we)
		free(data->path_we);
	if (data->path_ea)
		free(data->path_ea);
	if (data->f)
		free(data->f);
	if (data->c)
		free(data->c);
}

void	ft_init_struct(t_data_fd *data)
{
	data->path_no = NULL;
	data->path_so = NULL;
	data->path_we = NULL;
	data->path_ea = NULL;
	data->f = malloc(sizeof(int) * 3);
	data->c = malloc(sizeof(int) * 3);
	data->f[0] = -1;
	data->c[0] = -1;

	data->input[0]->c_point = malloc(sizeof(char) * 1);
	data->input[0]->c_point = 'A';
	data->input[0]->pos_s[0] = -5;
}
