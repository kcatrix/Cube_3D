/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:57:59 by tnicoue           #+#    #+#             */
/*   Updated: 2022/12/08 11:32:26 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cammouser(t_3D *g)
{
	double	oldplanex;
	double	olddirx;

	g->testmove = 1;
	oldplanex = g->planex;
	olddirx = g->dirx;
	g->dirx = g->dirx * cos(g->rotspeed) - g->diry * sin(g->rotspeed);
	g->diry = olddirx * sin(g->rotspeed) + g->diry * cos(g->rotspeed);
	g->planex = g->planex * cos(g->rotspeed) - g->planey * sin(g->rotspeed);
	g->planey = oldplanex * sin(g->rotspeed) + g->planey * cos(g->rotspeed);
}

void	cammousel(t_3D *g)
{
	double	oldplanex;
	double	olddirx;

	g->testmove = 1;
	oldplanex = g->planex;
	olddirx = g->dirx;
	g->dirx = g->dirx * cos(-g->rotspeed) - g->diry * sin(-g->rotspeed);
	g->diry = olddirx * sin(-g->rotspeed) + g->diry * cos(-g->rotspeed);
	g->planex = g->planex * cos(-g->rotspeed) - g->planey * sin(-g->rotspeed);
	g->planey = oldplanex * sin(-g->rotspeed) + g->planey * cos(-g->rotspeed);
}
