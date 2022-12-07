/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing5.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 13:16:46 by tnicoue           #+#    #+#             */
/*   Updated: 2022/12/07 13:17:28 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_lexer_f(t_stock *s, int i)
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

void	ft_lexer_virgule(t_stock *s, int i)
{
	int	y;

	y = 2;
	if (s->map[i][y] == ',')
		exit(printf("erreur couleur\n"));
	while (ft_isdigit(s->map[i][y]) == 1)
		y++;
	if (s->map[i][y++] != ',')
		exit(printf("erreur couleur\n"));
	if (ft_isdigit(s->map[i][y]) == 0)
		exit(printf("erreur couleur\n"));
	while (ft_isdigit(s->map[i][y]) == 1)
		y++;
	if (s->map[i][y++] != ',')
		exit(printf("erreur couleur\n"));
	if (ft_isdigit(s->map[i][y]) == 0)
		exit(printf("erreur couleur\n"));
	while (ft_isdigit(s->map[i][y]) == 1)
		y++;
	if (s->map[i][y] != '\n')
		exit(printf("erreur  fin couleur\n"));
}
