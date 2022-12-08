/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:19:27 by tnicoue           #+#    #+#             */
/*   Updated: 2022/12/08 14:04:01 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_init_val(t_3D *r)
{
	r->planex = 0;
	r->planey = 0.66;
	r->speed = 0.09;
	r->rotspeed = 0.06;
}

void	ft_dir_player(t_3D *r)
{
	if (r->dir == 'N')
	{
		r->diry = -1;
		r->dirx = 0;
	}
	if (r->dir == 'S')
	{
		r->diry = 1;
		r->dirx = 0;
	}
	if (r->dir == 'E')
	{
		r->diry = 0;
		r->dirx = 1;
	}
	if (r->dir == 'W')
	{
		r->diry = 0;
		r->dirx = -1;
	}
}

void	ft_pos_player(t_3D *r)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (r->map[y])
	{
		while (r->map[y][x] != '\n')
		{
			if (r->map[y][x] == 'N' || r->map[y][x] == 'S' ||
				r->map[y][x] == 'E' || r->map[y][x] == 'W')
			{
				r->pos_px = (x + 0.5);
				r->pos_py = (y + 0.5);
				r->dir = r->map[y][x];
				return ;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

char	**ft_malloc_map(t_stock *stock, t_3D *r, int i)
{
	int	y;
	int	res;

	y = 0;
	res = i;
	while (stock->map[res])
		res++;
	r->map = malloc(sizeof(char **) * (res + 1));
	while (stock->map[i])
	{
		r->map[y] = strdup(stock->map[i]);
		y++;
		i++;
	}
	r->map[y] = NULL;
	return (r->map);
}

void	ft_cree_map(t_stock *stock, t_3D *r)
{
	int	i;

	i = 0;
	r->map = stock->mapf;
}
