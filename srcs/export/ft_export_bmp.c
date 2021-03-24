/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_bmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:01:49 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/11 12:02:23 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_export.h"

void    ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

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
    unsigned char   bmp_pad[3] = {0, 0, 0};

    i = 0;
    while (i < w * h)
    {
        bgr_pixels[i * 3] = pixels[i * 4];
        bgr_pixels[i * 3 + 1] = pixels[i * 4 + 1];
        bgr_pixels[i * 3 + 2] = pixels[i * 4 + 2];
        i++;
    }
    i = 0;
    while (i < h)
    {
        write(fd, &bgr_pixels[0] + (w*(h - i - 1) * 3), 3 * w);
        write(fd, bmp_pad, (4 - (w * 3) % 4) % 4);
        i++;
    }
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