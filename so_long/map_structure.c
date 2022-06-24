/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_structure.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/14 13:26:44 by fchanane          #+#    #+#             */
/*   Updated: 2022/06/20 22:40:00 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	file_valid(int fd)
{
	if (fd < 0)
		exit(1);
}

char	*create_the_line(char *line, char *the_maze)
{
	int	j;

	j = 0;
	while (line[j] && line[j] != '\n')
	{
		the_maze[j] = line[j];
		j++;
	}
	the_maze[j] = '\0';
	return (the_maze);
}

char	**create_the_maze(char *file, int lines)
{
	int		i;
	t_creat	creat;

	creat.fd = open(file, O_RDONLY);
	file_valid(creat.fd);
	creat.line = get_next_line(creat.fd);
	creat.columns = ft_strlen(creat.line) - 1;
	creat.the_maze = malloc(sizeof(char *) * (lines + 1));
	i = 0;
	while (i < lines)
	{
		creat.the_maze[i] = malloc(creat.columns + 1);
		create_the_line(creat.line, creat.the_maze[i]);
		creat.line = get_next_line(creat.fd);
		i++;
	}
	creat.the_maze[i] = NULL;
	close(creat.fd);
	return (creat.the_maze);
}
