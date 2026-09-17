/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmkargi <ahmkargi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 20:45:56 by ahmkargi          #+#    #+#             */
/*   Updated: 2026/08/30 18:11:04 by ahmkargi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_putchar(char c);

static void	print_row(int x, char first, char last, char mid)
{
	int	i;

	i = 0;
	if (x > 0)
		ft_putchar(first);
	while (i < x - 2)
	{
		ft_putchar(mid);
		i++;
	}
	if (x > 1)
		ft_putchar(last);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	j;

	if (x <= 0 || y <= 0)
		return ;
	j = 0;
	while (j < y)
	{
		if (j == 0)
			print_row(x, '/', '\\', '*');
		else if (j == y - 1)
			print_row(x, '\\', '/', '*');
		else
			print_row(x, '*', '*', ' ');
		j++;
	}
}
