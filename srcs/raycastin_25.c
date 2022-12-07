/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycastin_25.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:41:20 by kcatrix           #+#    #+#             */
/*   Updated: 2022/12/07 15:42:16 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

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
