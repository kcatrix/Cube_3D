/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 09:24:18 by tnicoue           #+#    #+#             */
/*   Updated: 2022/12/07 13:38:27 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	openmap(char **av, int *y)
{
	int		fd;
	int		i;
	char	*mappath;

	i = 0;
	while (av[1][i] != '.')
		i++;
	if (strcmp(av[1] + i, ".cub") != 0)
	{
		printf("Format de la map non valide\n");
		return (-1);
	}
	mappath = strdup(av[1]);
	fd = open(mappath, O_RDONLY, 0777);
	if (fd == -1)
		return (err_mapnotfound());
	else
		(*y) = ft_lenghtmap(fd, mappath);
	free(mappath);
	return (fd);
}

int	ft_lenghtmap(int fd, char *mappath)
{
	char	*line;
	int		y;

	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	fd = open(mappath, O_RDONLY, 0777);
	return (y);
}

int	formatmap(int fd, t_stock *stock, int y)
{
	int	i;

	stock->map = malloc(sizeof(char *) * (y + 1));
	i = 0;
	while (i < y)
	{
		stock->map[i] = get_next_line(fd);
		i++;
	}
	stock->map[i] = NULL;
	close(fd);
	i = 0;
	ft_lexer(stock);
	return (0);
}

int	checkmapdebut(char **map, t_stock *stock)
{
	int	i;
	int	j;
	int	indice;
	int	nbformat;

	nbformat = 0;
	j = 0;
	i = 0;
	while (map[i] && nbformat < 6)
	{
		while (checkspace(map[i]) == 1)
			i++;
		indice = verifind(map[i], stock);
		if (indice == -1)
			err_parse();
		if (map[i] != NULL)
			i++;
		nbformat++;
	}
	checkmapfin(map, i, stock);
	return (0);
}

int	checkspace(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\n')
		return (1);
	return (0);
}
