#include "so_long.h"

void	check_w(t_all *all, int i)
{
	if (all->array[i * (all->plps.y - 1) + all->plps.x] != '1')
		all->plps.y -= 1;
	if (all->array[i * all->plps.y + all->plps.x] == 'C')
	{
		all->array[i * all->plps.y + all->plps.x] = '0';
		//draw_floor(all, all->plps.y * ELEM_SIZE, all->plps.x * ELEM_SIZE);
		all->coin_count--;
		printf ("coins left = %d\n", all->coin_count);
	}
	else if (all->array[i * all->plps.y + all->plps.x] == 'E')
	{
		if (all->coin_count == 0)
		{
			//all->plps.y -= 1;
			esc(all);
		}
		else
			all->plps.y = all->plps.y;
	}
	else
		all->plps.y = all->plps.y;
}

void	check_a(t_all *all, int i)
{
	if (all->array[i *all->plps.y + all->plps.x - 1] != '1')
		all->plps.x -= 1;
	if (all->array[i *all->plps.y + all->plps.x] == 'C')
	{
		all->array[i *all->plps.y + all->plps.x] = '0';
		//all->plps.x -= 1;
		//draw_floor(all, all->plps.y * ELEM_SIZE, all->plps.x * ELEM_SIZE);
		all->coin_count--;
		printf ("coins left = %d\n", all->coin_count);

	}
	else if (all->array[i *all->plps.y + all->plps.x] == 'E')
	{
		if (all->coin_count == 0)
		{
			//all->plps.x -= 1;
			esc(all);
		}
		else
			all->plps.x = all->plps.x;
	}
	else
		all->plps.x = all->plps.x;
}

void	check_s(t_all *all, int i)
{
	if (all->array[i * (all->plps.y + 1) + all->plps.x] != '1')
		all->plps.y += 1;
	if (all->array[i * all->plps.y + all->plps.x] == 'C')
	{
		all->array[i * all->plps.y + all->plps.x] = '0';
		//all->plps.y += 1;
		//draw_floor(all, all->plps.y * ELEM_SIZE, all->plps.x * ELEM_SIZE);
		all->coin_count--;
		printf ("coins left = %d\n", all->coin_count);
	}
	else if (all->array[i * all->plps.y + all->plps.x] == 'E')
	{
		if (all->coin_count == 0)
		{
			//all->plps.y += 1;	
			esc(all);
		}
		else
			all->plps.y = all->plps.y;
	}
	else
		all->plps.y = all->plps.y;
}

void	check_d(t_all *all, int i)
{
	if (all->array[i * all->plps.y + all->plps.x + 1] != '1')
		all->plps.x += 1;
	if (all->array[i *all->plps.y + all->plps.x] == 'C')
	{
		all->array[i *all->plps.y + all->plps.x] = '0';
		//all->plps.x += 1;
		//draw_floor(all, all->plps.y * ELEM_SIZE, all->plps.x * ELEM_SIZE);
		all->coin_count--;
		printf ("coins left = %d\n", all->coin_count);
	}
	else if (all->array[i *all->plps.y + all->plps.x] == 'E')
	{
		if (all->coin_count == 0)
		{
			//all->plps.x += 1;
			esc(all);
		}
		else
			all->plps.x = all->plps.x;
	}
	else
		all->plps.x = all->plps.x;
}