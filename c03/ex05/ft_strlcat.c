/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmkargi <ahmkargi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:12:02 by ahmkargi          #+#    #+#             */
/*   Updated: 2026/09/07 15:37:54 by ahmkargi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	unsigned int	pos;

	d_len = 0;
	s_len = 0;
	while (dest[d_len])
		d_len++;
	while (src[s_len])
		s_len++;
	if (size <= d_len)
		return (size + s_len);
	pos = 0;
	while (src[pos] && d_len + pos + 1 < size)
	{
		dest[d_len + pos] = src[pos];
		pos++;
	}
	dest[d_len + pos] = '\0';
	return (d_len + s_len);
}
