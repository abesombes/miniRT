/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_bmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:01:49 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/25 15:59:48 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_export.h"

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}
/*
void    ft_write_file_header(int fd, int w, int h)
{
    int             i;
    unsigned char   bmp_file_header[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 54, 0, 0, 0};
    int             filesize;

    i = 0;
    filesize = 54 + 3 * w * h;
    bmp_file_header[2] = (unsigned char)(filesize);
    bmp_file_header[3] = (unsigned char)(filesize >> 8);
    bmp_file_header[4] = (unsigned char)(filesize >> 16);
    bmp_file_header[5] = (unsigned char)(filesize >> 24);
    while (i < 14)
        ft_putchar_fd(bmp_file_header[i++], fd);
}

void    ft_write_info_header(int fd, int w, int h)
{
    unsigned char   bmp_info_header[40] = {40, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
    int             i;

    i = 0;
    bmp_info_header[4] = (unsigned char)(w);
    bmp_info_header[5] = (unsigned char)(w >> 8);
    bmp_info_header[6] = (unsigned char)(w >> 16);
    bmp_info_header[7] = (unsigned char)(w >> 24);
    bmp_info_header[8] = (unsigned char)(h);
    bmp_info_header[9] = (unsigned char)(h >> 8);
    bmp_info_header[10] = (unsigned char)(h >> 16);
    bmp_info_header[11] = (unsigned char)(h >> 24);
    while (i < 40)
        ft_putchar_fd(bmp_info_header[i++], fd);
}

void    ft_write_pixels(int fd, int w, int h, unsigned char *pixels)
{
    int             i;
    unsigned char   bgr_pixels[w * h * 3];

    i = 0;
    while (i < w * h)
    {
        bgr_pixels[i * 3] = pixels[i * 4];
        bgr_pixels[i * 3 + 1] = pixels[i * 4 + 1];
        bgr_pixels[i * 3 + 2] = pixels[i * 4 + 2];
        i++;
    }
    write(fd, bgr_pixels, 3 * w * h);
}/*
/*
void    ft_write_pixels(int fd, int w, int h, unsigned char *pixels)
{
    int             x;
    int             y;
    int             i;
    unsigned char   bgr_pixels[w * h * 3];

    i = 0;
    y = h;
    while (y-- > 0)
    {
        x = 0;
        while (x < w)
        {
            bgr_pixels[i * 3 + 0] = pixels[(x + y * w) * 4 + 0];
            bgr_pixels[i * 3 + 1] = pixels[(x + y * w) * 4 + 1];
            bgr_pixels[i * 3 + 2] = pixels[(x + y * w) * 4 + 2];
            i++;
            x++;
        }
    }
    write(fd, bgr_pixels, w * h * 3);
}*/

void    ft_write_file_header(int fd, int w, int h)
{
    int             i;
    unsigned char   bmp_file_header[14] = {'B', 'M', 0, 0, 0, 0, 0, 0, 0, 0, 70, 0, 0, 0};
    int             filesize;

    i = 0;
    filesize = 54 + 3 * w * h;
    bmp_file_header[2] = (unsigned char)(filesize);
    bmp_file_header[3] = (unsigned char)(filesize >> 8);
    bmp_file_header[4] = (unsigned char)(filesize >> 16);
    bmp_file_header[5] = (unsigned char)(filesize >> 24);
    while (i < 14)
        ft_putchar_fd(bmp_file_header[i++], fd);
}

void    ft_write_info_header(int fd, int w, int h)
{
    /*unsigned char   bmp_info_header[56] = {56, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 24, 0};
    int             i;

    i = 0;
    bmp_info_header[4] = (unsigned char)(w);
    bmp_info_header[5] = (unsigned char)(w >> 8);
    bmp_info_header[6] = (unsigned char)(w >> 16);
    bmp_info_header[7] = (unsigned char)(w >> 24);
    bmp_info_header[8] = (unsigned char)(h);
    bmp_info_header[9] = (unsigned char)(h >> 8);
    bmp_info_header[10] = (unsigned char)(h >> 16);
    bmp_info_header[11] = (unsigned char)(h >> 24);*/
    unsigned int	dib[15];
    int             i;
    int             j;
    
	dib[0] = 56;
	dib[1] = w;
	dib[2] = h;
	dib[3] = (32u << 16u) | 1u;
	dib[4] = 0;
	dib[5] = w * h * 4;
	dib[6] = 3800;
	dib[7] = 3800;
	dib[8] = 0;
	dib[9] = 0;
	dib[10] = 0x00FF0000;
	dib[11] = 0x0000FF00;
	dib[12] = 0x000000FF;
	dib[13] = 0xFF000000;
    i = 0;
    while (i < 14)
    {
        j = 0;    
        while (j < 4)
            ft_putchar_fd(dib[i][j++], fd);
        i++;
    }
}

void    ft_write_pixels(int fd, int w, int h, unsigned char *pixels)
{
    int             i;
    unsigned char   bgr_pixels[w * h * 4];

    i = 0;
    while (i < w * h)
    {
        bgr_pixels[i * 3] = pixels[i * 4];
        bgr_pixels[i * 3 + 1] = pixels[i * 4 + 1];
        bgr_pixels[i * 3 + 2] = pixels[i * 4 + 2];
        bgr_pixels[i * 3 + 3] = 0;
        i++;
    }
    write(fd, bgr_pixels, 3 * w * h);
}

void    ft_save_to_bmp(const char *filename, unsigned char *pixels, int w, int h)
{
    int             fd;

    (void)pixels;
    fd = open(filename, O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);
    if (fd != -1)
    {
        ft_write_file_header(fd, w, h);
        ft_write_info_header(fd, w, h);
        ft_write_pixels(fd, w, h, pixels);
        close (fd);
    }
}