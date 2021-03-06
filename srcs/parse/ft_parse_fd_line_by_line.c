/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_fd_line_by_line.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:53:11 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/12 21:06:52 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_err_print.h"
#include "../../includes/ft_parse_get_next_line.h"
#include "../../includes/ft_parse.h"

int ft_parse_fd_line_by_line(int fd, t_scene *sc)
{
	int i;
	int ret;
	int obj_id;
	char *line;

	obj_id = 0;
	while ((ret = ft_parse_get_next_line(fd, &line)) >= 0)
	{
		i = ft_parse_line_by_obj_type(line, sc, &obj_id);
		obj_id++;
		if (i != 0)
		{
			ft_err_print(i);
			return (-1);
		}
		if (ret == 0)
			break ;
	}
	return (1);
}