/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sky_and_floor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 17:32:15 by kevyn             #+#    #+#             */
/*   Updated: 2022/11/30 16:16:20 by kcatrix          ###   ########.fr       */
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

