/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/11 01:02:53 by fchanane          #+#    #+#             */
/*   Updated: 2022/06/19 20:56:34 by fchanane         ###   ########.fr       */
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

void	initialize_map(t_game *game, int width, int height)
{
	int	i;
	int	j;

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
	mlx_string_put(game->mlx, game->mlx_win, 30 * (j - 3), 64 * i + 15, CL, MS);
	if (game->counter > 0)
		mlx_string_put(game->mlx, game->mlx_win, 35 * (j - 1), 64 * i + 15, CL,
			ft_itoa(game->counter));
}
