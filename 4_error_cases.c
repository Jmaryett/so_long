/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_error_cases.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:20:38 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/01 14:35:46 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	invalid_map(void)
{
	write (1, "Error\nInvalid map.\n", 19);
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
