/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:57:59 by tnicoue           #+#    #+#             */
/*   Updated: 2022/12/07 14:00:05 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cammouser(t_3D *g)
{
	double	oldplanex;
	double	olddirx;

	oldplanex = g->planex;
	olddirx = g->dirx;
	g->dirx = g->dirx * cos(g->rotspeed / 10) - g->diry * sin(g->rotspeed / 10);
	g->diry = olddirx * sin(g->rotspeed / 10) + g->diry * cos(g->rotspeed / 10);
	g->planex = g->planex * cos(g->rotspeed / 10) - g->planey * sin(g->rotspeed / 10);
	g->planey = oldplanex * sin(g->rotspeed / 10) + g->planey * cos(g->rotspeed / 10);
}

void	cammousel(t_3D *g)
{
	double	oldplanex;
	double	olddirx;

	oldplanex = g->planex;
	olddirx = g->dirx;
	g->dirx = g->dirx * cos(-g->rotspeed / 10) - g->diry * sin(-g->rotspeed / 10);
	g->diry = olddirx * sin(-g->rotspeed / 10) + g->diry * cos(-g->rotspeed / 10);
	g->planex = g->planex * cos(-g->rotspeed / 10) - g->planey * sin(-g->rotspeed / 10);
	g->planey = oldplanex * sin(-g->rotspeed / 10) + g->planey * cos(-g->rotspeed / 10);
}