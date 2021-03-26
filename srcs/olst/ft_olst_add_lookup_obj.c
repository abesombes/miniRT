/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_olst_add_lookup_obj.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 15:23:37 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/26 10:54:01 by abesombe         ###   ########.fr       */
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

int ft_olst_count_obj_by_obj_group_type(t_olst **olst, char *obj_type)
{
	int count;
	int i;
	t_olst *tmp = NULL;
	
	count = 0;
	tmp = *olst;
	while (tmp)
	{
		i = -1;
		while (obj_type[++i])
			if (tmp->obj_type == obj_type[i])
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

t_olst *ft_olst_return_next_obj(t_olst **olst, int min_i, char otype)
{
	t_olst *tmp;
	
	tmp = *olst;
	while (tmp && (tmp->id <= min_i || tmp->obj_type != otype))
		tmp = tmp->next;
	if (tmp && tmp->obj_type > min_i)
		return (tmp);
	return (NULL);
}

int ft_is_char_within_str(char *str, char c)
{
	int i;
	
	i = -1;
	while (str && str[++i])
		if (str[i] == c)
			return (1);
	return (0);
}

t_olst *ft_olst_return_next_obj_from_group(t_olst **olst, int min_i, char *otype)
{
	t_olst *tmp;
	
	tmp = *olst;
	while (tmp && (tmp->id <= min_i || !ft_is_char_within_str(otype, tmp->obj_type)))
		tmp = tmp->next;
	if (tmp && tmp->obj_type > min_i && ft_is_char_within_str(otype, tmp->obj_type))
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

int ft_olst_return_next_obj_id_by_type(t_olst **olst, int obj_id, char otype)
{
	t_olst	*tmp;
	int		count;
	
	count = ft_olst_count_obj_by_obj_type(olst, otype);
	if (count == 1)
		return (obj_id);
	tmp = *olst;
	while (tmp)
	{
		printf("\nobj_type: [%c]- obj_id: [%i]", tmp->obj_type, tmp->id);
		if (tmp->obj_type == otype && tmp->id > obj_id)
			break ;
		tmp = tmp->next;
	}
	if (tmp && tmp->obj_type == otype && tmp->id > obj_id)
		return (tmp->id);
	return (ft_olst_return_first_obj_id_by_type(olst, otype));
}
/*
int ft_olst_return_previous_obj_id_by_type(t_olst **olst, int obj_id, char otype)
{
	t_olst *tmp;
	
	tmp = *olst;
	while (tmp && (tmp->obj_type != otype || 
		tmp = tmp->next;
	if (tmp->obj_type == otype)
		return (tmp->id);
	return (-1);
}
*/