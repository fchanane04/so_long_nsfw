/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 01:04:24 by fchanane          #+#    #+#             */
/*   Updated: 2022/06/24 01:18:23 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include<fcntl.h>
# include"mlx.h"

typedef struct s_checker
{
	char	*read;
	char	*line;
	int		size;
	int		size_line;
	int		fd;
}	t_checker;

typedef struct s_error
{
	char	*read;
	char	*line;
	int		size_line;
	int		size;
	int		lines;
}	t_error;

typedef struct s_creat
{
	int		fd;
	char	*line;
	int		columns;
	char	**the_maze;
}	t_creat;

typedef struct s_images
{
	void	*wall;
	void	*player;
	void	*exit;
	void	*stone;	
}	t_images;

typedef struct s_game
{
	void		*mlx;
	void		*mlx_win;
	void		*bg;
	t_images	images;
	char		**the_maze;
	int			lines;
	int			columns;
	int			counter;
	int			rm_clc;
	int			width;
	int			height;
}	t_game;

# define WL "./images/wall.xpm"
# define TH "./images/thanos.xpm"
# define ST "./images/purple.xpm"
# define EB "./images/exit_before.xpm"
# define EA "./images/exit_after.xpm"
# define BG "./images/bg.xpm"
# define MS "Moves Count: "
# define CL 0xccccff

void	check_argc_nb(int argc);
void	check_file(char *file);

int		endline_in(char *line);
int		check_map(char *file);

size_t	ft_strlen(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char	const *s, char c);
int		ft_strncmp(char *s1, char *s2, size_t n);
char	*ft_strrchr(const char *s, int c);
void	ft_putstr(char *s);

char	*ft_strdup(const char *s1);
char	*ft_strjoin(char *s1, char *s2);

int		search(char *s, int c);
char	*restart(char **stock);
char	*create_line(char **stock);
char	*stock_in(int fd, char *stock, char *rest, int rd);
char	*get_next_line(int fd);

void	file_valid(int fd);
char	*create_the_line(char *line, char *the_maze);
char	**create_the_maze(char *file, int lines);

void	line_is_wall(char *line);
void	line_is_valid(char *line);
int		calculate_character(char *line, char character);
void	msg_position(int p);
void	msg_collect(int c);
void	msg_exit(int e);
void	msg_parser(int p, int c, int e);
int		parse_the_map(char **the_maze, int lines);

void	moves_display(t_game *game);
void	initialize_map(t_game *game, int width, int height);
void	draw_in(t_game *game);
void	set_it_and_exit(char position, char ext, int *rm_clc);
void	exit_game(int key, int counter);
void	choose_move(int key, t_game *game, int width, int height);
int		move_right(char **the_maze, int *counter, int *rm_clc);
int		move_left(char **the_maze, int *counter, int *rm_clc);
int		move_up(char **the_maze, int *counter, int *rm_clc, int lines);
int		move_down(char **the_maze, int *counter, int *rm_clc);

char	*ft_itoa(int nb);
char	*ft_strcat(char *dest, char *src);

void	error_fd(int fd);
void	error_ext(char *file, int fd);
void	error_empty(char *read, int fd);
void	error_equal(int fd, int size, int size_line);
void	error_enough(int size, int lines);

#endif
