/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:35:45 by kevyn             #+#    #+#             */
/*   Updated: 2022/11/30 14:03:22 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct_r(t_stock *stock, t_3D *r)
{
	ft_init_val(r);
	ft_cree_map(stock, r);
	ft_cree_floor(stock, r);
	ft_cree_sky(stock, r);
	ft_pos_player(r);
	ft_dir_player(r);
	ft_fov(r);
	//ft_cree_way_wall(stock, r);
}

void	ft_fov(t_3D *r)
{
	if (r->dir == 'N' || r->dir == 'S')
	{
		r->dirx = 0.;
		r->diry = fov_gest(r, 8);
		r->planex = fov_gest(r, 10);
		r->planey = 0.;
	}
	else if (r->dir == 'E' || r->dir == 'W')
	{
		r->dirx = fov_gest(r, 8);
		r->diry = 0.;
		r->planex = 0.;
		r->planey = fov_gest(r, 10);
	}
}

double	fov_gest(t_3D *r, int check)
{
	if (check == 10)
	{
		if (r->dir == 'N' || r->dir == 'E')
			return (0.66);
		return (-0.66);
	}
	if (r->dir == 'W' || r->dir == 'N')
		return (-1);
	return (1);
}

void	init_struct(t_stock *stock)
{
	stock->pathspriten = NULL;
	stock->pathsprites = NULL;
	stock->pathspritew = NULL;
	stock->pathspritee = NULL;
	stock->vmin = 0;
	stock->vmax = 255;
	stock->testfd = 0;
}

void	init_struct_3D(t_3D *r)
{
	int	x;

	r->img = mlx_new_image(r->mlx, WIDTH, HEIGHT);
	r->buffer = (int *) mlx_get_data_addr(r->img, &r->bpp,
			&r->sizel, &x);
}

void	ft_cree_map(t_stock *stock, t_3D *r)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	while(stock->map[i])
	{
		while(stock->map[i][y])
		{
			if (stock->map[i][y] == '1' 
				&& stock->map[i][y + 1] == '1' && stock->map[i][y + 2] == '1')
			{
				r->map = ft_malloc_map(stock, r, i);
				return ;
			}
			y++;
		}
		y = 0;
		i++;
	}
}

char **ft_malloc_map(t_stock *stock, t_3D *r, int i)
{
	int y;
	int res;

	y = 0;
	res = i;
	while(stock->map[res])
		res++;
	r->map = malloc(sizeof(char **) * (res + 1));
	while(stock->map[i])
	{
		r->map[y] = strdup(stock->map[i]);
		y++;
		i++;
	}
	r->map[y] = NULL;
	return (r->map);
}

void	ft_pos_player(t_3D *r)
{
	int y;
	int x;
	
	y = 0;
	x = 0;
	while (r->map[y])
	{
		while(r->map[y][x] != '\n')
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
	r->pos_px = 0;
	r->pos_py = 0;
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

void	ft_init_val(t_3D *r)
{
	r->planex = 0;
	r->planey = 0.66;
	r->speed = 0.2;
}
