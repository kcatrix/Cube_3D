/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:24:15 by tnicoue           #+#    #+#             */
/*   Updated: 2022/12/08 13:04:27 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int ac, char **av)
{
	int		map;
	int		y;
	int		i;
	t_stock	stock;
	t_3D	r;

	i = 0;
	y = 0;
	r.testmove = 1;
	if (ac > 1)
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
		last_parse(&stock);
		ft_affecttext(&stock, &r);
		init_struct_r(&stock, &r);
		ft_start_cube(&r);
	}
}

void	ft_affecttext(t_stock *stock, t_3D *r)
{
	r->mlx = mlx_init();
	r->wall[0] = texture_prep(r->mlx, stock->pathspritew);
	r->wall[1] = texture_prep(r->mlx, stock->pathspritee);
	r->wall[3] = texture_prep(r->mlx, stock->pathsprites);
	r->wall[2] = texture_prep(r->mlx, stock->pathspriten);
}

int	deal_key(int key, t_3D *r)
{
	if (key == 53)
		exit('exit');
	if (key == 17)
		exit('exit');
	if (key == 13)
		up(r);
	if (key == 1)
		down(r);
	if (key == 123)
		left(r);
	if (key == 124)
		right(r);
	if (key == 0)
		newleft(r);
	if (key == 2)
		newright(r);
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
	{
		r->buffer[x--] = color;
	}
	color = create_trgb(0, r->sky[0], r->sky[1], r->sky[2]);
	while (x >= 0)
		r->buffer[x--] = color;
	mlx_put_image_to_window(r->mlx, r->win, r->img, 0, 0);
}
