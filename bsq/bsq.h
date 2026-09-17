/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhamalt <muhamalt@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 21:25:47 by muhamalt          #+#    #+#             */
/*   Updated: 2026/09/16 21:25:52 by muhamalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H

typedef struct s_map
{
	int		rows;
	int		cols;
	char	empty;
	char	obstacle;
	char	full;
	char	*grid;
}	t_map;

char	*read_input(char *filename);
int		parse_map(char *buffer, t_map *map);
void	solve_bsq(t_map *map);
void	print_map(t_map *map);
int		ft_strlen(char *str);
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		is_digit(char c);
int		is_printable(char c);

#endif
