/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 17:30:39 by cchevall          #+#    #+#             */
/*   Updated: 2014/05/15 19:21:32 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int const fd, char **line)
{
	static char		buffer[BUFF_SIZE + 1];
	static int		cursor;
	static int		end;
	int				status;

	if (fd == -10)
		end = 0;
	*line = ft_strnew(1);
	cursor = ft_check_buffer(buffer, cursor, line);
	if (cursor >= 0)
		return (1);
	while ((status = read(fd, buffer, BUFF_SIZE)) > 0)
	{
		cursor = 0;
		cursor = ft_check_buffer(buffer, cursor, line);
		if (cursor >= 0)
			return (1);
	}
	if (!end && ft_strlen(*line))
	{
		end = 1;
		return (1);
	}
	return (status);
}

int		ft_check_buffer(char *buffer, int cursor, char **line)
{
	int				start;

	start = cursor;
	while (cursor < BUFF_SIZE)
	{
		if (buffer[cursor] == '\n')
		{
			cursor++;
			*line = ft_strnjoin(*line, buffer + start, cursor - start - 1);
			return (cursor);
		}
		cursor++;
	}
	*line = ft_strnjoin(*line, buffer + start, cursor - start);
	ft_strclr(buffer);
	return (-1);
}

char	*ft_strnjoin(char const *s1, char const *s2, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	size_t			total_size;
	char			*str;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	total_size = ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1;
	str = ft_strnew(total_size);
	if (str)
	{
		while (s1[i])
		{
			str[j++] = s1[i++];
		}
		i = 0;
		while (s2[i] && i < size)
		{
			str[j++] = s2[i++];
		}
		return (str);
	}
	return (NULL);
}
