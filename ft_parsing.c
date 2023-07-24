/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:52:55 by lamasson          #+#    #+#             */
/*   Updated: 2023/07/25 00:03:31 by lamasson         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*parsing_intro(char **arg, int argc)
{
	int		fd;
	char	*path;
	
	if (argc > 2)
	{
		printf("Error\nToo many arguments\n");
		return (NULL);
	}
	else if (argc < 2)
	{
		printf("Error\nNo map\n");
		return (NULL);
	}
	path = arg[1];
	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		printf("Error\n%s\n", strerror(errno));
		return (NULL);
	}
	close(fd);
	return (path);
}

int	recover_file(char *path, t_data_fd *data)
{
	int		fd;
	char	*line;
	
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line)
	{
		ft_parse_line(line, &data);
		free(line);
		line = get_next_line(fd);
	}

	


}


int main(int argc, char **argv)
{
	char *path;
	t_data_fd	data;

	path = parsing_intro(argv, argc);
	if (!path)
		return (1);
//	ft_init_struct_data(&data);
	
	recover_file(path, &data);


	printf("%s\n", path);
	return (0);
}
