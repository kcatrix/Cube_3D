/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_and_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:32:15 by kevyn             #+#    #+#             */
/*   Updated: 2022/11/23 17:33:27 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_cree_floor(t_stock *stock, t_3D *r)
{
	int i;
	int	y;

	i = 0;
	y = 0;
	
	
	while(stock->map[i])
	{
		if (stock->map[i][0] == 'F')
			ft_cree_floor_loop(stock, r, i, y);
		i++;
	}
}

void	ft_cree_floor_loop(t_stock *stock, t_3D *r, int i, int y)
{
	int index;
	int index2;
	char res[5];
	
	index = 0;
	index2 = 0;
	
	while(stock->map[i][y] != '\n')
	{
		while(ft_isdigit(stock->map[i][y]) != 1)
			y++;
		while(ft_isdigit(stock->map[i][y]) == 1)
		{
			res[index] = stock->map[i][y];
			index++;
			y++;
		}
		r->floor[index2++] = ft_atoi(res);
		index = 0;
		while (res[index])
			res[index++] = '\0';
		index = 0;
	}	
}

void	ft_cree_sky(t_stock *stock, t_3D *r)
{
	int i;
	int	y;
	
	i = 0;
	y = 0;
	while(stock->map[i])
	{
		if (stock->map[i][0] == 'C')
			ft_cree_sky_loop(stock, r, i, y);
		i++;
	}
}

void	ft_cree_sky_loop(t_stock *stock, t_3D *r, int i, int y)
{
	int index;
	int index2;
	char res[5];

	index = -1;
	index2 = 0;
	while(stock->map[i][y] != '\n')
	{
		while(ft_isdigit(stock->map[i][y]) != 1)
			y++;
		while(ft_isdigit(stock->map[i][y]) == 1)
			res[++index] = stock->map[i][y++];
		r->sky[index2++] = ft_atoi(res);
		index = 0;
		while (res[index])
			res[index++] = '\0';
		index = -1;	
	}
}
