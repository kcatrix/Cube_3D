/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 15:58:50 by tnicoue           #+#    #+#             */
/*   Updated: 2022/11/18 10:25:26 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_checkval(t_stock *stock)
{
	if ((stock->valcfix3 < stock->vmin || stock->valcfix3 > stock->vmax)
		|| (stock->valcfix3 < stock->vmin || stock->valcfix3 > stock->vmax)
		|| (stock->valcfix3 < stock->vmin || stock->valcfix3 > stock->vmax))
	{
		printf("erreur, mauvaises valeurs dans C\n");
		exit(0);
	}
	if ((stock->valffix3 < stock->vmin || stock->valffix3 > stock->vmax)
		|| (stock->valffix3 < stock->vmin || stock->valffix3 > stock->vmax)
		|| (stock->valffix3 < stock->vmin || stock->valffix3 > stock->vmax))
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
	printf("ahouais\n");
	ft_checkmapchar(map, stock->debut);
	printf("test\n");
	ft_checkmapplayer(map, stock->debut, stock);
	printf("numero\n");
	ft_checkbeginend(map, stock->debut);
	printf("1\n");
	ft_checkmapwall(map, stock->debut);
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
