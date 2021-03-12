/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_olst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:24:01 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/12 22:05:55 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OLST_H
# define FT_OLST_H

/*-----------------ft_olst_add_lookup_obj.c----------------*/
t_olst	*ft_olst_pushback_obj(t_olst **olst, char obj_type, int *obj_id);
int     ft_olst_count_obj_by_obj_type(t_olst **olst, char obj_type);
t_olst *ft_olst_return_obj_by_id(t_olst **olst, int obj_id);
t_olst  *ft_olst_return_first_obj_by_type(t_olst **olst, int obj_type);
int ft_olst_return_first_obj_id_by_type(t_olst **olst, int obj_type);

#endif