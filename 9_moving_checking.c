/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_moving_checking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:19:59 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/04 18:34:54 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_w(t_all *all)
{
	if (all->arr[all->plps.y - 1][all->plps.x] != '1')
	{
		if (!check_exit_w(all))
			return ;
		all->plps.y -= 1;
		count_moves(all);
		draw_floor(all, all->plps.y + 1, all->plps.x);
	}
	if (all->arr[all->plps.y][all->plps.x] == 'C')
	{
		all->arr[all->plps.y][all->plps.x] = '0';
		draw_floor(all, all->plps.y, all->plps.x);
		all->coin_count--;
	}
	else
		all->plps.y = all->plps.y;
	draw_player(all);
}

void	check_a(t_all *all)
{
	if (all->arr[all->plps.y][all->plps.x - 1] != '1')
	{
		if (!check_exit_a(all))
			return ;
		all->plps.x -= 1;
		count_moves(all);
		draw_floor(all, all->plps.y, all->plps.x + 1);
	}
	if (all->arr[all->plps.y][all->plps.x] == 'C')
	{
		all->arr[all->plps.y][all->plps.x] = '0';
		draw_floor(all, all->plps.y, all->plps.x);
		all->coin_count--;
	}
	else
		all->plps.x = all->plps.x;
	draw_player(all);
}

void	check_s(t_all *all)
{
	if (all->arr[all->plps.y + 1][all->plps.x] != '1')
	{
		if (!check_exit_s(all))
			return ;
		all->plps.y += 1;
		count_moves(all);
		draw_floor(all, all->plps.y - 1, all->plps.x);
	}
	if (all->arr[all->plps.y][all->plps.x] == 'C')
	{
		all->arr[all->plps.y][all->plps.x] = '0';
		draw_floor(all, all->plps.y, all->plps.x);
		all->coin_count--;
	}
	else
		all->plps.y = all->plps.y;
	draw_player(all);
}

void	check_d(t_all *all)
{
	if (all->arr[all->plps.y][all->plps.x + 1] != '1')
	{
		if (!check_exit_d(all))
			return ;
		all->plps.x += 1;
		count_moves(all);
		draw_floor(all, all->plps.y, all->plps.x - 1);
	}
	if (all->arr[all->plps.y][all->plps.x] == 'C')
	{
		all->arr[all->plps.y][all->plps.x] = '0';
		draw_floor(all, all->plps.y, all->plps.x);
		all->coin_count--;
	}
	else
		all->plps.x = all->plps.x;
	draw_player(all);
}
