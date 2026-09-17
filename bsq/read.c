/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: muhamalt <muhamalt@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/16 21:30:27 by muhamalt          #+#    #+#             */
/*   Updated: 2026/09/16 21:36:28 by muhamalt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 4096

static char	*ft_join(char *old, char *add, int add_len)
{
	char	*out;
	int		old_len;
	int		i;

	old_len = 0;
	if (old)
		while (old[old_len])
			old_len++;
	out = malloc(old_len + add_len + 1);
	if (!out)
	{
		free(old);
		return (NULL);
	}
	i = -1;
	while (++i < old_len)
		out[i] = old[i];
	i = -1;
	while (++i < add_len)
		out[old_len + i] = add[i];
	out[old_len + add_len] = '\0';
	free(old);
	return (out);
}

static char	*read_fd(int fd)
{
	char	tmp[BUFFER_SIZE];
	char	*buf;
	int		n;

	buf = NULL;
	n = read(fd, tmp, BUFFER_SIZE);
	while (n > 0)
	{
		buf = ft_join(buf, tmp, n);
		if (!buf)
			return (NULL);
		n = read(fd, tmp, BUFFER_SIZE);
	}
	if (n < 0)
	{
		free(buf);
		return (NULL);
	}
	return (buf);
}

char	*read_input(char *path)
{
	int		fd;
	char	*buf;

	if (!path)
		return (read_fd(0));
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (NULL);
	buf = read_fd(fd);
	close(fd);
	return (buf);
}
