/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_olst_add_lookup_obj.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:23:37 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/08 18:19:28 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

t_olst	*ft_olst_pushback_obj(t_olst **olst)
{
	t_olst *new_elem;
	t_olst *tmp;

	if (!(new_elem = (t_olst *)malloc(sizeof(t_olst))))
		return (NULL);
    // if (!(obj = (t_object *)malloc(sizeof(t_object))))
	// 	return (NULL);
	tmp = *olst;
	while (tmp->next)
		tmp = tmp->next;
	new_elem->next = NULL;
	tmp->next = new_elem;
    return (new_elem);
}
/*
t_scene *ft_return_last_obj(t_scene *sc)
{
	t_scene *last;

	last = sc;
	while (last->next)
		last = last->next;
	return (last);
}

t_scene *ft_sc_add_sp(t_scene *sc, int id, t_sphere *sp)
{
    t_scene *tmp;

    if (!(tmp = (t_scene *)malloc(sizeof(t_scene))))
		return (NULL);
    if (tmp)
    {
		tmp->obj_type = 's';
        tmp->sp = sp;
        tmp->id = id;
        tmp->next = sc;
    }
    return tmp;
}

t_scene *ft_sc_add_tr(t_scene *sc, int id, t_triangle *tr)
{
    t_scene *tmp;

    tmp = (t_scene *)malloc(sizeof(t_scene));
    if (tmp)
    {
		tmp->obj_type = 't';
		tmp->tr = tr;
        tmp->id = id;
        tmp->next = sc;
    }
    return tmp;
}

t_scene *ft_sc_lookup_id(t_scene *sc, int obj_id)
{
    t_scene *tmp;
    tmp = sc;
    while (tmp)
    {
        if (tmp->id == obj_id)
            return (tmp);
        tmp = tmp->next;
    }
    return (0);
}*/