/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rt.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:26:43 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/11 15:54:05 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RT_H
# define FT_RT_H

/*--------------------------------ft_rt_set_ray.c-----------------------------*/
void    ft_set_ray(t_ray *r, t_vector *origin, t_vector *direction);
void	ft_set_light(t_light *light, t_vector *light_pos, double light_int);

/*-------------------------------ft_rt_trace_rays.c---------------------------*/
void    ft_rt_trace_rays(t_scene *sc);

#endif
