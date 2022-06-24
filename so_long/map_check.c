/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:29:19 by fchanane          #+#    #+#             */
/*   Updated: 2022/06/24 02:14:02 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

int	endline_in(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	check_map(char *file)
{
	t_error	err;
	int		fd;

	fd = open(file, O_RDONLY);
	error_fd(fd);
	err.read = get_next_line(fd);
	error_empty(err.read, fd);
	err.size = ft_strlen(err.read);
	if (endline_in(err.read))
		err.size--;
	err.lines = 0;
	while (err.read)
	{
		err.line = ft_strdup(err.read);
		err.lines++;
		err.size_line = ft_strlen(err.line);
		if (endline_in(err.line))
			err.size_line--;
		error_equal(fd, err.size, err.size_line);
		free(err.line);
		err.read = get_next_line(fd);
	}
	close(fd);
	error_enough(err.size, err.lines);
	return (err.lines);
}
