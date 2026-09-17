/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhamalt <muhamalt@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 21:29:45 by muhamalt          #+#    #+#             */
/*   Updated: 2026/09/16 21:29:48 by muhamalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

static int	fill_info(char *buffer, int len, t_map *map);
static int	check_line_chars(char *line, int len, t_map *map);
static int	check_map_body(char *buffer, int start, t_map *map);
static int	build_grid(char *buffer, int start, t_map *map);

int	parse_map(char *buffer, t_map *map)
{
	int	len;

	if (!buffer || buffer[0] == '\0')
		return (0);
	len = 0;
	while (buffer[len] && buffer[len] != '\n')
		len++;
	if (buffer[len] == '\0' || len < 4)
		return (0);
	if (!fill_info(buffer, len, map))
		return (0);
	if (!check_map_body(buffer, len + 1, map))
		return (0);
	if (!build_grid(buffer, len + 1, map))
		return (0);
	return (1);
}

static int	fill_info(char *buffer, int len, t_map *map)
{
	int	i;
	int	n;

	map->full = buffer[len - 1];
	map->obstacle = buffer[len - 2];
	map->empty = buffer[len - 3];
	if (map->empty == map->obstacle || map->empty == map->full
		|| map->obstacle == map->full || !is_printable(map->empty)
		|| !is_printable(map->obstacle) || !is_printable(map->full))
		return (0);
	i = 0;
	n = 0;
	while (i < len - 3)
	{
		if (!is_digit(buffer[i]) || n > 2147483647 / 10
			|| (n == 2147483647 / 10 && buffer[i] - '0' > 7))
			return (0);
		n = n * 10 + (buffer[i] - '0');
		i++;
	}
	if (n <= 0)
		return (0);
	map->rows = n;
	return (1);
}

static int	check_line_chars(char *line, int len, t_map *map)
{
	int	j;

	j = 0;
	while (j < len)
	{
		if (line[j] != map->empty && line[j] != map->obstacle)
			return (0);
		j++;
	}
	return (1);
}

static int	check_map_body(char *buffer, int start, t_map *map)
{
	int	i;
	int	j;
	int	lines;

	i = start;
	lines = 0;
	while (buffer[i])
	{
		j = i;
		while (buffer[j] && buffer[j] != '\n')
			j++;
		if (lines == 0)
			map->cols = j - i;
		if (j - i != map->cols || j == i)
			return (0);
		if (!check_line_chars(buffer + i, j - i, map))
			return (0);
		lines++;
		i = j;
		if (buffer[i] == '\n')
			i++;
	}
	if (lines != map->rows)
		return (0);
	return (1);
}

static int	build_grid(char *buffer, int start, t_map *map)
{
	int	i;
	int	j;

	map->grid = malloc((size_t)map->rows * (size_t)map->cols);
	if (!map->grid)
		return (0);
	i = start;
	j = 0;
	while (buffer[i])
	{
		if (buffer[i] == '\n')
			i++;
		else
		{
			map->grid[j] = buffer[i];
			j++;
			i++;
		}
	}
	return (1);
}
