/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:26:43 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/26 00:13:11 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RT_H
# define FT_RT_H

/*--------------------------------ft_rt_cam.c-----------------------------*/
void    ft_rt_cam_compute(t_scene *sc, t_cam *cam, t_ray *new_ray);

/*--------------------------------ft_rt_inter.c-----------------------------*/
int		ft_rt_inter_ray_sp(t_ray *r, t_sphere *sp, t_inter *inter);
int		ft_rt_inter_ray_tr(t_ray *r, t_triangle *tr, t_inter *inter);
int		ft_rt_inter_all(t_scene *sc, t_ray *ray, t_inter *inter, int opt);

/*--------------------------------ft_rt_set_ray.c-----------------------------*/
void	ft_ray_set(t_ray *r, t_vector *origin, t_vector *direction);
void	ft_light_set(t_light *light, t_vector *light_pos, double light_int);

/*-------------------------------ft_rt_trace_rays.c---------------------------*/
void	ft_rt_trace_rays(t_scene *sc, t_inter *inter);
void	ft_rt_select_next_sp(t_inter *inter);
void	ft_rt_save_min_t_pix_int(t_scene *sc, t_inter *inter, int opt);

int		ft_rt_inter_ray_pl(t_ray *r, t_plane *pl, t_inter *inter);

#endif
