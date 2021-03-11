/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_olst.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:24:01 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/11 15:31:17 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_OLST_H
# define FT_OLST_H

/*-----------------ft_olst_add_lookup_obj.c----------------*/
t_olst	*ft_olst_pushback_obj(t_olst **olst, char obj_type);
int     ft_olst_count_obj_by_obj_type(t_olst **olst, char obj_type);

#endif