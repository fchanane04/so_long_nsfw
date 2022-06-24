/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_error_msg.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchanane <fchanane@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/18 22:50:26 by fchanane          #+#    #+#             */
/*   Updated: 2022/06/18 23:00:16 by fchanane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	msg_position(int p)
{
	if (p != 1)
	{
		ft_putstr("Invalid Map : There is Only One Thanos\n");
		exit(1);
	}
}

void	msg_collect(int c)
{
	if (c < 1)
	{
		ft_putstr("Invalid Map : Enter More Infinity Stones\n");
		exit(1);
	}
}

void	msg_exit(int e)
{
	if (e < 1)
	{
		ft_putstr("Invalid Map : At Least One Exit\n");
		exit(1);
	}
}

void	msg_parser(int p, int c, int e)
{
	msg_position(p);
	msg_collect(c);
	msg_exit(e);
}
