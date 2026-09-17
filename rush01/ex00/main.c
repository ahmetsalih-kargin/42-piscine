/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmkargi <ahmkargi@student.42istanbul.c   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/04 20:16:25 by ahmkargi          #+#    #+#             */
/*   Updated: 2026/09/06 18:49:46 by misunal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush01.h"

static void	init_data(t_data	*d)
{
	int	i;
	int	j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE + 1)
		{
			d->col_used[i][j] = 0;
			j++;
		}
		i++;
	}
}

int	main(int argc, char	**argv)
{
	t_data	d;

	if (argc != 2 || parse_clues(argv[1], &d.clues) == 0)
	{
		print_error();
		return (1);
	}
	init_data(&d);
	if (solve_row(&d, 0))
		print_board(d.board);
	else
		print_error();
	return (0);
}
