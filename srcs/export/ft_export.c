/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 23:31:26 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/25 23:51:30 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_export.h"
#include "../../includes/ft_err_print.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;

	if (!dst || !src)
		return (NULL);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n-- > 0)
		*d++ = *s++;
	return (dst);
}

unsigned char	*file_header_bmp(int filesize)
{
	unsigned char	*bmpfileheader;

	if(!(bmpfileheader = (unsigned char*) malloc(14 * sizeof(unsigned char))))
		ft_err_print(-12);
	ft_memcpy(bmpfileheader, (char[]){'B','M', 0,0,0,0, 0,0, 0,0, 54,0,0,0}, 14);
	bmpfileheader[2] = (unsigned char)(filesize);
	bmpfileheader[3] = (unsigned char)(filesize >> 8);
	bmpfileheader[4] = (unsigned char)(filesize >> 16);
	bmpfileheader[5] = (unsigned char)(filesize >> 24);
	return (bmpfileheader);
}

unsigned char	*info_header_bmp(t_scene *sc)
{
	unsigned char	*bmpinfoheader;

	if(!(bmpinfoheader = (unsigned char*) malloc(40 * sizeof(unsigned char))))
	ft_err_print(-12);
	ft_memcpy(bmpinfoheader, (char[]){40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0, 32,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0, 0,0,0,0}, 40);
	bmpinfoheader[4] = (unsigned char)(sc->res_w);
	bmpinfoheader[5] = (unsigned char)(sc->res_w >> 8);
	bmpinfoheader[6] = (unsigned char)(sc->res_w >> 16);
	bmpinfoheader[7] = (unsigned char)(sc->res_w >> 24);
	bmpinfoheader[8] = (unsigned char)(sc->res_h);
	bmpinfoheader[9] = (unsigned char)(sc->res_h >> 8);
	bmpinfoheader[10] = (unsigned char)(sc->res_h >> 16);
	bmpinfoheader[11] = (unsigned char)(sc->res_h >> 24);
	return (bmpinfoheader);
}

void			write_data(int f, const unsigned char *data, t_scene *sc, const int filesize)
{
	int 			line;

	(void)filesize;
	line = sc->res_h;
	while(--line + 1)
		write(f, data + sc->res_w * line * 4, sc->res_w * 4);
}

void	save_bmp(const char *filename, const unsigned char *data, t_scene *sc)
{
	int				filesize;
	int				f;
	unsigned char	*bmpfileheader;
	unsigned char	*bmpinfoheader;

	filesize = 14 + 40 + 3 * sc->res_w * sc->res_h;
	f = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_APPEND, 0755);
	bmpfileheader = file_header_bmp(filesize);
	write(f, bmpfileheader, 14);
	free(bmpfileheader);
	bmpinfoheader = info_header_bmp(sc);
	write(f, bmpinfoheader, 40);
	free(bmpinfoheader);
	write_data(f, data, sc, filesize);
	close(f);
}