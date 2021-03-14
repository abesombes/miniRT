/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 22:31:22 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/14 18:09:53 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include "../minilibx_mms/mlx.h"
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
	t_vector	pos;
	double		intst;
}				t_light;

typedef	struct	s_cam
{
	t_vector	pos;
	t_vector	orient;
	double		fov;
}				t_cam;

typedef	struct	s_alight
{
	double		intst;
}				t_alight;

typedef struct  s_ray {
	t_vector    orig;
	t_vector    dir;
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
	t_vector	orig;
	double		radius;
}				t_sphere;

typedef struct	s_olst t_olst;
struct s_olst
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
	t_olst		*next;
};

typedef struct	s_inter
{
	int has_junc;
	double a;
	double b;
	double c;
	double delta;
	double t;
	double t1;
	double t2;
	double min_t;
	t_vector p;
	t_vector n;
	t_cam cur_c;
	t_light cur_l;
	t_sphere cur_s;
	int cur_s_id;
	t_olst *sp_obj;
	int count_sp;
}				t_inter;

typedef struct	s_scene
{
	int			i;
	int			j;
	int 		k;
	void		*mlx;
	void		*mlx_win;
	void        *img;
	char        *addr;
	int         bits_per_pixel;
	int         line_length;
	int         endian;
	int			res_w;
	int 		res_h;
	int			scr_w;
	int 		scr_h;
	int			cur_cam;
	t_vector	pix_int;
	int			pix_color;
	t_ray		ray;
	t_ray		ray_light;
	t_olst     	*olst;
}				t_scene;

/*--------------------------------init/ft_init.c-----------------------------*/
int 		ft_init_sc(t_scene *sc);
void 		ft_init_inter(t_inter *inter);

void		ft_print_olst(t_scene *sc);
int 		ft_control_args_file(int ac, char **av);
t_vector 	*ft_vec(double x, double y, double z);
void		ft_display_vec(t_vector *v);
int			ft_close_win(char *p);
int			ft_key_hook(int keycode, void *img, t_scene *sc);
int			ft_strcmp(const char *s1, const char *s2);

#endif