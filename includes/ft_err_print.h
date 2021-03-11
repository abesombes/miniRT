/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_print.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:23:20 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/11 11:56:29 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ERR_PRINT_H
# define FT_ERR_PRINT_H

# define err_msg_missing_requirements "Error\nMissing minimum required objects in your scene file: you need a minimum of 1 Res, 1 Cam and 1 Light or Alight.\n"
# define err_msg_failed_file_closure "Error\nFile closure failed: cannot close the opened file.\n"
# define err_msg_failed_malloc "Error\nMalloc failed: cannot allocate memory.\n"
# define err_msg_wrong_fd "Error\nWrong fd: cannot open file.\n"
# define err_msg_wrong_arg_nb "Error\nWrong number of arguments.\n"
# define err_msg_invalid_empty "Error\nOne of the vectors miss a value (empty value).\n"
# define err_msg_invalid_height "Error\nThe height should be a positive value.\n"
# define err_msg_invalid_length "Error\nThe length should be a positive value.\n"
# define err_msg_invalid_fov "Error\nThe fov value is outside [0, 180].\n"
# define err_msg_invalid_radius "Error\nThe radius should be a positive value.\n"
# define err_msg_invalid_light_int "Error\nThe light ratio is outside [0, 1].\n"
# define err_msg_invalid_orient "Error\nThe orientation vector should have [x,y,z] values all within [-1, 1] range.\n"
# define err_msg_twice_alight "Error\nThe .rt scene file contains twice an Ambiant Light definition.\n"
# define err_msg_invalid_rgb "Error\nSome rgb value is outside [0, 255].\n"
# define err_msg_invalid_alight "Error\nThe ambiant light ratio is outside [0, 1].\n"
# define err_msg_invalid_file_content "Error\nThe scene file has invalid content.\n"
# define err_msg_dir_not_file "Error\nThe path provided for the scene file is a directory, not a .rt file.\n"
# define err_msg_invalid_file_format "Error\nThe scene file should have a filename extension '.rt'.\n"
# define err_msg_twice_res "Error\nThe .rt scene file contains twice a Resolution definition.\n"
# define err_msg_invalid_res_render_size "Error\nResolution Render Size x and y should be > 0.\n"

int ft_err_print(int error_num);
int ft_err_print_2(int error_num);

#endif