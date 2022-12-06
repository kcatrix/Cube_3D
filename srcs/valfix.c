/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valfix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tnicoue <tnicoue@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 09:39:22 by tnicoue           #+#    #+#             */
/*   Updated: 2022/12/06 13:26:50 by tnicoue          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	valfix(t_stock *stock)
{
	ft_valfix(stock->pathsprites);
	ft_valfix(stock->pathspriten);
	ft_valfix(stock->pathspritew);
	ft_valfix(stock->pathspritee);
	ft_valfix2(stock->valc);
	ft_valfix2(stock->valf);
	stock->valcfix1 = ft_atoi(stock->valc[0]);
	stock->valcfix2 = ft_atoi(stock->valc[1]);
	stock->valcfix3 = ft_atoi(stock->valc[2]);
	stock->valffix1 = ft_atoi(stock->valf[0]);
	stock->valffix2 = ft_atoi(stock->valf[1]);
	stock->valffix3 = ft_atoi(stock->valf[2]);
	ft_checkval(stock);
}

void	ft_valfix(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	str[i] = '\0';
}

void	ft_valfix3(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[i][j])
		{
			if (!(str[i][j] >= '0' && str[i][j] <= '9'))
			{
				printf("caracteres de C / F non numeriques, erreur");
				exit (0);
			}
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_valfix2(char **str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
		i++;
	while (str[i - 1][j] != '\n')
		j++;
	str[i - 1][j] = '\0';
	i = 0;
	ft_valfix3(str);
}
