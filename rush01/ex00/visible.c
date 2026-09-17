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

#include "rush01.h"

int	count_visible(const int seq[SIZE], int reverse)
{
	int	i;
	int	max;
	int	count;
	int	idx;

	i = 0;
	max = 0;
	count = 0;
	while (i < SIZE)
	{
		if (reverse == 0)
			idx = i;
		else
			idx = SIZE - 1 - i;
		if (seq[idx] > max)
		{
			max = seq[idx];
			count++;
		}
		i++;
	}
	return (count);
}
