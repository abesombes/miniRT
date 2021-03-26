/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hooks.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:06:50 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/26 11:11:58 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_export.h"
#include "../../includes/ft_olst.h"
#include "../../includes/ft_rt.h"

int	ft_key_hook(int keycode, t_scene *sc)
{
	//(void)sc;
	t_inter		inter;
	printf("\nkeycode pressed: [%i]", keycode);
	if (keycode == 53)
		ft_close_win(sc->img);
	if (keycode == 45)
	{
		sc->change_cam = 1;
		printf("\nres: [%i, %i]", sc->res_w, sc->res_h);
		printf("\ncur_cam before change in key_hook: [%i]", sc->cur_cam);
//		printf("\nCount Cams: [%i]", ft_olst_count_obj_by_obj_type(&sc->olst, 'm'));
		sc->cur_cam = ft_olst_return_next_obj_id_by_type(&sc->olst, sc->cur_cam, 'm');
		printf("\ncur_cam after change in key_hook: [%i]", sc->cur_cam);
	//	mlx_clear_window(&sc->mlx, &sc->mlx_win);
		ft_rt_trace_rays(sc, &inter);
	}
	return (1);
}