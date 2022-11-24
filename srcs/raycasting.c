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
}