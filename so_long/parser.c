/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 19:09:55 by fchanane          #+#    #+#             */
/*   Updated: 2022/06/18 22:57:13 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	line_is_wall(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
		{
			ft_putstr("Map is Invalid : Should be closed\n");
			exit(1);
		}
		i++;
	}
}

void	line_is_valid(char *line)
{
	int	i;

	i = ft_strlen(line) - 1;
	if (line[0] != '1' || line[i] != '1')
	{
		ft_putstr("Map is Invalid : Should be closed\n");
		exit(1);
	}
	i = 1;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'C'
			&& line[i] != 'E' && line[i] != 'P')
		{
			ft_putstr("Map is Invalid : Invalid Character \'");
			write(1, &line[i], 1);
			ft_putstr("\'\n");
			exit(1);
		}
		i++;
	}
}

int	calculate_character(char *line, char character)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == character)
			count++;
		i++;
	}
	return (count);
}

int	parse_the_map(char **the_maze, int lines)
{
	int	i;
	int	c;
	int	p;
	int	e;

	i = 0;
	c = 0;
	p = 0;
	e = 0;
	while (i < lines)
	{
		if (i == 0 || i == lines - 1)
			line_is_wall(the_maze[i]);
		else
		{
			c = c + calculate_character(the_maze[i], 'C');
			p = p + calculate_character(the_maze[i], 'P');
			e = e + calculate_character(the_maze[i], 'E');
			line_is_valid(the_maze[i]);
		}
		i++;
	}
	msg_parser(p, c, e);
	ft_putstr("MAP IS ACCEPTED\n");
	return (c);
}
