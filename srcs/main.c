/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:24:15 by tnicoue           #+#    #+#             */
/*   Updated: 2022/11/23 12:22:37 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	int		map;
	int		y;
	int		i;
	t_stock	stock;
	t_3D 	r;

	i = 0;
	y = 0;
	if (ac >= 1)
	{
		init_struct(&stock);
		map = openmap(av, &y);
		if (map == -1)
			return (0);
		if (formatmap(map, &stock, y) == -1)
			return (0);
		checkmapdebut(stock.map, &stock);
		valfix(&stock);
		ft_checkopen(&stock);
		r.map = ft_cree_map(&stock, &r);
		while (r.map[i])
			printf("%s", r.map[i++]);
		printf("\n");
	}
}

void	init_struct(t_stock *stock)
{
	stock->pathspriten = NULL;
	stock->pathsprites = NULL;
	stock->pathspritew = NULL;
	stock->pathspritee = NULL;
	stock->vmin = 0;
	stock->vmax = 255;
	stock->testfd = 0;
}

char **ft_cree_map(t_stock *stock, t_3D *r)
{
	int i;
	int y;
	
	i = 0;
	y = 0;
	while(stock->map[i])
	{
		while(stock->map[i][y])
		{
			if (stock->map[i][y] == '1' 
				&& stock->map[i][y + 1] == '1' && stock->map[i][y + 2] == '1')
			{
				r->map = ft_malloc_map(stock, r, i);
				return (r->map);
			}
			y++;
		}
		y = 0;
		i++;
	}
	return(r->map);	
}

char **ft_malloc_map(t_stock *stock, t_3D *r, int i)
{
	int y;

	y = 0;
	while(stock->map[i])
	{
		r->map[y] = strdup(stock->map[i]);
		y++;
		i++;
	}
	r->map[y] = NULL;
	return (r->map);
}