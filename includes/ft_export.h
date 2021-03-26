/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/11 12:02:37 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/25 23:50:33 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_EXPORT_H
# define FT_EXPORT_H

/*-----------------ft_export_bmp.c----------------*/
void    ft_putchar_fd(char c, int fd);
void    ft_write_file_header(int fd, int w, int h);
void    ft_write_info_header(int fd, int w, int h);
void    ft_write_pixels(int fd, int w, int h, unsigned char *pixels);
void    ft_save_to_bmp(const char *filename, unsigned char *pixels, int w, int h);

unsigned char	*file_header_bmp(int filesize);
void	*ft_memcpy(void *dst, const void *src, size_t n);
unsigned char	*info_header_bmp(t_scene *sc);
void			write_data(int f, const unsigned char *data, t_scene *sc, const int filesize);
void	save_bmp(const char *filename, const unsigned char *data, t_scene *sc);

#endif