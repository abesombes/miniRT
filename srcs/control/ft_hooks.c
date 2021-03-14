/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:06:50 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/14 17:28:45 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_export.h"

int	ft_key_hook(int keycode, void *img, t_scene *sc)
{
	(void)sc;
	if (keycode == 53)
		ft_close_win(img);
	return (1);
}