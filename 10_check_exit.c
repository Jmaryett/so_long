/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_check_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:57:36 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/04 18:35:06 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_moves(t_all *all)
{
	all->key.count_moves++;
	ft_putstr_fd("Current number of moves = ", 1);
	ft_putnbr_fd(all->key.count_moves, 1);
	ft_putchar_fd('\n', 1);
}

int	check_exit_w(t_all *all)
{
	if (all->arr[all->plps.y - 1][all->plps.x] == 'E')
	{
		if (all->coin_count == 0)
			exit (0);
		else
			return (0);
	}
	return (1);
}

int	check_exit_a(t_all *all)
{
	if (all->arr[all->plps.y][all->plps.x - 1] == 'E')
	{
		if (all->coin_count == 0)
			exit (0);
		else
			return (0);
	}
	return (1);
}

int	check_exit_s(t_all *all)
{
	if (all->arr[all->plps.y + 1][all->plps.x] == 'E')
	{
		if (all->coin_count == 0)
			exit (0);
		else
			return (0);
	}
	return (1);
}

int	check_exit_d(t_all *all)
{
	if (all->arr[all->plps.y][all->plps.x + 1] == 'E')
	{
		if (all->coin_count == 0)
			exit (0);
		else
			return (0);
	}
	return (1);
}
