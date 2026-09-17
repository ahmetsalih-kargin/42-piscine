/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmkargi <ahmkargi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 18:14:34 by ahmkargi          #+#    #+#             */
/*   Updated: 2026/08/30 18:14:55 by ahmkargi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_putchar(char c);

static void	print_row(int x, char corner, char mid)
{
	int	i;

	i = 0;
	if (x > 0)
		ft_putchar(corner);
	while (i < x - 2)
	{
		ft_putchar(mid);
		i++;
	}
	if (x > 1)
		ft_putchar(corner);
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
			print_row(x, 'A', 'B');
		else if (j == y - 1)
			print_row(x, 'C', 'B');
		else
			print_row(x, 'B', ' ');
		j++;
	}
}
