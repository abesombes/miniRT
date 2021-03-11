/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:06:50 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/11 14:30:58 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_export.h"

int     ft_key_hook(int keycode, void *img, t_scene *sc)
{
	if (keycode == 1)
	{
    	printf("\nYou just pressed the key 's' - we now save your current image in bitmap format.\n");
    	ft_save_to_bmp("scene_export.bmp", img, sc->res_w, sc->res_h);
    	printf("\nExport to scene_export.bmp done!\n");
	}
	else if (keycode == 53)
	{
		ft_close_win(img);
	}
    return (1);
}