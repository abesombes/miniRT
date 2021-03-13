/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_olst_add_lookup_obj.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:23:37 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/13 21:40:44 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_olst.h"

t_olst	*ft_olst_pushback_obj(t_olst **olst, char obj_type, int *obj_id)
{
	t_olst *new_elem;
	t_olst *tmp;

	if (!(new_elem = (t_olst *)malloc(sizeof(t_olst))))
		return (NULL);
	new_elem->id = *obj_id;
	new_elem->next = NULL;
	if (!(*olst))
		*olst = new_elem;
	else
	{
		tmp = *olst;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new_elem;
	}
	new_elem->obj_type = obj_type;
	return (new_elem);
}

int ft_olst_count_obj_by_obj_type(t_olst **olst, char obj_type)
{
	int count;
	t_olst *tmp = NULL;
	
	count = 0;
	tmp = *olst;
	while (tmp)
	{
	//	printf("\nObject Type Detected: [%c]\n", tmp->obj.obj_type);
		if (tmp->obj_type == obj_type)
			count++;
		tmp = tmp->next;
	}
	return (count);
}

t_olst *ft_olst_return_obj_by_id(t_olst **olst, int obj_id)
{
	t_olst *tmp;
	
	tmp = *olst;
	while (tmp && tmp->id != obj_id)
		tmp = tmp->next;
	if (tmp->id == obj_id)
		return (tmp);
	return (NULL);
}

t_olst *ft_olst_return_first_obj_by_type(t_olst **olst, char otype)
{
	t_olst *tmp;
	
	tmp = *olst;
	while (tmp && tmp->obj_type != otype)
		tmp = tmp->next;
	if (tmp->obj_type == otype)
		return (tmp);
	return (NULL);
}

int ft_olst_return_first_obj_id_by_type(t_olst **olst, char otype)
{
	t_olst *tmp;
	
	tmp = *olst;
	while (tmp && tmp->obj_type != otype)
		tmp = tmp->next;
	if (tmp->obj_type == otype)
		return (tmp->id);
	return (-1);
}