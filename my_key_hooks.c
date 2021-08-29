/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_key_hooks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:22:08 by jmaryett          #+#    #+#             */
/*   Updated: 2021/08/29 19:22:23 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	esc(t_all *all)
{
	mlx_destroy_window(all->mlx, all->mlx_win);
	exit (0);
	return (0);
}

static void	check_positions(t_all *all, char key)
{
	int	i;

	i = all->map.width + 1;
	if (key == 'w')
		check_w(all, i);
	else if (key == 'a')
		check_a(all, i);
	else if (key == 's')
		check_s(all, i);
	else if (key == 'd')
		check_d(all, i);
}

int	key_pressed(int keycode, t_all *all)
{
	if (keycode == 53)
		esc(all);
	else if (keycode == 13)
	{
		all->key.w = 1;
		check_positions(all, 'w');
	}
	else if (keycode == 0)
	{
		all->key.a = 1;
		check_positions(all, 'a');
	}
	else if (keycode == 1)
	{	
		all->key.s = 1;
		check_positions(all, 's');
	}
	else if (keycode == 2)
	{	
		all->key.d = 1;
		check_positions(all, 'd');
	}
	return (0);
}

int	key_released(int keycode, t_all *all)
{
	if (keycode == 13)
		all->key.w = 0;
	else if (keycode == 0)
		all->key.a = 0;
	else if (keycode == 1)
		all->key.s = 0;
	else if (keycode == 2)
		all->key.d = 0;
	return (0);
}
