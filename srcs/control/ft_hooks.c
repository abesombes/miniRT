/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:06:50 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/11 12:07:47 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"

int     key_hook(int keycode, void *img)
{
	if (keycode == 1)
	{
    	printf("\nYou just pressed the key 's' - we now save your current image in bitmap format.\n");
    	ft_save_to_bmp("scene_export.bmp", img, w, h);
    	printf("\nExport to scene_export.bmp done!\n");
	}
	else if (keycode == 53)
	{
		ft_close_win(img);
	}
    return (1);
}

int     mouse_hook(int mousecode, int x, int y, void *img)
{
	(void)img;
	printf("\nHello from mouse_hook! You just pressed the mouse [%i] at [%i, %i]\n", mousecode, x, y);
   // ft_save_to_bmp("scene_export.bmp", img, w, h);
    //printf("\nExport to scene_export.bmp done!\n");
	exit(0);
	return (1);
}