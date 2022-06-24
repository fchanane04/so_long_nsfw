/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 22:26:25 by fchanane          #+#    #+#             */
/*   Updated: 2022/06/18 22:35:42 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	set_it_and_exit(char position, char ext, int *rm_clc)
{
	if (*rm_clc == 0 && (position == 'P')
		&& (ext == 'E'))
	{
		ext = 'P';
		exit(0);
	}
}

int	move_right(char **the_maze, int *counter, int *rm_clc)
{
	int	i;
	int	j;

	i = 1;
	while (the_maze[i])
	{
		j = 0;
		while (the_maze[i][j])
		{
			set_it_and_exit(the_maze[i][j], the_maze[i][j + 1], rm_clc);
			if ((the_maze[i][j] == 'P') && ((the_maze[i][j + 1] == '0')
				|| (the_maze[i][j + 1] == 'C')))
			{
				if (the_maze[i][j + 1] == 'C')
					*rm_clc = *rm_clc - 1;
				the_maze[i][j] = '0';
				the_maze[i][j + 1] = 'P';
				*counter = *counter + 1;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	move_left(char **the_maze, int *counter, int *rm_clc)
{
	int	i;
	int	j;

	i = 1;
	while (the_maze[i])
	{
		j = 0;
		while (the_maze[i][j])
		{
			set_it_and_exit(the_maze[i][j + 1], the_maze[i][j], rm_clc);
			if (((the_maze[i][j] == '0') || (the_maze[i][j] == 'C'))
				&& (the_maze[i][j + 1] == 'P'))
			{
				if (the_maze[i][j] == 'C')
					*rm_clc = *rm_clc - 1;
				the_maze[i][j] = 'P';
				the_maze[i][j + 1] = '0';
				*counter = *counter + 1;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	move_up(char **the_maze, int *counter, int *rm_clc, int lines)
{
	int	i;
	int	j;

	i = lines - 2;
	while (the_maze[i] && i > 1)
	{
		j = 0;
		while (the_maze[i][j])
		{
			set_it_and_exit(the_maze[i][j], the_maze[i - 1][j], rm_clc);
			if (((the_maze[i - 1][j] == '0') || (the_maze[i - 1][j] == 'C'))
				&& (the_maze[i][j] == 'P'))
			{
				if (the_maze[i - 1][j] == 'C')
					*rm_clc = *rm_clc - 1;
				the_maze[i - 1][j] = 'P';
				the_maze[i][j] = '0';
				*counter = *counter + 1;
				return (1);
			}
			j++;
		}
		i--;
	}
	return (0);
}

int	move_down(char **the_maze, int *counter, int *rm_clc)
{
	int	i;
	int	j;

	i = 1;
	while (the_maze[i])
	{
		j = 0;
		while (the_maze[i][j])
		{
			set_it_and_exit(the_maze[i - 1][j], the_maze[i][j], rm_clc);
			if (((the_maze[i][j] == '0') || (the_maze[i][j] == 'C'))
				&& (the_maze[i - 1][j] == 'P'))
			{
				if (the_maze[i][j] == 'C')
					*rm_clc = *rm_clc - 1;
				the_maze[i][j] = 'P';
				the_maze[i - 1][j] = '0';
				*counter = *counter + 1;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
