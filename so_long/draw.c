/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/30 23:12:26 by fchanane          #+#    #+#             */
/*   Updated: 2022/06/24 21:52:55 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_in(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->lines)
	{
		j = 0;
		while (j < game->columns)
		{
			if (game->the_maze[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->images.wall, 64 * j, 64 * i);
			if (game->the_maze[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->images.player, 64 * j, 64 * i);
			if (game->the_maze[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->images.exit, 64 * j, 64 * i);
			if (game->the_maze[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->mlx_win,
					game->images.stone, 64 * j, 64 * i);
			j++;
		}
		i++;
	}
}

void	moves_display(t_game *game)
{
	int	i;
	int	j;

	i = 64 * (game->lines - 1) + 20;
	j = 20;
	mlx_string_put(game->mlx, game->mlx_win, j, i, CL, MS);
	j = 64 * 2 + 20;
	if (game->counter > 0)
		mlx_string_put(game->mlx, game->mlx_win, j, i, CL,
			ft_itoa(game->counter));
}

void	initialize_map(t_game *game, int width, int height)
{
	game->images.wall = mlx_xpm_file_to_image(game->mlx,
			WL, &width, &height);
	game->images.player = mlx_xpm_file_to_image(game->mlx,
			TH, &width, &height);
	game->images.stone = mlx_xpm_file_to_image(game->mlx,
			ST, &width, &height);
	if (game->rm_clc != 0)
		game->images.exit = mlx_xpm_file_to_image(game->mlx,
				EB, &width, &height);
	if (game->rm_clc == 0)
		game->images.exit = mlx_xpm_file_to_image(game->mlx,
				EA, &width, &height);
	game->bg = mlx_xpm_file_to_image(game->mlx, BG, &width, &height);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->bg, 0, 0);
	draw_in(game);
	moves_display(game);
}
