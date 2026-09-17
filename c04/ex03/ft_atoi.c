/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmkargi <ahmkargi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/08 17:23:05 by ahmkargi          #+#    #+#             */
/*   Updated: 2026/09/09 05:10:35 by ahmkargi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	number;
	int	negative;

	number = 0;
	negative = 1;
	while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			negative = -negative;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10;
		number += *str - '0';
		str++;
	}
	return (number * negative);
}
