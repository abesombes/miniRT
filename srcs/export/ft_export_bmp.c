/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export_bmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:01:49 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/25 23:11:17 by abesombe         ###   ########.fr       */
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
}*/
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
/*
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
    unsigned char   bmp_info_header[56] = {0};
    int             *bmp_info_header_int;
    int             i;
    
    bmp_info_header_int = (int *)&bmp_info_header[0];
	bmp_info_header_int[0] = 56;
	bmp_info_header_int[1] = w;
	bmp_info_header_int[2] = h;
	bmp_info_header_int[3] = (32u << 16u) | 1u;
	bmp_info_header_int[4] = 0;
	bmp_info_header_int[5] = w * h * 4;
	bmp_info_header_int[6] = 3800;
	bmp_info_header_int[7] = 3800;
	bmp_info_header_int[8] = 0;
	bmp_info_header_int[9] = 0;
	bmp_info_header_int[10] = 0x00FF0000;
	bmp_info_header_int[11] = 0x0000FF00;
	bmp_info_header_int[12] = 0x000000FF;
	bmp_info_header_int[13] = 0xFF000000;
    
	bmp_file_header_int[1] = w;
    bmp_info_header[8] = (unsigned char)(h >> 0);
	bmp_info_header[9] = (unsigned char)(h >> 8);
	bmp_info_header[10] = (unsigned char)(h >> 16);
	bmp_info_header[11] = (unsigned char)(h >> 24);
	bmp_info_header[12] = 32;
	bmp_info_header[16] = 0;
	bmp_info_header[20] = (unsigned char)((w * h * 4) >> 0);
	bmp_info_header[21] = (unsigned char)((w * h * 4) >> 8);
	bmp_info_header[22] = (unsigned char)((w * h * 4) >> 16);
	bmp_info_header[23] = (unsigned char)((w * h * 4) >> 24);
	bmp_info_header[24] = (unsigned char)(3800 >> 0);
	bmp_info_header[25] = (unsigned char)(3800 >> 8);
	bmp_info_header[26] = (unsigned char)(3800 >> 16);
	bmp_info_header[27] = (unsigned char)(3800 >> 24);
	bmp_info_header[28] = (unsigned char)(3800 >> 0);
	bmp_info_header[29] = (unsigned char)(3800 >> 8);
	bmp_info_header[30] = (unsigned char)(3800 >> 16);
	bmp_info_header[31] = (unsigned char)(3800 >> 24);
	bmp_info_header[40] = (unsigned char)(0x00FF0000 >> 0);
	bmp_info_header[41] = (unsigned char)(0x00FF0000 >> 8);
	bmp_info_header[42] = (unsigned char)(0x00FF0000 >> 16);
	bmp_info_header[43] = (unsigned char)(0x00FF0000 >> 24);
    bmp_info_header[44] = (unsigned char)(0x0000FF00 >> 0);
	bmp_info_header[45] = (unsigned char)(0x0000FF00 >> 8);
	bmp_info_header[46] = (unsigned char)(0x0000FF00 >> 16);
	bmp_info_header[47] = (unsigned char)(0x0000FF00 >> 24);
    bmp_info_header[48] = (unsigned char)(0x000000FF >> 0);
	bmp_info_header[49] = (unsigned char)(0x000000FF >> 8);
	bmp_info_header[50] = (unsigned char)(0x000000FF >> 16);
	bmp_info_header[51] = (unsigned char)(0x000000FF >> 24);
    bmp_info_header[52] = (unsigned char)(0xFF000000 >> 0);
	bmp_info_header[53] = (unsigned char)(0xFF000000 >> 8);
	bmp_info_header[54] = (unsigned char)(0xFF000000 >> 16);
	bmp_info_header[55] = (unsigned char)(0xFF000000 >> 24);*/
   /* i = 0;
    while (i < 56)
    {
        ft_putchar_fd((unsigned char)(bmp_info_header[i]), fd);
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
        bgr_pixels[i * 4] = pixels[i * 4];
        bgr_pixels[i * 4 + 1] = pixels[i * 4 + 1];
        bgr_pixels[i * 4 + 2] = pixels[i * 4 + 2];
        bgr_pixels[i * 4 + 3] = 0;
        i++;
    }
    write(fd, bgr_pixels, 4 * w * h);
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
}*/

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
        write(1, bmp_pad, (4 - (w * 3) % 4) % 4);
//		write(1, "\n", 1);
		// write(fd, bmp_pad, (4 - (w * 3) % 4) % 4);
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