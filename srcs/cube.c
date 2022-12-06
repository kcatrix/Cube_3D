/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cube.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:40:56 by kevyn             #+#    #+#             */
/*   Updated: 2022/12/06 14:59:25 by kcatrix          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	boucle(t_3D	*r)
{
	draw_floor(r);
	raycasting(r);
	return (1);
}

void	ft_start_cube(t_3D *r)
{
	r->mlx = mlx_init();
	r->win = mlx_new_window(r->mlx, WIDTH, HEIGHT, "Cub3D");
	init_struct_3D(r);
	mlx_key_hook(r->win, deal_key, r);
	mlx_hook(r->win, 2, 0, ft_key_press, r);
	mlx_loop_hook(r->mlx, boucle, r);
	mlx_loop(r->mlx);
}
