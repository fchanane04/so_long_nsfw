/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/17 20:10:55 by fchanane          #+#    #+#             */
/*   Updated: 2022/06/19 23:21:17 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	error_fd(int fd)
{
	if (fd < 0)
	{
		perror("File");
		exit(1);
	}
}

void	error_ext(char *file, int fd)
{
	if (ft_strncmp(ft_strrchr(file, '.'), ".ber", 5))
	{
		close(fd);
		ft_putstr("ERROR\nExtension is invalid\n");
		exit(1);
	}
	close(fd);
}

void	error_empty(char *read, int fd)
{
	if (!read)
	{
		ft_putstr("ERROR\nMap is Empty\n");
		close(fd);
		exit(1);
	}
}

void	error_equal(int fd, int size, int size_line)
{
	if (size_line != size)
	{
		ft_putstr("ERROR\nInvalid Map : Lines should be equal\n");
		close(fd);
		exit(1);
	}
}

void	error_enough(int size, int lines)
{
	if (size < 3 || lines < 3)
	{
		ft_putstr("ERROR\nInvalid Map : not enough Lines and/or Columns\n");
		exit(1);
	}
}
