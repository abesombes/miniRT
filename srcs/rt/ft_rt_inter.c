/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/12 16:19:31 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/20 15:36:50 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_rt.h"
#include "../../includes/ft_maths.h"
#include "../../includes/ft_olst.h"

int ft_rt_inter_all(t_scene *sc, t_ray *ray, t_inter *inter, int opt)
{	
	sc->k = 0;
	inter->min_t = 1E10;
	inter->cur_obj_id = 0;
	while (sc->k < sc->count_obj)
	{
		if (!(inter->cur_obj = ft_olst_return_next_obj_from_group(&sc->olst, inter->cur_obj_id, "spyqt")))
			break ;
		inter->cur_obj_id = inter->cur_obj->id;
		if (inter->cur_obj->obj_type == 's')
		{
			inter->cur_s = inter->cur_obj->sp;
			inter->cur_s_id = inter->cur_obj->id;
			ft_init_inter(inter);
			if ((inter->has_junc = ft_rt_inter_ray_sp(ray, &inter->cur_s, inter)))
			{
				if (inter->t < inter->min_t)
					ft_rt_save_min_t_pix_int(sc, inter, opt);
			}
		}
		if (inter->cur_obj->obj_type == 't')
		{
			inter->cur_t = inter->cur_obj->tr;
			inter->cur_t_id = inter->cur_obj->id;
			ft_init_inter(inter);
			if ((inter->has_junc = ft_rt_inter_ray_tr(ray, &inter->cur_t, inter)))
			{
				if (inter->t < inter->min_t)
					ft_rt_save_min_t_pix_int(sc, inter, opt);
			}
		}
		if (inter->cur_obj->obj_type == 'p')
		{
			inter->cur_p = inter->cur_obj->plane;
			inter->cur_p_id = inter->cur_obj->id;
			ft_init_inter(inter);
			if ((inter->has_junc = ft_rt_inter_ray_pl(ray, &inter->cur_p, inter)))
			{
				if (inter->t < inter->min_t)
					ft_rt_save_min_t_pix_int(sc, inter, opt);
			}
		}
		if (inter->cur_obj->obj_type == 'q')
		{
			// printf("\nIAM IN SQUARE");
			inter->cur_q = inter->cur_obj->square;
			inter->cur_q_id = inter->cur_obj->id;
			ft_init_inter(inter);
			if ((inter->has_junc = ft_rt_inter_ray_sq(ray, &inter->cur_q, inter)))
			{
				printf("\nIAM IN SQUARE SHADOW");
				if (inter->t < inter->min_t)
					ft_rt_save_min_t_pix_int(sc, inter, opt);
			}
		}
		sc->k++;
	}
	if(inter->min_t != 1E10)
		return (1);
	return (0);
}
