/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   9_moving_checking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/29 19:19:59 by jmaryett          #+#    #+#             */
/*   Updated: 2021/08/29 19:20:01 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_w(t_all *all, int i)
{
	if (all->array[i * (all->plps.y - 1) + all->plps.x] != '1')
	{
		all->plps.y -= 1;
		all->key.count_moves++;
		printf ("Current number of moves = %d\n", all->key.count_moves);
	}
	if (all->array[i * all->plps.y + all->plps.x] == 'C')
	{
		all->array[i * all->plps.y + all->plps.x] = '0';
		all->coin_count--;
	}
	else if (all->array[i * all->plps.y + all->plps.x] == 'E')
	{
		if (all->coin_count == 0)
			esc(all);
		else
			all->plps.y = all->plps.y + 1;
		return ;
	}
	else
		all->plps.y = all->plps.y;
}

void	check_a(t_all *all, int i)
{
	if (all->array[i * all->plps.y + all->plps.x - 1] != '1')
	{
		all->plps.x -= 1;
		all->key.count_moves++;
		printf ("Current number of moves = %d\n", all->key.count_moves);
	}
	if (all->array[i * all->plps.y + all->plps.x] == 'C')
	{
		all->array[i * all->plps.y + all->plps.x] = '0';
		all->coin_count--;
	}
	else if (all->array[i * all->plps.y + all->plps.x] == 'E')
	{
		if (all->coin_count == 0)
			esc(all);
		else
			all->plps.x = all->plps.x + 1;
		return ;
	}
	else
		all->plps.x = all->plps.x;
}

void	check_s(t_all *all, int i)
{
	if (all->array[i * (all->plps.y + 1) + all->plps.x] != '1')
	{
		all->plps.y += 1;
		all->key.count_moves++;
		printf ("Current number of moves = %d\n", all->key.count_moves);
	}
	if (all->array[i * all->plps.y + all->plps.x] == 'C')
	{
		all->array[i * all->plps.y + all->plps.x] = '0';
		all->coin_count--;
	}
	else if (all->array[i * all->plps.y + all->plps.x] == 'E')
	{
		if (all->coin_count == 0)
			esc(all);
		else
			all->plps.y = all->plps.y - 1;
		return ;
	}
	else
		all->plps.y = all->plps.y;
}

void	check_d(t_all *all, int i)
{
	if (all->array[i * all->plps.y + all->plps.x + 1] != '1')
	{
		all->plps.x += 1;
		all->key.count_moves++;
		printf ("Current number of moves = %d\n", all->key.count_moves);
	}
	if (all->array[i * all->plps.y + all->plps.x] == 'C')
	{
		all->array[i * all->plps.y + all->plps.x] = '0';
		all->coin_count--;
	}
	else if (all->array[i * all->plps.y + all->plps.x] == 'E')
	{
		if (all->coin_count == 0)
			esc(all);
		else
			all->plps.x = all->plps.x - 1;
		return ;
	}
	else
		all->plps.x = all->plps.x;
}
