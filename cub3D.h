/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:54:26 by lamasson          #+#    #+#             */
/*   Updated: 2023/07/30 00:46:59 by lamasson         ###   ########.fr       */
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
	char			**tab;
	struct s_map	**input;
	char			*path_no;
	char			*path_so;
	char			*path_we;
	char			*path_ea;
	int				*f;
	int				*c;
}t_data_fd;

typedef	struct s_map
{
	int		x;
	int		y;
	int		pos_s[2];
	char	c_point;
}t_map;

//	ft_parse.c	//
char	*parsing_intro(char **argv, int argc);
int		ft_parse_line(char *line, t_data_fd *data);

//	ft_parsing_color.c	//
int		parsing_colors(char *line, t_data_fd *data, int id);

//	ft_parsing_color_error.c	//
int	check_digit_error(char *line);
int	check_data_rgb_error(char *line);

//	ft_parsing_texture.c	//
int	rec_pos_element(char *line);

//	ft_parsing_texture_error.c	//
int	printf_error(int id, char *str);
int	check_end_line_texture(char *line, int i);
int	check_path_texture(char *path, int id);
int	check_nb_element(t_data_fd *data, int id);
int	check_if_all_init(t_data_fd *data);

//	ft_init_struct.c	//
void	ft_free_struct(t_data_fd *data);
void	ft_init_struct(t_data_fd *data);

#endif
