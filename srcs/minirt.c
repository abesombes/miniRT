/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:30:42 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/08 01:38:52 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minirt.h"

int	main(int ac, char **av)
{
	t_scene	sc;

    (void)ac;
    (void)av;
    if (!ft_init_sc(&sc))
        return (-1);
  //  printf("\nres_w, res_h: [%i, %i]", sc.res_w, sc.res_h);
	/*if (ft_parser_control_args_file(ac, av[1], &sc) == -1)
		return (-1);*/
     sc.mlx = mlx_init();
	 sc.mlx_win = mlx_new_window(sc.mlx, /*sc.res_w, sc.res_h,*/1080, 1080, "miniRT - RayTracer Engine");
     mlx_loop(sc.mlx);
}