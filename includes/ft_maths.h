/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_maths.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 14:37:19 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/11 15:15:59 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATHS_H
# define FT_MATHS_H

/*-----------------ft_maths_arr_val_in_range.c----------------*/
int	        ft_maths_arr_val_in_range(double *arr, double min_b, double max_b);
int	        ft_within_range(double nb, double min_b, double max_b);

/*-----------------ft_maths_vec_calc.c------------------------*/
t_vector    *ft_add_vec(t_vector *u, t_vector *v);
t_vector    *ft_sub_vec(t_vector *u, t_vector *v);
t_vector    *ft_cross_vec(t_vector *u, t_vector *v);
t_vector    *ft_mul_vec_vec(t_vector *u, t_vector *v);
t_vector    *ft_div_vec(t_vector *u, t_vector *v);

/*-----------------ft_maths_vec_norm.c------------------------*/
double  ft_get_sqnorm(t_vector *v);
t_vector *ft_get_normvec(t_vector *v);
void    ft_norm_vec(t_vector *v);

/*-----------------ft_maths_vec_scal_calc.c-------------------*/
t_vector *ft_div_vec_scal(t_vector *u, double a);
t_vector *ft_mul_vec_scal(t_vector *u, double a);
double ft_mul_vec(t_vector *u, t_vector *v);

/*-----------------ft_maths_vec.c-----------------------------*/
void        ft_set_vec(t_vector *v, double x, double y, double z);
t_vector    *ft_vec(double x, double y, double z);
t_vector    *ft_dup_vec(t_vector *v);


#endif