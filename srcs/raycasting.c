/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:30:17 by kevyn             #+#    #+#             */
/*   Updated: 2022/11/24 17:02:53 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	raycasting(t_3D *g)
{
	g->rayon.nb = 0;
	while(g->rayon.nb < WIDTH)
	{
		init_ray(g);
		//dda(g);
	}
}

void	init_ray(t_3D *g)
{
	double val;

	val = 2 * g->rayon.nb / (double) WIDTH - 1;
	g->rayon.x = (int) g->pos_px;
	g->rayon.y = (int) g->pos_py;
	g->rayon.dir_x = g->dirX + g->planeX * val;
	g->rayon.dir_y = g->dirY + g->planeY * val;
	if (g->rayon.dir_y == 0)
		g->rayon.delta_x = 0;
	else if (g->rayon.dir_x == 0)
		g->rayon.delta_x = 1;
	else
		g->rayon.delta_x = fabs(1 / g->rayon.dir_x);
	if (g->rayon.dir_x == 0)
		g->rayon.delta_y = 0;
	else if (g->rayon.dir_y == 0)
		g->rayon.delta_y = 1;
	else
		g->rayon.delta_y = fabs(1 / g->rayon.dir_y);
	get_step(g);
	g->rayon.hit = 0;
	g->rayon.side = 0;
	g->rayon.dist = 0;
}

void	dda(t_3D *g)
{
	while(g->rayon.hit == 0)
	{
		if(g->rayon.side_x < g->rayon.side_y)
		{
			g->rayon.side_x += g->rayon.delta_x;
			g->rayon.x += g->rayon.step_x;
		}
		else
		{
			g->rayon.side_y += g->rayon.delta_y;
			g->rayon.y += g->rayon.step_y;
		}
	}
}

void	get_step(t_3D *g)
{
	if (g->rayon.dir_x < 0)
	{
		g->rayon.step_x = -1;
		g->rayon.side_x = (g->pos_px - g->rayon.x) * g->rayon.delta_x;
	}
	else
	{
		g->rayon.step_x = 1;
		g->rayon.side_x = (g->rayon.x - g->pos_px + 1.0) * g->rayon.delta_x;
	}
	if (g->rayon.dir_y < 0)
	{
		g->rayon.step_y = -1;
		g->rayon.side_y = (g->pos_py - g->rayon.y) * g->rayon.delta_y;
	}
	else
	{
		g->rayon.step_y = 1;
		g->rayon.side_y = (g->rayon.y - g->pos_py + 1.0) * g->rayon.delta_y;
	}
}