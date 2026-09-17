/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhamalt <muhamalt@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 21:30:07 by muhamalt          #+#    #+#             */
/*   Updated: 2026/09/16 21:30:19 by muhamalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <unistd.h>

void	print_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->rows)
	{
		write(1, map->grid + i * map->cols, map->cols);
		write(1, "\n", 1);
		i++;
	}
}
