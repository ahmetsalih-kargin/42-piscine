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

static int	skip_spaces(char *str, int i)
{
	while (str[i] == ' ')
		i++;
	return (i);
}

static int	read_number(char *str, int *i, int *value)
{
	if (str[*i] < '1' || str[*i] > '9')
		return (0);
	*value = str[*i] - '0';
	*i = *i + 1;
	if (str[*i] >= '0' && str[*i] <= '9')
		return (0);
	return (1);
}

static void	fill_clues(t_clues *clues, int *values)
{
	int	n;

	n = 0;
	while (n < SIZE)
	{
		clues->col_top[n] = values[n];
		clues->col_bottom[n] = values[SIZE + n];
		clues->row_left[n] = values[2 * SIZE + n];
		clues->row_right[n] = values[3 * SIZE + n];
		n++;
	}
}

int	parse_clues(char *str, t_clues *clues)
{
	int	values[NB_CLUES];
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (n < NB_CLUES)
	{
		i = skip_spaces(str, i);
		if (read_number(str, &i, &values[n]) == 0 || values[n] < 1
			|| values[n] > SIZE)
			return (0);
		n++;
		i = skip_spaces(str, i);
	}
	if (str[i] != '\0')
		return (0);
	fill_clues(clues, values);
	return (1);
}
