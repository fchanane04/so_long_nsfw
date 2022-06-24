/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 23:06:17 by fchanane          #+#    #+#             */
/*   Updated: 2022/06/24 21:37:28 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	exit_game(int key, int counter)
{
	if (key == 53)
	{
		ft_putstr("moves : ");
		ft_putstr(ft_itoa(counter));
		ft_putstr("\n");
		exit(0);
	}
}

int	destroy(void)
{
	exit(0);
	return (0);
}

void	choose_move(int key, t_game *game, int width, int height)
{
	if (key == 2)
	{
		move_right(game->the_maze, &game->counter, &game->rm_clc);
		initialize_map(game, width, height);
	}
	if (key == 0)
	{
		move_left(game->the_maze, &game->counter, &game->rm_clc);
		initialize_map(game, width, height);
	}
	if (key == 13)
	{
		move_up(game->the_maze, &game->counter, &game->rm_clc, game->lines);
		initialize_map(game, width, height);
	}
	if (key == 1)
	{
		move_down(game->the_maze, &game->counter, &game->rm_clc);
		initialize_map(game, width, height);
	}
}

int	esc_fon(int key, t_game	*game)
{
	int	width;
	int	height;

	width = 0;
	height = 0;
	exit_game(key, game->counter);
	choose_move(key, game, width, height);
	if (key != 0 && key != 1 && key != 2 && key != 13)
		printf("Warning : Choose a valid move from : A, W, D and S\n");
	return (0);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = malloc(sizeof(t_game));
	check_argc_nb(argc);
	check_file(argv[1]);
	game->lines = check_map(argv[1]);
	game->the_maze = create_the_maze(argv[1], game->lines);
	game->columns = ft_strlen(game->the_maze[0]);
	game->rm_clc = parse_the_map(game->the_maze, game->lines);
	game->mlx = mlx_init();
	game->mlx_win = mlx_new_window(game->mlx, 64 * game->columns,
			64 * game->lines, "Infinity War");
	initialize_map(game, game->width, game->height);
	game->counter = 0;
	mlx_hook(game->mlx_win, 17, 0L, destroy, NULL);
	mlx_key_hook(game->mlx_win, esc_fon, game);
	mlx_loop(game->mlx);
	return (0);
}
