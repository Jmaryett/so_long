/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fd_and_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 18:47:30 by jmaryett          #+#    #+#             */
/*   Updated: 2021/08/31 18:55:30 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file_name(char *filename)
{
	int	len;

	len = ft_strlen(filename);
	if (filename[len - 1] != 'r')
		invalid_input();
	else if (filename[len - 2] != 'e')
		invalid_input();
	else if (filename[len - 3] != 'b')
		invalid_input();
	else if (filename[len - 4] != '.')
		invalid_input();
	return ;
}

int	check_fd(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd < 0)
		invalid_file();
	return (fd);
}
