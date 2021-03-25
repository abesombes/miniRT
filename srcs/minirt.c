/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:30:42 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/25 15:36:41 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/ft_export.h"
#include "../includes/ft_parse.h"
#include "../includes/ft_render.h"
#include "../includes/ft_rt.h"

int	main(int ac, char **av)
{
	t_scene	sc;
	t_inter	inter;

	if ((ft_control_args_file(ac, av) == -1))
		return (-1);
	sc.mlx = mlx_init();
	if (!ft_parse_open_rt_file(av[1], &sc))
		return (-1);
	sc.mlx_win = mlx_new_window(sc.mlx, sc.res_w, sc.res_h, "miniRT - RayTracer Engine");
	sc.img = mlx_new_image(sc.mlx, sc.res_w, sc.res_h);
	sc.addr = mlx_get_data_addr(sc.img, &sc.bits_per_pixel, &sc.line_length, &sc.endian);
	ft_rt_trace_rays(&sc, &inter);
	mlx_key_hook(sc.mlx_win, ft_key_hook, sc.addr);
	mlx_hook(sc.mlx_win, 17, 1, ft_close_win, sc.addr);
	/*** ATTENTION 33 SOUS LINUX ***/
	if (ac == 3 && !(ft_strcmp(av[2], "-save")))
		ft_save_to_bmp("scene_export.bmp", (unsigned char *)sc.addr, sc.res_w, sc.res_h);
	mlx_loop(sc.mlx);
}