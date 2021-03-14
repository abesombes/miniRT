/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_control_args_file.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abesombe <abesombe@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/08 09:43:11 by abesombe          #+#    #+#             */
/*   Updated: 2021/03/14 20:21:30 by abesombe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minirt.h"
#include "../../includes/ft_err_print.h"

int	ft_control_is_directory(char *str)
{
	int fd;

	fd = open(str, O_DIRECTORY);
	if (fd == -1)
		return (0);
	close(fd);
	return (1);
}

int	ft_control_rt_file_format(char *str)
{
	int i;

	i = 0;
	while(str[i])
		i++;
	if (str[i - 3] == '.' && str[i - 2] == 'r' && str[i - 1] == 't')
		return (1);
	return (0);
}

int ft_control_args_file(int ac, char **av)
{
 	if (ac != 2 && (ft_strcmp(av[2], "-save")))
		return (ft_err_print(-17));
	if (!ft_control_rt_file_format(av[1]))
		ft_err_print(-4);
	if (ft_control_is_directory(av[1]))
		ft_err_print(-5);
	return (1);
}
