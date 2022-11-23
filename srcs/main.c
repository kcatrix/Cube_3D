/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:24:15 by tnicoue           #+#    #+#             */
/*   Updated: 2022/11/23 17:06:12 by kevyn            ###   ########.fr       */
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
		init_struct_r(&stock, &r);
		ft_start_cube(&r);
	}
}

void	init_struct_r(t_stock *stock, t_3D *r)
{
	int i;

	i = 0;
	printf("init\n");
	ft_cree_map(stock, r);
	printf("init end\n");
	ft_cree_floor(stock, r);
	ft_cree_sky(stock, r);
	
}

void	ft_cree_floor(t_stock *stock, t_3D *r)
{
	int i;
	int	y;
	int index;
	char res[5];
	int	index2;

	index = 0;
	index2 = 0;
	i = 0;
	y = 0;
	
	
	while(stock->map[i])
	{
		if (stock->map[i][0] == 'F')
		{
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
		i++;
	}
}

void	ft_cree_sky(t_stock *stock, t_3D *r)
{
	int i;
	int	y;
	int index;
	char res[5];
	int	index2;

	index = 0;
	index2 = 0;
	i = 0;
	y = 0;
	
	
	while(stock->map[i])
	{
		if (stock->map[i][0] == 'C')
		{
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
				r->sky[index2++] = ft_atoi(res);
				index = 0;
				while (res[index])
					res[index++] = '\0';
				index = 0;	
			}
		}
		i++;
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

void	ft_cree_map(t_stock *stock, t_3D *r)
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
				return ;
			}
			y++;
		}
		y = 0;
		i++;
	}
}

char **ft_malloc_map(t_stock *stock, t_3D *r, int i)
{
	int y;
	int res;

	y = 0;
	res = i;
	while(stock->map[res])
		res++;
	r->map = malloc(sizeof(char **) * res + 1);
	while(stock->map[i])
	{
		r->map[y] = strdup(stock->map[i]);
		y++;
		i++;
	}
	r->map[y] = NULL;
	return (r->map);
}

int	deal_key(int key, t_3D *r)
{
	if (key == 53)
		exit('exit');
	(void) r;
	return (0);
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	draw_floor(t_3D *r)
{
	int	x;
	int	color;
	int	mid;

	mid = WIDTH * HEIGHT / 2 - 1;
	x = HEIGHT * WIDTH - 1;
	color = create_trgb(0, r->floor[0], r->floor[1],
			r->floor[2]);
	while (x >= mid)
		r->buffer[x--] = color;
	color = create_trgb(0, r->sky[0], r->sky[1], r->sky[2]);
	while (x >= 0)
		r->buffer[x--] = color;
	mlx_put_image_to_window(r->mlx, r->win, r->img, 0,0);
}

int	boucle(t_3D	*r)
{
	//ft_key(&r);
	draw_floor(r);
	//raycasting(&r);
	return (1);
}

void	init_struct_3D(t_3D *r)
{
	int x;
	
	r->img = mlx_new_image(r->mlx, WIDTH, HEIGHT);
	r->buffer = (int *) mlx_get_data_addr(r->img, &r->bpp,
			&r->sizel, &x);
	
}

void	ft_start_cube(t_3D *r)
{
	r->mlx = mlx_init();
	r->win = mlx_new_window(r->mlx, WIDTH, HEIGHT, "Cub3D");
	init_struct_3D(r);
	mlx_key_hook(r->win, deal_key, &r);
	mlx_loop_hook(r->mlx, boucle, r);	
	mlx_loop(r->mlx);
	
}
