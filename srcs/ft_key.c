/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:24:31 by kcatrix           #+#    #+#             */
/*   Updated: 2022/11/30 15:43:16 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	upright(t_3D *g)
{
	if (g->map[(int)(g->pos_py + g->diry * g->speed)][(int)g->pos_px] != '1')
		g->pos_py += g->diry * g->speed;
	if (g->map[(int)(g->pos_py)][(int)(g->pos_px + g->dirx * g->speed)] != '1')
		g->pos_px += g->dirx * g->speed;
}

void	down(t_3D *g)
{
	if (g->map[(int)(g->pos_py - g->diry * g->speed)][(int)g->pos_px] != '1')
		g->pos_py -= g->diry * g->speed;
	if (g->map[(int)(g->pos_py)][(int)(g->pos_px - g->dirx * g->speed)] != '1')
		g->pos_px -= g->dirx * g->speed;
}

void	right(t_3D *g)
{
	double	oldplanex;
	double	olddirx;

	oldplanex = g->planex;
	olddirx = g->dirx;
	g->dirx = g->dirx * cos(g->rotspeed) - g->diry * sin(g->rotspeed);
	g->diry = olddirx * sin(g->rotspeed) + g->diry * cos(g->rotspeed);
	g->planex = g->planex * cos(g->rotspeed) - g->planey * sin(g->rotspeed);
	g->planey = oldplanex * sin(g->rotspeed) + g->planey * cos(g->rotspeed);
}

void	left(t_3D *g)
{
	double	oldplanex;
	double	olddirx;

	oldplanex = g->planex;
	olddirx = g->dirx;
	g->dirx = g->dirx * cos(-g->rotspeed) - g->diry * sin(-g->rotspeed);
	g->diry = olddirx * sin(-g->rotspeed) + g->diry * cos(-g->rotspeed);
	g->planex = g->planex * cos(-g->rotspeed) - g->planey * sin(-g->rotspeed);
	g->planey = oldplanex * sin(-g->rotspeed) + g->planey * cos(-g->rotspeed);
}
