/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/03 17:30:47 by cchevall          #+#    #+#             */
/*   Updated: 2014/05/15 19:21:58 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "../includes/libft.h"
# define BUFF_SIZE 65536

int		get_next_line(int const fd, char **line);
void	ft_buffer_clear(char *s);
size_t	ft_strlen(const char *str);
char	*ft_strnjoin(char const *s1, char const *s2, unsigned int size);
int		ft_check_buffer(char *buffer, int cursor, char **line);

#endif
