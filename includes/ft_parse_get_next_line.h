/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_get_next_line.h                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:11:55 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/11 15:36:12 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_GET_NEXT_LINE_H
# define FT_PARSE_GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>

typedef struct	s_fl
{
	char		*buffer;
	int			pos;
	int			bytes_read;
	int			fd;
}				t_fl;

void			ft_putstr_fd(char *s, int fd);

/*--------------------ft_parse_get_next_line.c--------------------------*/
int				ft_parse_get_next_line(int fd, char **line);

/*--------------------ft_parse_get_next_line_utils.c--------------------------*/
size_t			ft_strlen(const char *str);
char			*ft_strnjoin(char *s1, char const *s2, size_t n);
int				find_line(t_fl *fl);
int				init(t_fl *fl, int fd, char **line);
int				reinit(t_fl *fl);

#endif

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 32
#endif