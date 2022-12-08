/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:30:17 by kevyn             #+#    #+#             */
/*   Updated: 2022/12/08 11:35:26 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	raycasting(t_3D *g)
{
	double	ratio;

	ratio = ((double) WIDTH / (double) HEIGHT) / (4.0 / 3.0);
	g->rayon.nb = 0;
	while (g->rayon.nb < WIDTH)
	{
		ft_rayon(g);
		dda(g);
		g->rayon.dist = (g->rayon.x - g->pos_px
				+ (1 - g->rayon.step_x) / 2) / g->rayon.dir_x;
		if (g->rayon.side == 0 || g->rayon.side == 1)
			g->rayon.dist = (g->rayon.x - g->pos_px
					+ (1 - g->rayon.step_x) / 2) / g->rayon.dir_x;
		else
			g->rayon.dist = (g->rayon.y - g->pos_py
					+ (1 - g->rayon.step_y) / 2) / g->rayon.dir_y;
		g->rayon.h = (int)(((double)HEIGHT * ratio) / g->rayon.dist);
		draw_texture(g, -g->rayon.h / 2
			+ HEIGHT / 2, g->rayon.h / 2 + HEIGHT / 2);
		g->rayon.nb++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img, 0, 0);
	return ;
}

void	draw_color(t_3D *g)
{
	while (g->draw_start < g->draw_end)
	{
		g->buffer[g->draw_start * WIDTH
			+ g->rayon.nb] = create_trgb(0, 128, 128, 128);
		g->draw_start++;
	}
}

void	ft_rayon(t_3D *g)
{
	double	val;

	val = 2 * g->rayon.nb / (double) WIDTH - 1;
	g->rayon.x = (int) g->pos_px;
	g->rayon.y = (int) g->pos_py;
	g->rayon.dir_x = g->dirx + g->planex * val;
	g->rayon.dir_y = g->diry + g->planey * val;
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
	while (g->rayon.hit == 0)
	{
		if (g->rayon.side_x < g->rayon.side_y)
		{
			g->rayon.side_x += g->rayon.delta_x;
			g->rayon.x += g->rayon.step_x;
			if (g->rayon.step_x == -1)
				g->rayon.side = 0;
			else
				g->rayon.side = 1;
		}
		else
		{
			g->rayon.side_y += g->rayon.delta_y;
			g->rayon.y += g->rayon.step_y;
			if (g->rayon.step_y == -1)
				g->rayon.side = 2;
			else
				g->rayon.side = 3;
		}
		if (g->map[g->rayon.y][g->rayon.x] == '1')
			g->rayon.hit = 1;
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
