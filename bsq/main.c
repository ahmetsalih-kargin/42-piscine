/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhamalt <muhamalt@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 21:27:17 by muhamalt          #+#    #+#             */
/*   Updated: 2026/09/16 21:34:18 by muhamalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>

static void	handle_map(char *path, int extra_nl)
{
	char	*buf;
	t_map	map;

	buf = read_input(path);
	if (buf && parse_map(buf, &map))
	{
		solve_bsq(&map);
		print_map(&map);
		free(map.grid);
	}
	else
		ft_putstr("map error\n");
	if (extra_nl)
		ft_putchar('\n');
	free(buf);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc == 1)
		handle_map(NULL, 0);
	else
	{
		i = 1;
		while (i < argc)
		{
			handle_map(argv[i], i != argc - 1);
			i++;
		}
	}
	return (0);
}
