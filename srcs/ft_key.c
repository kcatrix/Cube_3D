/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_key.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:24:31 by kcatrix           #+#    #+#             */
/*   Updated: 2022/11/30 14:11:49 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	upright(t_3D *g)
{
	if (g->map[(int)(g->pos_py + g->diry * g->speed)][(int)g->pos_px] != '1'
		&& g->map[(int)(g->pos_py + g->diry * g->speed)][(int)g->pos_px])
		g->pos_py += g->diry * g->speed;
	if (g->map[(int)(g->pos_py)][(int)(g->pos_px + g->dirx * g->speed)] != '1'
		&& g->map[(int)(g->pos_py)][(int)(g->pos_px + g->dirx * g->speed)])
		g->pos_px += g->dirx * g->speed;
}
