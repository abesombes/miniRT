/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:30:42 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/11 12:32:36 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"
#include "../includes/ft_export.h"

int	main(int ac, char **av)
{
	t_scene	sc;

	if ((ft_control_args_file(ac, av[1]) == -1))
		return (-1);
	if (!ft_parse_open_rt_file(av[1], &sc))
		return (-1);
	sc.mlx = mlx_init();
	printf("\nsc.res: [%d, %d]", sc.res_w, sc.res_h);
	mlx_get_screen_size(sc.mlx_win, &sc.scr_w, &sc.scr_h);
	printf("\neffective screen res: [%d, %d]", sc.scr_w, sc.scr_h);
	sc.mlx_win = mlx_new_window(sc.mlx, sc.res_w, sc.res_h, "miniRT - RayTracer Engine");
	mlx_key_hook(sc.mlx_win, key_hook, sc.addr);
 	mlx_mouse_hook(sc.mlx_win, mouse_hook, sc.addr);
	mlx_hook(sc.mlx_win, 17, 1, ft_close_win, sc.addr);
	/*** ATTENTION 33 SOUS LINUX ***/
	if (ft_strcmp(av[2], "-save"))
		ft_save_to_bmp("scene_export.bmp", sc.img, sc.res_w, sc.res_h);
	mlx_loop(sc.mlx);
}