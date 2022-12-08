/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_and_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:32:15 by kevyn             #+#    #+#             */
/*   Updated: 2022/12/08 12:43:22 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_cree_sky(t_stock *stock, t_3D *r)
{
	r->sky[0] = stock->valcfix1;
	r->sky[1] = stock->valcfix2;
	r->sky[2] = stock->valcfix3;
	r->floor[0] = stock->valffix1;
	r->floor[1] = stock->valffix2;
	r->floor[2] = stock->valffix3;
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
	if (key == 6)
		cammousel(r);
	return (0);
}

void	left(t_3D *g)
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

void	ft_checkmapplayer(char **map, int i, t_stock *stock)
{
	int	j;
	int	fin;

	j = 0;
	fin = 0;
	while (map[i])
	{
		if (checkspace(map[i]) == 1)
		{
			verifpostmap(map, i);
			break ;
		}
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'E'
			|| map[i][j] == 'W' || map[i][j] == 'S')
				stock->playernb++;
			j++;
		}
		j = 0;
		i++;
	}
	ft_errplayer(stock);
}
