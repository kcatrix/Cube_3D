/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:58:50 by tnicoue           #+#    #+#             */
/*   Updated: 2022/12/07 13:15:47 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_checkval(t_stock *stock)
{
	if ((stock->valcfix3 < stock->vmin || stock->valcfix3 > stock->vmax)
		|| (stock->valcfix2 < stock->vmin || stock->valcfix2 > stock->vmax)
		|| (stock->valcfix1 < stock->vmin || stock->valcfix1 > stock->vmax))
	{
		printf("erreur, mauvaises valeurs dans C\n");
		exit(0);
	}
	if ((stock->valffix3 < stock->vmin || stock->valffix3 > stock->vmax)
		|| (stock->valffix2 < stock->vmin || stock->valffix2 > stock->vmax)
		|| (stock->valffix1 < stock->vmin || stock->valffix1 > stock->vmax))
	{
		printf("erreur, mauvaises valeurs dans F\n");
		exit(0);
	}
}

void	checkmapfin(char **map, int i, t_stock *stock)
{
	while (checkspace(map[i]) == 1)
		i++;
	stock->debut = i;
	ft_createmap(stock, i);
	ft_checkmapchar(map, stock->debut);
	ft_checkmapplayer(map, stock->debut, stock);
	ft_checkbeginend(map, stock->debut);
	ft_checkmapwall(map, stock->debut);
}

void	ft_createmap(t_stock *stock, int i)
{
	int	y;

	y = i;
	while (stock->map[y])
		y++;
	stock->mapf = malloc(sizeof(char *) * ((y - i) + 1));
	y = i;
	i = 0;
	while (stock->map[y])
	{
		stock->mapf[i] = ft_strdup(stock->map[y]);
		i++;
		y++;
	}
	stock->mapf[i] = NULL;
}

void	ft_checkmapwall(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'E'
			|| map[i][j] == 'W' || map[i][j] == 'S')
			{
				ft_checkaround(i, j, map);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_checkmapchar(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != '\n' && map[i][j] != '1'
			&& map[i][j] != '0' && map[i][j] != 'N'
			&& map[i][j] != 'S' && map[i][j] != 'W'
			&& map[i][j] != 'E' && map[i][j] != 32)
			{
				printf("erreur: Mauvaise definition de la map :");
				printf("%c\n", map[i][j]);
				exit (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
