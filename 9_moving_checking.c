/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_moving_checking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:19:59 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/02 16:54:33 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_w(t_all *all)
{
	if (all->arr[all->plps.y - 1][all->plps.x] != '1')
	{
		all->plps.y -= 1;
		draw_floor(all, all->plps.y + 1, all->plps.x);
		check_exit_for_w(all);
	}
	if (all->arr[all->plps.y][all->plps.x] == 'C')
	{
		all->arr[all->plps.y][all->plps.x] = '0';
		draw_floor(all, all->plps.y, all->plps.x);
		all->coin_count--;
	}
	else if (all->arr[all->plps.y][all->plps.x] == 'E')
	{
		if (all->coin_count == 0)
			esc(all);
		else
			all->plps.y = all->plps.y + 1;
		return ;
	}
	else
		all->plps.y = all->plps.y;
	draw_player(all);
}

void	check_a(t_all *all)
{
	if (all->arr[all->plps.y][all->plps.x - 1] != '1')
	{
		all->plps.x -= 1;
		draw_floor(all, all->plps.y, all->plps.x + 1);
		check_exit_for_a(all);
	}
	if (all->arr[all->plps.y][all->plps.x] == 'C')
	{
		all->arr[all->plps.y][all->plps.x] = '0';
		draw_floor(all, all->plps.y, all->plps.x);
		all->coin_count--;
	}
	else if (all->arr[all->plps.y][all->plps.x] == 'E')
	{
		if (all->coin_count == 0)
			esc(all);
		else
			all->plps.x = all->plps.x + 1;
		return ;
	}
	else
		all->plps.x = all->plps.x;
	draw_player(all);
}

void	check_s(t_all *all)
{
	if (all->arr[all->plps.y + 1][all->plps.x] != '1')
	{
		all->plps.y += 1;
		draw_floor(all, all->plps.y - 1, all->plps.x);
		check_exit_for_s(all);
	}
	if (all->arr[all->plps.y][all->plps.x] == 'C')
	{
		all->arr[all->plps.y][all->plps.x] = '0';
		draw_floor(all, all->plps.y, all->plps.x);
		all->coin_count--;
	}
	else if (all->arr[all->plps.y][all->plps.x] == 'E')
	{
		if (all->coin_count == 0)
			esc(all);
		else
			all->plps.y = all->plps.y - 1;
		return ;
	}
	else
		all->plps.y = all->plps.y;
	draw_player(all);
}

void	check_d(t_all *all)
{
	if (all->arr[all->plps.y][all->plps.x + 1] != '1')
	{
		all->plps.x += 1;
		draw_floor(all, all->plps.y, all->plps.x - 1);
		check_exit_for_d(all);
	}
	if (all->arr[all->plps.y][all->plps.x] == 'C')
	{
		all->arr[all->plps.y][all->plps.x] = '0';
		draw_floor(all, all->plps.y, all->plps.x);
		all->coin_count--;
	}
	else if (all->arr[all->plps.y][all->plps.x] == 'E')
	{
		if (all->coin_count == 0)
			esc(all);
		else
			all->plps.x = all->plps.x - 1;
		return ;
	}
	else
		all->plps.x = all->plps.x;
	draw_player(all);
}
