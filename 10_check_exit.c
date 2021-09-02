/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_check_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chudapak <chudapak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:57:36 by jmaryett          #+#    #+#             */
/*   Updated: 2021/09/02 15:54:06 by chudapak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit_for_w(t_all *all)
{
	if (all->arr[all->plps.y][all->plps.x] == 'E')
	{
		if (all->coin_count != 0)
			return ;
	}
	else
	{
		all->key.count_moves++;
		ft_putstr_fd("Current number of moves = ", 1);
		ft_putnbr_fd(all->key.count_moves, 1);
		ft_putchar_fd('\n', 1);
	}
	return ;
}

void	check_exit_for_a(t_all *all)
{
	if (all->arr[all->plps.y][all->plps.x] == 'E')
	{
		if (all->coin_count != 0)
			return ;
	}
	else
	{
		all->key.count_moves++;
		ft_putstr_fd("Current number of moves = ", 1);
		ft_putnbr_fd(all->key.count_moves, 1);
		ft_putchar_fd('\n', 1);
	}
	return ;
}

void	check_exit_for_s(t_all *all)
{
	if (all->arr[all->plps.y][all->plps.x] == 'E')
	{
		if (all->coin_count != 0)
			return ;
	}
	else
	{
		all->key.count_moves++;
		ft_putstr_fd("Current number of moves = ", 1);
		ft_putnbr_fd(all->key.count_moves, 1);
		ft_putchar_fd('\n', 1);
	}
	return ;
}

void	check_exit_for_d(t_all *all)
{
	if (all->arr[all->plps.y][all->plps.x] == 'E')
	{
		if (all->coin_count != 0)
			return ;
	}
	else
	{
		all->key.count_moves++;
		ft_putstr_fd("Current number of moves = ", 1);
		ft_putnbr_fd(all->key.count_moves, 1);
		ft_putchar_fd('\n', 1);
	}
	return ;
}
