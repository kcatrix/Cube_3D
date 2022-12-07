/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:40:56 by kevyn             #+#    #+#             */
/*   Updated: 2022/12/07 14:27:35 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	boucle(t_3D	*r)
{
	draw_floor(r);
	raycasting(r);
	return (1);
}

int	win_closed(t_3D *r)
{
	mlx_destroy_window(r->mlx, r->win);
	printf("\033[0;32m" "Window closed succesfuly !\n" "\033[0m");
	exit (0);
}

void	ft_start_cube(t_3D *r)
{
	r->win = mlx_new_window(r->mlx, WIDTH, HEIGHT, "Cub3D");
	init_struct_3d(r);
	mlx_key_hook(r->win, deal_key, r);
	mlx_hook(r->win, 2, 0, ft_key_press, r);
	mlx_hook(r->win, 17, 1L << 0, win_closed, r);
	mlx_loop_hook(r->mlx, boucle, r);
	mlx_loop(r->mlx);
}
