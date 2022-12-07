/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkopen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:12:15 by tnicoue           #+#    #+#             */
/*   Updated: 2022/12/07 12:20:07 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_checkopen(t_stock *stock)
{
	stock->fde = open(stock->pathspritee, O_RDONLY, 0777);
	if (stock->fde == -1)
	{
		printf("erreur: impossible de lire %s\n", stock->pathspritee);
		stock->testfd++;
	}
	close(stock->fde);
	stock->fdn = open(stock->pathspriten, O_RDONLY, 0777);
	if (stock->fdn == -1)
	{
		printf("erreur: impossible de lire %s\n", stock->pathspriten);
		stock->testfd++;
	}
	close(stock->fdn);
	ft_checkopen2(stock);
}

void	ft_checkopen2(t_stock *stock)
{
	stock->fds = open(stock->pathsprites, O_RDONLY, 0777);
	if (stock->fds == -1)
	{
		printf("erreur: impossible de lire %s\n", stock->pathsprites);
		stock->testfd++;
	}
	close(stock->fds);
	stock->fdw = open(stock->pathspritew, O_RDONLY, 0777);
	if (stock->fdw == -1)
	{
		printf("erreur: impossible de lire %s\n", stock->pathspritew);
		stock->testfd++;
	}
	close(stock->fdw);
	if (stock->testfd > 0)
		exit(0);
}

void	verifpostmap(char **map, int i)
{
	int	j;

	j = 0;
	i++;
	while (map[i])
	{
		while (map[i][j])
		{
			if (map[i][j] != 32 && map[i][j] != '\t' && map[i][j] != '\n')
			{
				printf("erreur: characteres presents apres la definition map\n");
				exit (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
}
