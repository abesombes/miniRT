/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 10:17:44 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/11 10:37:57 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_err_print.h"

int ft_err_print_2(int error_num)
{
	if (error_num == -9)
		printf(err_msg_twice_alight);
	if (error_num == -8)
		printf(err_msg_invalid_rgb);
	if (error_num == -7)
		printf(err_msg_invalid_alight);
	if (error_num == -6)
		printf(err_msg_invalid_file_content);
	if (error_num == -5)
		printf(err_msg_dir_not_file);
	if (error_num == -4)
		printf(err_msg_invalid_file_format);
	if (error_num == -3)
		printf(err_msg_twice_res);
	if (error_num == -2)
		printf(err_msg_invalid_res_render_size);
	if (error_num == 12)
		printf(err_msg_failed_malloc);
	return (-1);
}

int	ft_err_print(int error_num)
{
	if (error_num == -20)
		printf(err_msg_missing_requirements);
	if (error_num == -19)
		printf(err_msg_failed_file_closure);
	if (error_num == -18)
		printf(err_msg_wrong_fd);
	if (error_num == -17)
		printf(err_msg_wrong_arg_nb);
	if (error_num == -16)
		printf(err_msg_invalid_empty);
	if (error_num == -15)
		printf(err_msg_invalid_height);
	if (error_num == -14)
		printf(err_msg_invalid_length);
	if (error_num == -13)
		printf(err_msg_invalid_fov);
	if (error_num == -12)
		printf(err_msg_invalid_radius);
	if (error_num == -11)
		printf(err_msg_invalid_light_int);
	if (error_num == -10)
		printf(err_msg_invalid_orient);
	return(ft_err_print_2(error_num));
}