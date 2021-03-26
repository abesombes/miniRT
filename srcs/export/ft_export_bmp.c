/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_bmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:01:49 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/26 22:35:32 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_export.h"
#include "../../includes/ft_err_print.h"

static void     create_header(int fd, int pad, t_scene *sc)
{
    unsigned char   headerfile[54]={0};
    int             bmpsize;

    (void)pad;
    bmpsize = 54 + (3 * (sc->res_w + pad) * sc->res_h);
    headerfile[0] = (unsigned char)('B');
    headerfile[1] = (unsigned char)('M');
    headerfile[2] = (unsigned char)bmpsize;
    headerfile[3] = (unsigned char)(bmpsize >> 8);
    headerfile[4] = (unsigned char)(bmpsize >> 16);
    headerfile[5] = (unsigned char)(bmpsize >> 24);
    headerfile[10] = (unsigned char)(54);
    headerfile[14] = (unsigned char)(40);
    headerfile[18] = (unsigned char)sc->res_w;
    headerfile[19] = (unsigned char)(sc->res_w >> 8);
    headerfile[20] = (unsigned char)(sc->res_w >> 16);
    headerfile[21] = (unsigned char)(sc->res_w >> 24);
    headerfile[22] = (unsigned char)sc->res_h;
    headerfile[23] = (unsigned char)(sc->res_h >> 8);
    headerfile[24] = (unsigned char)(sc->res_h >> 16);
    headerfile[25] = (unsigned char)(sc->res_h >> 24);
    headerfile[26] = (unsigned char)(1);
    headerfile[28] = (unsigned char)(24);
    write(fd, headerfile, 54);
}

static int      copy_pixels(t_scene *sc, int fd, int pad)
{
    unsigned int    zero[3];
    int             x;
    int             y;
    y = sc->res_h - 1;
    zero[0]= '\0';
    zero[1]= '\0';
    zero[2]= '\0';
    while (y >= 0)
    {
        x = 0;
        while (x < sc->res_w)
        {
            write(fd, &sc->addr[(y * sc->line_length + x * (sc->bits_per_pixel / 8))], 3);
            x++;
        }
        if (pad > 0 && write(fd, &zero, pad) < 0)
            return (-1);
        y--;
    }
    return (0);
}

int	ft_export_save_img_bmp(t_scene *sc)
{
    int pad;
    int fd;

    pad = (4 - ((int)sc->res_w * 3) % 4) % 4;
    fd = open("scene_export.bmp", O_WRONLY | O_CREAT, 0777 | O_TRUNC | O_APPEND);
    create_header(fd, pad, sc);
    copy_pixels(sc, fd, pad);
    return (0);
}