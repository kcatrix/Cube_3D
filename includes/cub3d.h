/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kevyn <kevyn@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:57:59 by tnicoue           #+#    #+#             */
/*   Updated: 2022/11/23 17:44:33 by kevyn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../lib/libft/libft.h"
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <fcntl.h>
# include <signal.h>
# include <stdlib.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/wait.h>
# include <termios.h>
# include "../srcs/GNL/get_next_line.h"
# include "../mlx/mlx.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_stock
{
	char	**map;
	char	*pathspriten;
	char	*pathsprites;
	char	*pathspritew;
	char	*pathspritee;
	int		fds;
	int		fdn;
	int		fdw;
	int		fde;
	int		testfd;

	int		valcfix1;
	int		valcfix2;
	int		valcfix3;
	int		valffix1;
	int		valffix2;
	int		valffix3;
	int		vmax;
	int		vmin;
	int		debut;
	int		fin;
	char	**valc;
	char	**valf;
	int		playernb;
}	t_stock;

typedef struct s_3D
{
	int		*buffer;
	int		sizel;
	int		bpp;
	void	*img;
	void	*mlx;
	void	*win;
	char 	**map;
	int		floor[3];
	int		sky[3];
}	t_3D;

char	*get_next_line(int fd);
int		compteur_sot(char *stock);
char	*after(char	**stock, int i);
char	*end(char **stock);
int		openmap(char **av, int *y);
int		formatmap(int fd, t_stock *stock, int y);
int		checkspace(char *line);
int		checkmapdebut(char **map, t_stock *stock);
int		verifind(char *line, t_stock *stock);
void	err_parse(void);
int		err_mapnotfound(void);
int		ft_lenghtmap(int fd, char *mappath);
void	free_tab(char **tab);
void	valaffect(int i, t_stock *stock, char **line);
void	valfix(t_stock *stock);
void	ft_valfix(char *str);
void	init_struct(t_stock *stock);
void	ft_valfix2(char **str);
int		chkdoublon(char *str);
int		chkdoublon2(char **str);
void	ft_valfix3(char **str);
void	ft_checkval(t_stock *stock);
void	checkmapfin(char **map, int i, t_stock *stock);
void	ft_checkmapwall(char **map, int i);
void	ft_checkmapchar(char **map, int i);
void	ft_checkmapplayer(char **map, int i, t_stock *stock);
void	ft_checkaround(int i, size_t j, char **map);
void	ft_checkaround2(int i, size_t j, char **map);
void	ft_checkbeginend(char **map, int i);
void	ft_checkopen(t_stock *stock);
int		verifind2(char **line2, int i);
void	ft_checkopen2(t_stock *stock);
void	ft_errplayer(t_stock *stock);
void	verifpostmap(char **map, int i);
void	ft_cree_map(t_stock *stock, t_3D *next);
char	**ft_malloc_map(t_stock *stock, t_3D *r, int i);
void	ft_start_cube(t_3D *r);
void	init_struct_r(t_stock *stock, t_3D *r);
void	ft_cree_floor(t_stock *stock, t_3D *r);
void	ft_cree_sky(t_stock *stock, t_3D *r);
void	ft_cree_floor_loop(t_stock *stock, t_3D *r, int i, int y);
void	ft_cree_sky_loop(t_stock *stock, t_3D *r, int i, int y);
int		deal_key(int key, t_3D *r);
void	init_struct_r(t_stock *stock, t_3D *r);
void	init_struct_3D(t_3D *r);
void	draw_floor(t_3D *r);

#endif
