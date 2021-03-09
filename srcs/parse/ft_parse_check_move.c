/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_check_move.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 14:56:15 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/09 16:12:20 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_parse.h"

void	ft_move_to_next_data(char **line)
{
	while (**line && (**line == ' ' || **line == '\t'))
		(*line)++;
}

int	ft_check_if_space_tab_only(char **line)
{
	while (**line && (**line == ' ' || **line == '\t'))
		(*line)++;
	if (!**line)
		return (1);
	return (0);
}