/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing4.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:40:50 by tnicoue           #+#    #+#             */
/*   Updated: 2022/12/07 13:16:35 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	chkdoublon2(char **str)
{
	if (!str)
		return (0);
	else
	{
		printf("Il y a un doublon dans les lettres\n");
		exit (0);
	}
}

void	last_parse(t_stock *s)
{
	int	i;

	i = 1;
	while (s->pathspritee[i] != '.')
		i++;
	if (strcmp(s->pathspritee + i, ".xpm") != 0)
		exit(printf("erreur chemin sprite E\n"));
	i = 1;
	while (s->pathspriten[i] != '.')
		i++;
	if (strcmp(s->pathspriten + i, ".xpm") != 0)
		exit(printf("erreur chemin sprite N\n"));
	i = 1;
	while (s->pathsprites[i] != '.')
		i++;
	if (strcmp(s->pathsprites + i, ".xpm") != 0)
		exit(printf("erreur chemin sprite S\n"));
	i = 1;
	while (s->pathspritew[i] != '.')
		i++;
	if (strcmp(s->pathspritew + i, ".xpm") != 0)
		exit(printf("erreur chemin sprite W\n"));
	ft_verif_dir(s);
}

void	ft_verif_dir(t_stock *s)
{
	if (open(s->pathspritee, O_DIRECTORY) == 0)
		exit(printf("erreur chemin E est un dossier\n"));
	if (open(s->pathspriten, O_DIRECTORY) == 0)
		exit(printf("erreur chemin N est un dossier\n"));
	if (open(s->pathsprites, O_DIRECTORY) == 0)
		exit(printf("erreur chemin S est un dossier\n"));
	if (open(s->pathspritew, O_DIRECTORY) == 0)
		exit(printf("erreur chemin W est un dossier\n"));
}

void	ft_lexer(t_stock *s)
{
	int		i;
	int		y;
	char	**mapspli;

	i = 0;
	y = 0;
	while (s->map[i])
	{
		mapspli = ft_split(s->map[i], 32);
		if (mapspli[0][0] == 'C')
			ft_lexer_c(s, i);
		if (mapspli[0][0] == 'F')
			ft_lexer_f(s, i);
		free_tab(mapspli);
		i++;
	}
}

void	ft_lexer_c(t_stock *s, int i)
{
	int	y;

	y = 2;
	while (s->map[i][0] == ' ')
		rm_char(s->map[i], 0);
	while (s->map[i][y] != '\0')
	{
		while (s->map[i][y] == ' ')
			rm_char(s->map[i], y);
		y++;
	}
	ft_lexer_virgule(s, i);
}
