/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render_mlx.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 15:58:10 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/12 22:56:39 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_render.h"

void	ft_render_pixel_put(t_scene *sc, int x, int y, int color)
{
	char	*dst;

	dst = sc->addr + (y * sc->line_length + x * (sc->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}