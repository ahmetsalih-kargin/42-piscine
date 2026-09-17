/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahmkargi <ahmkargi@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/29 08:30:06 by ahmkargi          #+#    #+#             */
/*   Updated: 2026/09/05 15:31:16 by ahmkargi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	new_word;

	i = 0;
	new_word = 1;
	while (str[i] != '\0')
	{
		if ((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z')
			|| (str[i] >= '0' && str[i] <= '9'))
		{
			if (new_word && str[i] >= 'a' && str[i] <= 'z')
				str[i] -= 32;
			else if (!new_word && str[i] >= 'A' && str[i] <= 'Z')
				str[i] += 32;
			new_word = 0;
		}
		else
			new_word = 1;
		i++;
	}
	return (str);
}
