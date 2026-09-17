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

static int	row_matches_clue(t_data *d, int row, int *perm)
{
	int	left;
	int	right;

	left = count_visible(perm, 0);
	right = count_visible(perm, 1);
	return (left == d->clues.row_left[row]
		&& right == d->clues.row_right[row]);
}

static int	fits_columns(t_data *d, int row, int *perm)
{
	int	c;

	(void)row;
	c = 0;
	while (c < SIZE)
	{
		if (d->col_used[c][perm[c]])
			return (0);
		c++;
	}
	return (1);
}

static void	place_row(t_data *d, int row, int *perm, int set)
{
	int	c;

	c = 0;
	while (c < SIZE)
	{
		d->board[row][c] = perm[c];
		d->col_used[c][perm[c]] = set;
		c++;
	}
}

static int	columns_match_clues(t_data *d)
{
	int	col[SIZE];
	int	c;
	int	r;

	c = 0;
	while (c < SIZE)
	{
		r = 0;
		while (r < SIZE)
		{
			col[r] = d->board[r][c];
			r++;
		}
		if (count_visible(col, 0) != d->clues.col_top[c]
			|| count_visible(col, 1) != d->clues.col_bottom[c])
			return (0);
		c++;
	}
	return (1);
}

int	solve_row(t_data *d, int row)
{
	int	perms[24][4];
	int	p;

	fill_perms(perms);
	p = 0;
	while (p < NB_PERMS)
	{
		if (row_matches_clue(d, row, perms[p])
			&& fits_columns(d, row, perms[p]))
		{
			place_row(d, row, perms[p], 1);
			if (row == SIZE - 1 && columns_match_clues(d))
				return (1);
			if (row < SIZE - 1 && solve_row(d, row + 1))
				return (1);
			place_row(d, row, perms[p], 0);
		}
		p++;
	}
	return (0);
}
