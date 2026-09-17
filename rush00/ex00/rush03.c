/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmkargi <ahmkargi@42istanbul.com.tr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 20:45:56 by ahmkargi          #+#    #+#             */
/*   Updated: 2026/08/29 22:59:42 by hersoy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_putchar(char c);

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
		if (j == 0 || j == y - 1)
			print_row(x, 'A', 'C', 'B');
		else
			print_row(x, 'B', 'B', ' ');
		j++;
	}
}
