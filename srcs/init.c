/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:35:45 by kevyn             #+#    #+#             */
/*   Updated: 2022/12/08 14:22:15 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	init_struct_r(t_stock *stock, t_3D *r)
{
	ft_init_val(r);
	ft_cree_map(stock, r);
	ft_cree_sky(stock, r);
	ft_pos_player(r);
	ft_fov(r);
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
		return (-1.);
	return (1.);
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

void	init_struct_3d(t_3D *r)
{
	int	x;

	r->img = mlx_new_image(r->mlx, WIDTH, HEIGHT);
	r->buffer = (int *) mlx_get_data_addr(r->img, &r->bpp,
			&r->sizel, &x);
}
