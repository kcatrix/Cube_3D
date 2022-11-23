/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errparsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:31:07 by tnicoue           #+#    #+#             */
/*   Updated: 2022/11/18 10:16:19 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	err_parse(void)
{
	printf("contenu de la map invalide\n");
	exit (0);
}

int	err_mapnotfound(void)
{
	printf("Le fichier specifie est introuvable\n");
	return (-1);
}

void	ft_errplayer(t_stock *stock)
{
	if (stock->playernb != 1)
	{
		printf("Erreur: il n'y a pas le bon nombre de Joueurs\n");
		exit(0);
	}
}
