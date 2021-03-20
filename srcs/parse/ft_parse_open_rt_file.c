/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_open_rt_file.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:39:59 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/20 17:09:47 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_err_print.h"
#include "../../includes/ft_parse.h"
#include "../../includes/ft_olst.h"
#include "../../includes/ft_maths.h"

int	ft_parse_control_min_requirements(t_scene *sc)
{
	if (((sc->count_al = ft_olst_count_obj_by_obj_type(&sc->olst, 'a')) > 0 \
		|| ft_olst_count_obj_by_obj_type(&sc->olst, 'l') > 0) && \
			ft_olst_count_obj_by_obj_type(&sc->olst, 'm') > 0 &&
				sc->res_w > 0 && sc->res_h > 0)
		return (1);
	return (0);
}

int	ft_parse_open_rt_file(char *av, t_scene *sc)
{
	int fd;
	
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return(ft_err_print(-18));
	ft_init_sc(sc);
	if (!(ft_parse_fd_line_by_line(fd, sc)))
		return(ft_err_print(12));
	if (!(ft_parse_control_min_requirements(sc)))
		return(ft_err_print(-20));
	mlx_get_screen_size(sc->mlx_win, &sc->scr_w, &sc->scr_h);
	if (sc->res_w > sc->scr_w)
		sc->res_w = sc->scr_w;
	if (sc->res_h > sc->scr_h)
		sc->res_h = sc->scr_h;
	sc->cur_cam = ft_olst_return_first_obj_id_by_type(&sc->olst, 'm');
	sc->count_obj = ft_olst_count_obj_by_obj_group_type(&sc->olst, "spyqt");
	if (close(fd) == -1)
		return(ft_err_print(-19));
	return (1);
}