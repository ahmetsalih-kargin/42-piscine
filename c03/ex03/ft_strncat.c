/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmkargi <ahmkargi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:11:52 by ahmkargi          #+#    #+#             */
/*   Updated: 2026/09/07 15:38:10 by ahmkargi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char	*start;

	start = dest;
	while (*dest != '\0')
		dest++;
	while (nb > 0 && *src != '\0')
	{
		*dest++ = *src++;
		nb--;
	}
	*dest = '\0';
	return (start);
}
