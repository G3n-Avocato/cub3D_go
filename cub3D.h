/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:54:26 by lamasson          #+#    #+#             */
/*   Updated: 2023/07/27 14:17:08 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>

typedef struct	s_data_fd
{
	char	**tab;
	char	*path_no;
	char	*path_so;
	char	*path_we;
	char	*path_ea;
	int		*f;
	int		*c;
}t_data_fd;

char	*parsing_intro(char **argv, int argc);
int		ft_parse_line(char *line, t_data_fd *data);
int		parsing_colors(char *line, t_data_fd *data, int id);

void	ft_free_struct(t_data_fd *data);

#endif
