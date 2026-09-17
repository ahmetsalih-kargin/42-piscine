/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmkargi <ahmkargi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 02:17:02 by ahmkargi          #+#    #+#             */
/*   Updated: 2026/08/31 13:02:39 by ahmkargi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	writechar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	a;

	a = 0;
	while (str[a] != '\0')
	{
		writechar(str[a]);
		a++;
	}
}
