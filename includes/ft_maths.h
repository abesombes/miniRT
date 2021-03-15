/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:37:19 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/15 10:57:30 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATHS_H
# define FT_MATHS_H

/*-----------------ft_maths_arr_val_in_range.c----------------*/
int			ft_maths_arr_val_in_range(double *arr, double min_b, double max_b);
int			ft_within_range(double nb, double min_b, double max_b);

/*-----------------ft_maths_vec_calc.c------------------------*/
t_vector	*ft_vec_add(t_vector *u, t_vector *v);
t_vector	*ft_vec_sub(t_vector *u, t_vector *v);
t_vector	*ft_vec_cross(t_vector *u, t_vector *v);
t_vector	*ft_vec_mul_vec(t_vector *u, t_vector *v);
t_vector	*ft_vec_div(t_vector *u, t_vector *v);
void		ft_vec_a(t_vector *w, t_vector *u, t_vector *v);
void		ft_vec_s(t_vector *w, t_vector *u, t_vector *v);

/*-----------------ft_maths_vec_norm.c------------------------*/
double		ft_vec_sqnorm(t_vector *v);
t_vector	*ft_vec_normvec(t_vector *v);
void		ft_vec_norm(t_vector *v);
void		ft_vec_nv(t_vector *w, t_vector *v);

/*-----------------ft_maths_vec_scal_calc.c-------------------*/
t_vector	*ft_vec_div_scal(t_vector *u, double a);
t_vector	*ft_vec_mul_scal(t_vector *u, double a);
double		ft_vec_mul(t_vector *u, t_vector *v);
void		ft_vec_ms(t_vector *w, t_vector *u, double a);

/*-----------------ft_maths_vec.c-----------------------------*/
void		ft_vec_set(t_vector *v, double x, double y, double z);
void		ft_vec_nul(t_vector *v);
t_vector	*ft_vec(double x, double y, double z);
t_vector	*ft_vec_dup(t_vector *v);
void		ft_vec_cpy(t_vector *vec1, t_vector *vec2);

void    ft_sp_cpy(t_sphere *sp1, t_sphere *sp2);

#endif