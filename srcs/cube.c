/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:40:56 by kevyn             #+#    #+#             */
/*   Updated: 2022/11/24 16:43:22 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	boucle(t_3D	*r)
{
	(void) r;
	//ft_key(&r);
	draw_floor(r);
	raycasting(r);
	return (1);
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