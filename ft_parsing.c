/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:52:55 by lamasson          #+#    #+#             */
/*   Updated: 2023/07/28 23:21:46 by lamasson         ###   ########.fr       */
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
	int		check;
	char	*line;
	
	check = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		return (1);
	line = get_next_line(fd);
	while (line && check != 1)
	{
		check = ft_parse_line(line, data);
		free(line);
		line = get_next_line(fd);
	}
	while (line && check == 1)
	{
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
	//if (check == 1)
	//	return (1);
	return (0);
}

int main(int argc, char **argv)
{
	char *path;
	t_data_fd	data;

	path = parsing_intro(argv, argc);
	if (!path)
		return (1);
	ft_init_struct(&data);
	if (recover_file(path, &data) == 1)
	{
		ft_free_struct(&data);
		return (1);
	}


	printf("%s\n", path);
	printf("no %s\n", data.path_no);
	printf("so %s\n", data.path_so);
	printf("we %s\n", data.path_we);
	printf("ea %s\n", data.path_ea);

/*	int i = 0;
	while (i < 3)
	{
		if (data.f[i])
			printf("f %d - %d\n", i, data.f[i]);
		if (data.c[i])
			printf("c %d - %d\n", i, data.c[i]);
		i++;
	}*/
	ft_free_struct(&data);
	return (0);
}
