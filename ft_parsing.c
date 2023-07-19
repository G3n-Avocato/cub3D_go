/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lamasson <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 16:52:55 by lamasson          #+#    #+#             */
/*   Updated: 2023/07/19 19:28:12 by lamasson         ###   ########.fr       */
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

int	recover_file(char *path)



int main(int argc, char **argv)
{
	char *path;

	path = parsing_intro(argv, argc);
	if (!path)
		return (1);
	recover_file(path);

	printf("%s\n", path);
	return (0);
}
