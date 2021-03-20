/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_bmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:01:49 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/20 11:35:19 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_export.h"
#include "../../includes/ft_err_print.h"

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

void    ft_write_file_header(int fd, t_scene *sc)
{
    int             i;
    unsigned char   bmp_file_header[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    int             filesize;

    i = 0;
    filesize = 54 + sc->res_h * sc->res_w * 3;
    bmp_file_header[2] = (unsigned char)(filesize);
    bmp_file_header[3] = (unsigned char)(filesize >> 8);
    bmp_file_header[4] = (unsigned char)(filesize >> 16);
    bmp_file_header[5] = (unsigned char)(filesize >> 24);
    while (i < 14)
        ft_putchar_fd(bmp_file_header[i++], fd);
}

void    ft_write_info_header(int fd, t_scene *sc)
{
	unsigned char	bmp_info_header[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
	int				i;

    i = 0;
    bmp_info_header[4] = (unsigned char)(sc->res_w);
    bmp_info_header[5] = (unsigned char)(sc->res_w >> 8);
    bmp_info_header[6] = (unsigned char)(sc->res_w >> 16);
    bmp_info_header[7] = (unsigned char)(sc->res_w >> 24);
    bmp_info_header[8] = (unsigned char)(sc->res_h);
    bmp_info_header[9] = (unsigned char)(sc->res_h >> 8);
    bmp_info_header[10] = (unsigned char)(sc->res_h >> 16);
    bmp_info_header[11] = (unsigned char)(sc->res_h >> 24);
	while (i < 40)
        ft_putchar_fd(bmp_info_header[i++], fd);
}


void    ft_write_pixels(int fd, t_scene *sc, unsigned char *pixels)
{
    int             i;
    unsigned char   bgr_pixels[sc->res_w * sc->res_h * 3];
  	unsigned char   bmp_pad[3] = {0, 0, 0};

    i = 0;
/*
	i = sc->res_h;
	while(--i+ 1)
		write(fd, pixels + sc->res_w * i * 4, sc->res_w * 4);*/
	
	
    while (i < sc->res_w * sc->res_h)
    {
        bgr_pixels[i * 3] = pixels[i * 4];
        bgr_pixels[i * 3 + 1] = pixels[i * 4 + 1];
        bgr_pixels[i * 3 + 2] = pixels[i * 4 + 2];
        i++;
    }
    i = 0;
    while (i < sc->res_h)
    {
        write(fd, &bgr_pixels[0] + (sc->res_w * (sc->res_h - i - 1) * 3), 3 * sc->res_w);
        write(fd, bmp_pad, (4 - (sc->res_w * 3) % 4) % 4);
		i++;
	}	
}

void    ft_save_to_bmp(const char *filename, unsigned char *pixels, t_scene *sc)
{
	int	fd;

    (void)pixels;
    fd = open(filename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd != -1)
    {
        ft_write_file_header(fd, sc);
        ft_write_info_header(fd, sc);
        ft_write_pixels(fd, sc, pixels);
        close (fd);
    }
	else
		ft_err_print(-21);
}