/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmkargi <ahmkargi@student.42istanbul.c   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/06 06:23:54 by ahmkargi          #+#    #+#             */
/*   Updated: 2026/09/06 18:51:55 by misunal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

#include <unistd.h>

static void
	write_digit(int n)
{
	char	c;

	c = '0' + n;
	write(1, &c, 1);
}

void	print_board(int board[SIZE][SIZE])
{
	int	r;
	int	c;

	r = 0;
	while (r < SIZE)
	{
		c = 0;
		while (c < SIZE)
		{
			write_digit(board[r][c]);
			if (c < SIZE - 1)
				write(1, " ", 1);
			c++;
		}
		write(1, "\n", 1);
		r++;
	}
}

void	print_error(void)
{
	write(1, "Error\n", 6);
}
