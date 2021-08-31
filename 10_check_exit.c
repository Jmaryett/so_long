/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   10_check_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmaryett <jmaryett@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 15:57:36 by jmaryett          #+#    #+#             */
/*   Updated: 2021/08/31 15:57:38 by jmaryett         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_exit_for_w(t_all *all, int i)
{
	if (all->array[i * all->plps.y + all->plps.x] == 'E')
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

void	check_exit_for_a(t_all *all, int i)
{
	if (all->array[i * all->plps.y + all->plps.x] == 'E')
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

void	check_exit_for_s(t_all *all, int i)
{
	if (all->array[i * all->plps.y + all->plps.x] == 'E')
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

void	check_exit_for_d(t_all *all, int i)
{
	if (all->array[i * all->plps.y + all->plps.x] == 'E')
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
