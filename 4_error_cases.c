/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_error_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:20:38 by jmaryett          #+#    #+#             */
/*   Updated: 2021/08/29 19:20:38 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_map(char *array)
{
	printf ("%s\n", "Invalid map.");
	free (array);
	exit (0);
}

void	invalid_file(void)
{
	printf ("%s\n", "Can't open file.");
	exit (0);
}

void	invalid_input(void)
{
	printf ("%s\n", "Invalid input.");
	exit (0);
}
