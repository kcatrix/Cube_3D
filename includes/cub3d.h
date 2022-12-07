/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcatrix <kcatrix@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 13:57:59 by tnicoue           #+#    #+#             */
/*   Updated: 2022/12/07 15:24:35 by kcatrix          ###   ########.fr       */
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
# include <math.h>
# include "../srcs/GNL/get_next_line.h"
# include "../mlx/mlx.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef struct s_stock
{
	char	**map;
	char	**mapf;
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

typedef struct s_wall
{
	void	*img;
	int		*buffer;
	int		w;
	int		h;
	int		bpp;
	int		sizel;
	int		endian;
}	t_wall;

typedef struct s_rayon
{
	int		x;
	int		y;
	double	dir_x;
	double	dir_y;
	double	delta_x;
	double	delta_y;
	double	side_x;
	double	side_y;
	int		step_x;
	int		step_y;
	double	dist;
	int		hit;
	int		side;
	double	wallx;
	int		nb;
	int		h;
}	t_rayon;

typedef struct s_3D
{
	int		xmouse;
	int		*buffer;
	int		sizel;
	int		bpp;
	void	*img;
	void	*mlx;
	void	*win;
	char	**map;
	int		floor[3];
	int		sky[3];
	double	pos_px;
	double	pos_py;
	char	dir;
	double	dirx;
	double	diry;
	double	planex;
	double	planey;
	int		columnheight;
	int		draw_start;
	int		draw_end;
	double	speed;
	double	rotspeed;
	t_wall	wall[4];
	t_rayon	rayon;
}	t_3D;

char	*get_next_line(int fd);
void	ft_pos_player(t_3D *r);
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
void	init_struct_3d(t_3D *r);
void	draw_floor(t_3D *r);
void	ft_dir_player(t_3D *r);
void	ft_init_val(t_3D *r);
void	ft_rayon(t_3D *g);
void	get_step(t_3D *g);
void	dda(t_3D *g);
void	raycasting(t_3D *g);
int		create_trgb(int t, int r, int g, int b);
void	last_parse(t_stock *s);
void	ft_verif_dir(t_stock *s);
void	ft_lexer(t_stock *s);
void	ft_lexer_f(t_stock *s, int i);
void	ft_lexer_c(t_stock *s, int i);
void	ft_lexer_virgule(t_stock *s, int i);
void	ft_fov(t_3D *r);
double	fov_gest(t_3D *r, int check);
void	draw_color(t_3D *g);
void	up(t_3D *g);
void	down(t_3D *g);
void	left(t_3D *g);
void	right(t_3D *g);
void	ft_createmap(t_stock *stock, int i);
int		ft_key_press(int key, t_3D *r);
void	texture_prep2(t_3D *g, int *texx);
void	draw_texture(t_3D *g, int start, int end);
t_wall	texture_prep(void *mlx, char *file);
void	ft_affecttext(t_stock *stock, t_3D *r);
void	newleft(t_3D *g);
void	newright(t_3D *g);
void	cammousel(t_3D *g);
void	cammouser(t_3D *g);
int		win_closed(t_3D *r);
#endif
