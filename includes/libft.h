/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cchevall <cchevall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/03/07 15:50:51 by cchevall          #+#    #+#             */
/*   Updated: 2014/05/25 14:15:15 by cchevall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <unistd.h>

typedef struct		s_dlist
{
	char			*cmd;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;
/*
** Print functions.
*/
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *str, int fd);
void				ft_putstr_fd_sub(char *str, int fd, int size);
void				ft_putendl_fd(char *str, int fd);
void				ft_puttab_fd(char **tabl, size_t fd);
void				ft_putnbr_fd(int n, int fd);
int					tputs_putchar(int c);
/*
** Strings functions.
*/
char				*ft_strrchr(const char *s, int c);
int					ft_isprint(char *str);
int					isprint_less_sp(int c);
size_t				ft_strlen(const char *s);
void				ft_strclr(char *s);
size_t				ft_tablen(char **s);
void				*ft_memset(void *str, int c, size_t len);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
int					get_next_line(int const fd, char **line);
int					ft_atoi(const char *str);
int					is_digit(char *str);
char				*ft_itoa(int n);
int					word_len(char *sentence);
/*
** Mem allocating functions.
*/
char				**ft_strsplit(char const *s, char c);
char				*ft_strdup(char *s1);
char				*ft_strnew(size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_del_char(char *str, size_t pos);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_stradd(char *s1, const char *s2, size_t pos);
void				*ft_memalloc(size_t size);
void				ft_strdel(char **str);
void				ft_bzero(void *str, size_t n);
/*
** Mem freeing functions.
*/
void				*destroy_var(void *var);
char				**destroy_tab(char **tab_char, size_t size);
#endif
