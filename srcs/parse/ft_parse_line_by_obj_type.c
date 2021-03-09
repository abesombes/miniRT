/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_line_by_obj_type.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:20:40 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/09 16:15:37 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_parse.h"

int	ft_parse_line_by_obj_type(char *line, t_scene *sc)
{
	int i;

	i = 0;
	if (line[0] == 'R' && (line[1] == '\t' || line[1] == ' '))
		i = ft_parse_res(line + 1, sc);
	else if (line[0] == 'A' && (line[1] == '\t' || line[1] == ' '))
		i = ft_parse_alight(line + 1, sc);
/*	else if (line[0] == 'c' && (line[1] == '\t' || line[1] == ' '))
		i = ft_parse_cam(line + 1, sc);
	else if (line[0] == 'l' && (line[1] == '\t' || line[1] == ' '))
		i = ft_parse_light(line + 1, sc);
	else if (line[0] == 's' && line[1] == 'p')
		i = ft_parse_sphere(line + 2 , sc);
	else if (line[0] == 'p' && line[1] == 'l')
		i = ft_parse_plane(line + 2, sc);
	else if (line[0] == 's' && line[1] == 'q')
		i = ft_parse_square(line + 2, sc);
	else if (line[0] == 'c' && line[1] == 'y')
		i = ft_parse_cylinder(line + 2, sc);
	else if (line[0] == 't' && line[1] == 'r')
		i = ft_parse_triangle(line + 2, sc);*/
	else
		i = (ft_check_if_space_tab_only(&line) ? 0: -6); 
	return (i);
}