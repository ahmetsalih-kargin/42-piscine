/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmkargi <ahmkargi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 10:43:56 by ahmkargi          #+#    #+#             */
/*   Updated: 2026/09/05 15:31:08 by ahmkargi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

void	ft_putstr_non_printable(char *str)
{
	char	*hex;
	int		c;

	hex = "0123456789abcdef";
	while (*str)
	{
		c = (unsigned char)*str;
		if (ft_is_printable(c))
			ft_putchar(c);
		else
		{
			ft_putchar('\\');
			ft_putchar(hex[c / 16]);
			ft_putchar(hex[c % 16]);
		}
		str++;
	}
}
