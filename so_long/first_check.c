/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   first_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/26 18:48:00 by fchanane          #+#    #+#             */
/*   Updated: 2022/06/24 04:40:23 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	check_argc_nb(int argc)
{
	if (argc != 2)
	{
		ft_putstr("ERROR\nArguments number is invalid\n");
		exit(1);
	}
}

void	check_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	error_fd(fd);
	error_ext(file, fd);
}
