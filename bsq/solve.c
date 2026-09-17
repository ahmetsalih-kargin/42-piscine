/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhamalt <muhamalt@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 21:31:43 by muhamalt          #+#    #+#             */
/*   Updated: 2026/09/16 21:32:24 by muhamalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

static int	cell_size(t_map *map, int *line, int prev, int pos)
{
	int	i;
	int	j;
	int	m;

	i = pos / map->cols;
	j = pos % map->cols;
	if (map->grid[pos] == map->obstacle)
		return (0);
	if (i == 0 || j == 0)
		return (1);
	m = line[j];
	if (line[j - 1] < m)
		m = line[j - 1];
	if (prev < m)
		m = prev;
	return (m + 1);
}

static void	try_best(int *best, int val, int i, int j)
{
	if (val > best[0])
	{
		best[0] = val;
		best[1] = i;
		best[2] = j;
	}
}

static void	run_dp(t_map *map, int *line, int *best)
{
	int	i;
	int	j;
	int	prev;
	int	old;

	i = 0;
	while (i < map->rows)
	{
		prev = 0;
		j = 0;
		while (j < map->cols)
		{
			old = line[j];
			line[j] = cell_size(map, line, prev, i * map->cols + j);
			try_best(best, line[j], i, j);
			prev = old;
			j++;
		}
		i++;
	}
}

static void	fill_square(t_map *map, int y, int x, int size)
{
	int	i;
	int	j;

	i = y;
	while (i < y + size)
	{
		j = x;
		while (j < x + size)
		{
			map->grid[i * map->cols + j] = map->full;
			j++;
		}
		i++;
	}
}

void	solve_bsq(t_map *map)
{
	int	*line;
	int	best[3];
	int	i;

	best[0] = 0;
	best[1] = 0;
	best[2] = 0;
	line = malloc(sizeof(int) * (size_t)map->cols);
	if (!line)
		return ;
	i = 0;
	while (i < map->cols)
	{
		line[i] = 0;
		i++;
	}
	run_dp(map, line, best);
	free(line);
	if (best[0] > 0)
		fill_square(map, best[1] - best[0] + 1,
			best[2] - best[0] + 1, best[0]);
}
