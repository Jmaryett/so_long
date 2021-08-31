/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_error_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:20:38 by jmaryett          #+#    #+#             */
/*   Updated: 2021/08/31 15:39:39 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_map(char *array)
{
	write (1, "Invalid map.\n", 13);
	free (array);
	exit (0);
}

void	invalid_file(void)
{
	write (1, "Can't open file.\n", 17);
	exit (0);
}

void	invalid_input(void)
{
	write (1, "Invalid input.\n", 15);
	exit (0);
}
