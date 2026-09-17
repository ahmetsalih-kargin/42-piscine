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

#ifndef RUSH01_H
# define RUSH01_H

# define SIZE 4
# define NB_CLUES 16
# define NB_PERMS 24

typedef struct s_clues
{
	int		col_top[SIZE];
	int		col_bottom[SIZE];
	int		row_left[SIZE];
	int		row_right[SIZE];
}			t_clues;

typedef struct s_data
{
	int		board[SIZE][SIZE];
	int		col_used[SIZE][SIZE + 1];
	t_clues	clues;
}			t_data;

int			parse_clues(char *str, t_clues *clues);
int			solve_row(t_data *d, int row);
int			count_visible(const int seq[SIZE], int reverse);
void		fill_perms(int perms[24][4]);
void		print_board(int board[SIZE][SIZE]);
void		print_error(void);

#endif