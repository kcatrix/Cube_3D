/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   closedmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 10:04:27 by tnicoue           #+#    #+#             */
/*   Updated: 2022/11/18 10:08:10 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_checkaround(int i, size_t j, char **map)
{
	if (ft_strlen(map[i - 1]) < j || (map[i - 1][j] != '1'
		&& map[i - 1][j] != 'E' && map[i - 1][j] != 'N'
		&& map[i - 1][j] != 'S' && map[i - 1][j] != 'W'
		&& map[i - 1][j] != '0'))
	{
		printf("erreur: Map non fermee\n");
		exit(0);
	}
	if (ft_strlen(map[i + 1]) < j || (map[i + 1][j] != '1'
		&& map[i + 1][j] != 'E' && map[i - 1][j] != 'N'
		&& map[i + 1][j] != 'S' && map[i + 1][j] != 'W'
		&& map[i + 1][j] != '0'))
	{
		printf("erreur: Map non fermee\n");
		exit(0);
	}
	ft_checkaround2(i, j, map);
}

void	ft_checkaround2(int i, size_t j, char **map)
{
	if ((map[i][j + 1] != '1' && map[i][j + 1] != 'E'
		&& map[i][j + 1] != 'N' && map[i][j + 1] != 'S'
		&& map[i][j + 1] != 'W' && map[i][j + 1] != '0'))
	{
		printf("erreur: Map non fermee\n");
		exit(0);
	}
	if (j == 0 || (map[i][j - 1] != '1' && map[i][j - 1] != 'E'
		&& map[i][j - 1] != 'N' && map[i][j - 1] != 'S'
		&& map[i][j - 1] != 'W' && map[i][j - 1] != '0'))
	{
		printf("erreur: Map non fermee\n");
		exit(0);
	}
}

void	ft_checkbeginend(char **map, int i)
{
	int	j;

	j = 0;
	while (map[i][j])
	{
		if (map[i][j] != 32 && map[i][j] != '1' && map[i][j] != '\n')
		{
			printf("erreur: map mal faite\n");
			exit(0);
		}
		j++;
	}
	j = 0;
	while (map[i])
		i++;
	i--;
	while (map[i][j])
	{
		if (map[i][j] != 32 && map[i][j] != '1' && map[i][j] != '\n')
		{
			printf("erreur: map mal faite\n");
			exit(0);
		}
		j++;
	}
}
