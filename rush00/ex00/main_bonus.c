/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmkargi <ahmkargi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/30 18:14:16 by ahmkargi          #+#    #+#             */
/*   Updated: 2026/08/30 21:00:44 by ahmkargi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	error(int n)
{
	if (n == 1)
		write(2, "Error: 2 adet sayı girmelisin\n", 31);
	if (n == 2)
		write(2, "Error: Integer girmelisin\n", 26);
	if (n == 3)
		write(2, "Error: Girilen sayı integer boyutunu aşıyor\n", 47);
	if (n == 4)
		write(2, "Error: Pozitif sayı girmelisin\n", 32);
	return (1);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	is_overflow(char *str)
{
	int		i;
	long	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		n = n * 10 + (str[i] - '0');
		if (n > 2147483647)
			return (1);
		i++;
	}
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		n = n * 10 + (str[i] - '0');
		i++;
	}
	return (n);
}

int	main(int argc, char **argv)
{
	int	x;
	int	y;

	if (argc != 3)
		return (error(1));
	if (!is_number(argv[1]) || !is_number(argv[2]))
		return (error(2));
	if (is_overflow(argv[1]) || is_overflow(argv[2]))
		return (error(3));
	x = ft_atoi(argv[1]);
	y = ft_atoi(argv[2]);
	if (x <= 0 || y <= 0)
		return (error(4));
	rush(x, y);
	return (0);
}
