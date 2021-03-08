/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:30:42 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/08 15:08:19 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int ac, char **av)
{
	t_scene	sc;

	if (!ft_init_sc(&sc) || (ft_control_args_file(ac, av[1]) == -1))
		return (-1);
	if (!ft_parse_open_rt_file(av[1], &sc))
		return (-1);
//	sc.mlx = mlx_init();
	printf("sc.res: [%d, %d]", sc.res_w, sc.res_h);
//	sc.mlx_win = mlx_new_window(sc.mlx, sc.res_w, sc.res_h, "miniRT - RayTracer Engine");
//	mlx_loop(sc.mlx);
}