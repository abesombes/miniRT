/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:31:22 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/08 01:27:53 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <mlx.h>
# define _USE_MATH_DEFINES
# include <math.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <time.h>

typedef struct  s_vector {
	double     x;
	double     y;
	double     z;
}               t_vector;

typedef	struct	s_light
{
	t_vector	light_pos;
	double		light_int;
}				t_light;

typedef	struct	s_cam
{
	t_vector	pos;
	t_vector	orient;
	double		fov;
}				t_cam;

typedef	struct	s_alight
{
	double		alight_int;
}				t_alight;

typedef struct  s_data {
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
}               t_data;

typedef struct  s_ray {
	t_vector    origin;
	t_vector    direction;
}               t_ray;

typedef struct s_triangle {
	t_vector	a;
	t_vector	b;
	t_vector	c;
}				t_triangle;

typedef struct s_plane {
	t_vector	u;
	t_vector	v;
}				t_plane;

typedef struct s_square {
	t_vector	u;
	t_vector	v;
	double		l;
}				t_square;

typedef struct s_cylinder {
	t_vector	u;
	t_vector	v;
	double		radius;
	double		height;
}				t_cylinder;

typedef struct	s_sp {
	t_vector	origin;
	double		radius;
}				t_sphere;

typedef struct	s_object t_object;

struct  s_object
{
	char		obj_type;
	int         id;
	t_sphere    sp;
	t_triangle	tr;
	t_plane		plane;
	t_square	square;
	t_light		light;
	t_alight	alight;
	t_cylinder	cylinder;
	t_cam		cam;
	t_vector	rgb;
	t_object     *next;
};

typedef t_object *t_olst;

typedef struct	s_scene
{
	void		*mlx;
	void		*mlx_win;
	t_data		data;
	int			res_w;
	int 		res_h;
	t_olst     	olst;
}				t_scene;

int ft_init_sc(t_scene *sc);

#endif