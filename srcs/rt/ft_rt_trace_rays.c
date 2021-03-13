/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_trace_rays.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:21:08 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/13 11:35:42 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_render.h"
#include "../../includes/ft_maths.h"
#include "../includes/ft_olst.h"

void ft_rt_trace_rays(t_scene *sc, t_inter *inter)
{
	int i;
	int j;
	t_cam current_cam;
	t_light light;
	t_sphere sp;
	
	j = 0;
	current_cam = (ft_olst_return_obj_by_id(&sc->olst, sc->cur_cam))->cam;
	light = (ft_olst_return_first_obj_by_type(&sc->olst, 'l'))->light;
	sp = (ft_olst_return_first_obj_by_type(&sc->olst, 's'))->sp;
	while (j < sc->res_h)
	{
		i = 0;
		while (i < sc->res_w)
		{
			ft_vec_set(&sc->ray.dir, i - sc->res_w / 2, j - sc->res_h / 2, -sc->res_w / (2 * tan(current_cam.fov / 2)));
			ft_vec_norm(&sc->ray.dir);
			ft_vec_cpy(&sc->ray.orig, &current_cam.pos);
			ft_ray_set(&sc->ray, &sc->ray.orig, &sc->ray.dir);
			ft_vec_set(&sc->pix_int, 0., 0., 0.);
			inter->has_junc = ft_rt_inter(&sc->ray, &sc->olst->sp, inter);
			if (inter->has_junc)
			{
			//	printf("hello from has_inter");
				//sc->pix_int
			}
			//sc->pix_int = *ft_vec_add(&sc->pix_int, ft_get_color(&sc->ray, &sc, &light, 5));
			sc->pix_color = ((int)round(fmin(fmax(pow(sc->pix_int.x, 0.4545), 0), 255)) + 0) << 16 | ((int)round(fmin(fmax(pow(sc->pix_int.y, 0.4545), 0), 255)) + 0) << 8 | ((int)round(fmin(fmax(pow(sc->pix_int.z, 0.4545), 0), 255)));
		//	printf("\npix_color: [%i] - i: [%i] - sc->res_h - j - 1: [%i]", sc->pix_color, i, sc->res_h - j - 1);
			ft_render_pixel_put(sc, 500, 500, 1564565);
			mlx_put_image_to_window(sc->mlx, sc->mlx_win, sc->img, 0, 0);
		//	mlx_pixel_put(sc->mlx, sc->mlx_win, 500, 500, 1565544);
		//	ft_render_pixel_put(sc, i, sc->res_h - j - 1, sc->pix_color);
			i++;
		}
		j++;
	}
}