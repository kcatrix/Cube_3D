/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 11:05:57 by tnicoue           #+#    #+#             */
/*   Updated: 2022/11/18 10:15:33 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (tab[i])
		{
			free(tab[i]);
			i++;
		}
		free(tab);
	}
}

int	verifind(char *line, t_stock *stock)
{
	char	**line2;
	int		i;

	i = -1;
	line2 = ft_split(line, ' ');
	i = verifind2(line2, i);
	valaffect(i, stock, line2);
	free_tab(line2);
	return (i);
}

int	verifind2(char **line2, int i)
{
	if ((line2[0][0] == 'S' && line2[0][1] == '\0')
		|| (line2[0][0] == 'S' && line2[0][1] == 'O' && line2[0][2] == '\0'))
		i = 1;
	else if ((line2[0][0] == 'N' && line2[0][1] == '\0')
		|| (line2[0][0] == 'N' && line2[0][1] == 'O' && line2[0][2] == '\0'))
		i = 2;
	else if ((line2[0][0] == 'E' && line2[0][1] == '\0')
		|| (line2[0][0] == 'E' && line2[0][1] == 'A' && line2[0][2] == '\0'))
		i = 3;
	else if ((line2[0][0] == 'W' && line2[0][1] == '\0')
		|| (line2[0][0] == 'W' && line2[0][1] == 'E' && line2[0][2] == '\0'))
		i = 4;
	else if (line2[0][0] == 'C' && line2[0][1] == '\0')
		i = 5;
	else if (line2[0][0] == 'F' && line2[0][1] == '\0')
		i = 6;
	else
		err_parse();
	return (i);
}

void	valaffect(int i, t_stock *stock, char **line)
{
	printf("line2[1] = %s, i = %d\n", line[1], i);
	if (i == 1 && chkdoublon(stock->pathsprites) == 0)
		stock->pathsprites = ft_strdup(line[1]);
	if (i == 2 && chkdoublon(stock->pathspriten) == 0)
		stock->pathspriten = ft_strdup(line[1]);
	if (i == 3 && chkdoublon(stock->pathspritee) == 0)
		stock->pathspritee = ft_strdup(line[1]);
	if (i == 4 && chkdoublon(stock->pathspritew) == 0)
		stock->pathspritew = ft_strdup(line[1]);
	if (i == 5 && chkdoublon2(stock->valc) == 0)
		stock->valc = ft_split(line[1], ',');
	if (i == 6 && chkdoublon2(stock->valf) == 0)
		stock->valf = ft_split(line[1], ',');
}

int	chkdoublon(char *str)
{
	if (!str)
		return (0);
	else
	{
		printf("Il y a un doublon dans les lettres\n");
		exit (0);
	}
}
