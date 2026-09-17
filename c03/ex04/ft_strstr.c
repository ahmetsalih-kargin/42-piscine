/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmkargi <ahmkargi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/07 12:11:59 by ahmkargi          #+#    #+#             */
/*   Updated: 2026/09/07 15:37:50 by ahmkargi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*begin;
	char	*search;

	if (!*to_find)
		return (str);
	while (*str)
	{
		begin = str;
		search = to_find;
		while (*str && *search && *str == *search)
		{
			str++;
			search++;
		}
		if (!*search)
			return (begin);
		str = begin + 1;
	}
	return (0);
}
