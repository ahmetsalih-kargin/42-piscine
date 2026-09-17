/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmkargi <ahmkargi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/13 14:31:21 by ahmkargi          #+#    #+#             */
/*   Updated: 2026/09/14 13:23:03 by ahmkargi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_cat(char *dest, char *src, int k)
{
	int	j;

	j = 0;
	while (src[j])
		dest[k++] = src[j++];
	return (k);
}

int	ft_total_len(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	len = 0;
	i = -1;
	while (++i < size)
	{
		len += ft_strlen(strs[i]);
		if (i < size - 1)
			len += ft_strlen(sep);
	}
	return (len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*res;
	int		i;
	int		k;

	res = malloc(ft_total_len(size, strs, sep) + 1);
	if (!res)
		return (NULL);
	i = -1;
	k = 0;
	while (++i < size)
	{
		k = ft_cat(res, strs[i], k);
		if (i < size - 1)
			k = ft_cat(res, sep, k);
	}
	res[k] = '\0';
	return (res);
}
