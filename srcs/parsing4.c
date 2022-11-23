/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing6.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:40:50 by tnicoue           #+#    #+#             */
/*   Updated: 2022/11/18 09:42:46 by tnicoue          ###   ########.fr       */
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
