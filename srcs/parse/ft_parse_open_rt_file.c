/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_open_rt_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:39:59 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/08 14:52:23 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_err_print.h"
#include "../../includes/ft_parse.h"

int	ft_parse_open_rt_file(char *av, t_scene *sc)
{
	int fd;
	
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return(ft_err_print(-18));
	if (!(ft_parse_fd_line_by_line(fd, sc)))
		return(ft_err_print(12));
	if (close(fd) == -1)
		return(ft_err_print(-19));
	return (1);
}