/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 12:26:41 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/13 22:11:42 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PARSE_H
# define FT_PARSE_H

/*-----------------------------ft_parse_check_move.c--------------------------*/
void	ft_move_to_next_data(char **line);
int		ft_check_if_space_tab_only(char **line);

/*-----------------------------ft_parse_custom_atoi.c-------------------------*/
int		ft_atoi(char **str, int *nb_digits);
double	ft_atoif(char **str, int *nb_digits);

/*----------------------ft_parse_cylidr_pln_sphr_sqr_triang.c-----------------*/
int		ft_parse_cylinder(char *line, t_scene *sc, int err_code, int *obj_id);
int		ft_parse_plane(char *line, t_scene *sc, int *obj_id);
int		ft_parse_sphere(char *line, t_scene *sc, int *obj_id);
int		ft_parse_square(char *line, t_scene *sc, int *obj_id);
int		ft_parse_triangle(char *line, t_scene *sc, int *obj_id);

/*------------------------ft_parse_fd_line_by_line.c--------------------------*/
int		ft_parse_fd_line_by_line(int fd, t_scene *sc);

/*------------------------ft_parse_open_rt_file.c-----------------------------*/
int		ft_parse_control_min_requirements(t_scene *sc);
int		ft_parse_open_rt_file(char *av, t_scene *sc);

/*------------------------ft_parse_line_by_obj_type.c-------------------------*/
int		ft_parse_line_by_obj_type(char *line, t_scene *sc, int *obj_id);

/*------------------------ft_parse_res_cam_alight_light.c---------------------*/
int		ft_parse_res(char *line, t_scene *sc);
int		ft_parse_cam(char *line, t_scene *sc, int *obj_id);
int		ft_parse_alight(char *line, t_scene *sc, int *obj_id);
int		ft_parse_light(char *line, t_scene *sc, int *obj_id);

/*---------------------------ft_parse_get_xyz_rgb.c---------------------------*/
void	ft_get_rgb(char **line, t_olst *olst, int *err_code);
void	ft_get_xyz(char **line, t_vector *vec, double *bounds, int *err_code);


#endif