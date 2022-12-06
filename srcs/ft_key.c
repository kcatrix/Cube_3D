/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:24:31 by kcatrix           #+#    #+#             */
/*   Updated: 2022/12/06 16:55:49 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	up(t_3D *g)
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

void	newleft(t_3D *g)
{
	if (g->map[(int)(g->pos_py - g->planex * g->speed)][(int)g->pos_px] != '1')
		g->pos_py -= g->planey * g->speed;
	if (g->map[(int)(g->pos_py)][(int)(g->pos_px - g->planex * g->speed)] != '1')
		g->pos_px -= g->planex * g->speed;
}

void	newright(t_3D *g)
{
	if (g->map[(int)(g->pos_py + g->planey * g->speed)][(int)g->pos_px] != '1')
		g->pos_py += g->planey * g->speed;
	if (g->map[(int)(g->pos_py)][(int)(g->pos_px + g->planex * g->speed)] != '1')
		g->pos_px += g->planex * g->speed;
}

void	right(t_3D *g)
{
	double	oldplanex;
	double	olddirx;

	printf("g_dir x = %f g_dir y = %f\n", g->dirx, g->diry);
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

int	ft_key_press(int key, t_3D *r)
{
	if (key == 53)
		exit('exit');
	if (key == 17)
		exit('exit');
	if (key == 13)
		up(r);
	if (key == 1)
		down(r);
	if (key == 0)
		newleft(r);
	if (key == 2)
		newright(r);
	if (key == 123)
		left(r);
	if (key == 124)
		right(r);
	return (0);
}
