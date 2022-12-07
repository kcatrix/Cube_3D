/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 16:30:17 by kevyn             #+#    #+#             */
/*   Updated: 2022/12/07 13:35:13 by tnicoue          ###   ########.fr       */
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
		init_ray(g);
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

void	init_ray(t_3D *g)
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

void	draw_texture(t_3D *g, int start, int end)
{
	double	step;
	double	texpos;
	int		texy;
	int		texx;

	if (start < 0)
		start = 0;
	if (end > HEIGHT)
		end = HEIGHT - 1;
	texture_prep2(g, &texx);
	step = 1.0 * g->wall[g->rayon.side].h / g->rayon.h;
	texpos = (start - HEIGHT / 2 + g->rayon.h / 2) * step;
	while (start < end)
	{
		texy = (int)texpos & (g->wall[g->rayon.side].h - 1);
		texpos += step;
		g->buffer[start * WIDTH
			+ g->rayon.nb] = g->wall[g->rayon.side].buffer[texy
			* g->wall[g->rayon.side].w + texx];
		start++;
	}
}

void	texture_prep2(t_3D *g, int *texx)
{
	if (g->rayon.side <= 1)
		g->rayon.wallx = g->pos_py + g->rayon.dist * g->rayon.dir_y;
	else
		g->rayon.wallx = g->pos_px + g->rayon.dist * g->rayon.dir_x;
	g->rayon.wallx -= floor((g->rayon.wallx));
	*texx = (int)(g->rayon.wallx * (double)g->wall[g->rayon.side].w);
	if (g->rayon.side <= 1 && g->dirx > 0)
		*texx = g->wall[g->rayon.side].w - *texx - 1;
	if (g->rayon.side > 1 && g->diry < 0)
		*texx = g->wall[g->rayon.side].w - *texx - 1;
}

t_wall	texture_prep(void *mlx, char *file)
{
	t_wall	stru;

	stru.img = mlx_xpm_file_to_image(mlx, file, &stru.w, &stru.h);
	stru.buffer = (int *) mlx_get_data_addr(stru.img,
			&stru.bpp, &stru.sizel, &stru.endian);
	return (stru);
}
