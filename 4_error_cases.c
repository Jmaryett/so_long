/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_error_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:20:38 by jmaryett          #+#    #+#             */
/*   Updated: 2021/08/31 18:34:58 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_map(char *array)
{
	write (1, "Error\nInvalid map.\n", 19);
	free (array);
	exit (0);
}

void	invalid_file(void)
{
	write (1, "Error\nCan't open file.\n", 23);
	exit (0);
}

void	invalid_input(void)
{
	write (1, "Error\nInvalid input.\n", 21);
	exit (0);
}
