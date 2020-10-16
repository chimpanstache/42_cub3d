/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehafidi <ehafidi@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 12:45:37 by stuntman          #+#    #+#             */
/*   Updated: 2020/10/15 17:34:07 by ehafidi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <stdio.h>
# include "../minilibx_mms/mlx.h"
# include <math.h>
# include <stddef.h>
# include "libft/libft.h"

typedef struct	s_point
{
	int		x;
	int		y;
	int		space;
	int		spr_n;
	char	nseorw;
	char	target;
}				t_point;

typedef struct	s_sprite
{
	double	x;
	double	y;
	double	distance;
}				t_sprite;

typedef struct	s_path
{
	char	*n;
	char	*e;
	char	*w;
	char	*s;
	char	*sp;
}				t_path;

typedef struct	s_color
{
	int		r;
	int		g;
	int		b;
}				t_color;

typedef struct	s_size
{
	int		scrn_w;
	int		scrn_h;
}				t_size;

typedef struct	s_parse
{
	int		r;
	int		no;
	int		so;
	int		we;
	int		ea;
	int		s;
	int		f;
	int		c;
	int		check_map;
}				t_parse;

typedef struct	s_texture
{
	void	*img;
	int		w;
	int		h;
	char	*ad;
	int		bpp;
	int		l_l;
	int		end;
	char	*p;
}				t_texture;

typedef struct	s_user_screen_data
{
	int		x;
	int		y;
}				t_user_screen_data;

typedef struct	s_parameters
{
	int					fd;
	int					ret;
	int					i;
	char				*l;
	int					check;
	int					info;
	int					error;
	char				**map_to_ff;
	char				*map_i_l;
	char				**arr;
	t_point				size2;
	t_point				begin;
	t_parse				parse;
	t_color				clr_clng;
	t_color				clr_flr;
	t_size				size;
	t_path				path;
	t_user_screen_data	usr_scrn;
	int					scr_h;
	int					scr_w;
	int					win_h;
	int					win_w;
	int					map_h;
	int					map_w;
	char				**map;
	int					nsprite;
	t_sprite			*sprites;
	char				*buf;
	int					flr_color;
	int					clg_color;
	t_texture			n_t;
	t_texture			s_t;
	t_texture			w_t;
	t_texture			e_t;
	t_texture			p_t;
	t_texture			tex;
	void				*img;
	char				*addr;
	int					bpp;
	int					l_l;
	int					endian;
	void				*mlx;
	void				*win;
	int					trgb;
	double				posx;
	double				posy;
	double				dirx;
	double				diry;
	double				planex;
	double				planey;
	double				time;
	double				oldtime;
	double				movespeed;
	double				rotspeed;
	double				frametime;
	double				olddirx;
	double				oldplanex;
	int					flr_clr;
	int					cl_clr;
	unsigned int		color;
	char				*tex_path;
	double				*zbuffer;
	char				*config_file_path;
	char				*save;
}				t_parameters;

typedef struct	s_rc_params
{
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapy;
	int			mapx;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		perpwalldist;
	int			stepx;
	int			stepy;
	int			hit;
	int			side;
	int			drawstart;
	int			drawend;
	int			lineheight;
	double		wallx;
	int			texx;
	int			texy;
	double		step;
	double		texpos;
}				t_rc_params;

typedef struct	s_sprite_params
{
	double		spritex;
	double		spritey;
	double		invdet;
	double		transx;
	double		transy;
	int			spritescreenx;
	int			spriteheight;
	int			drawstarty;
	int			drawendy;
	int			spritewidth;
	int			drawstartx;
	int			drawendx;
	int			texx;
	int			texy;
	int			d;
}				t_sprite_params;

typedef struct	s_sprites_parameters
{
	double	invdet;
	double	transformx;
	double	transformy;
	int		spritescreenx;
	int		spriteheight;
	int		spritewidth;
	int		drawstartx;
	int		drawstarty;
	int		drawendx;
	int		drawendy;
	int		texx;
}				t_sprites_parameters;

typedef struct	s_bmp
{
	int					bmp_size;
	int					bytes_width;
	int					pad_size;
	int					fd;
	unsigned char		*fileheader;
	unsigned char		*imageheader;
	int					i;
	int					j;
	int					r;
	int					g;
	int					b;
}				t_bmp;

# define MAX_WINDOW_WIDTH 2560
# define MAX_WINDOW_HEIGHT 1440

# define NORTH 3
# define SOUTH 4
# define EAST 5
# define WEST 6
# define MSPEED 0.3
# define RSPEED 0.27
# define TEXWIDTH 64
# define TEXHEIGHT 64

void			parse_map(t_parameters *prs);
char			*ft_chrstr(int c, const char *str);
void			init_prs(t_parameters *prs);
void			parse_line(t_parameters *prs);
int				check_map_place(t_parameters *prs);
void			get_screen_size(t_parameters *prs);
void			get_color_clng(t_parameters *prs);
void			get_color_flr(t_parameters *prs);
void			get_info_line(t_parameters *prs);
int				check_line(t_parameters *prs);
void			verify_parse(t_parameters *prs);
int				verify_color(t_parameters *prs);
int				verify_dimensions(t_parameters *prs);
void			error_msg(int err);
int				parse_elements(t_parameters *prs);
void			parser(t_parameters *prs);
int				create_trgb(int t, int r, int g, int b);
void			free_arr(t_parameters *prs);
void			free_map(t_parameters *prs);
void			free_map_to_ff(t_parameters *prs);
int				ft_is_scnd_char(char c);
int				ft_is_alpha_maj(char c);
void			check_arr(t_parameters *p);
void			check_arr_2(t_parameters *p);
void			check_arr_each_line(t_parameters *p, char *l);
void			check_flr_clg(t_parameters *prs);

void			move_left(t_parameters *data);
void			move_right(t_parameters *data);
void			move_forward(t_parameters *data);
void			move_backward(t_parameters *data);
int				keyhandle(int keycode, t_parameters *data);
void			watch_left(t_parameters *data);
void			watch_right(t_parameters *data);
void			escape(t_parameters *data);

int				close_window();
void			free_all(t_parameters *data);

int				raycaster(t_parameters *data);

void			init_raycast(t_parameters *data, t_rc_params *p, int x);
void			calc_step_and_sidedist(t_rc_params *p, t_parameters *data);
void			perform_dda(t_parameters *data, t_rc_params *p);
void			calculate_distance_pixel_wallx(t_rc_params *p,
t_parameters *data);
void			getting_ready_to_render(t_rc_params *p, t_parameters *data);
void			wall_caster(t_parameters *data);

void			sort_sprite_distance(t_parameters *data);
void			init_sprite_values(t_sprite_params *s,
t_parameters *data, int i);
void			render_sprite(t_sprite_params *s, int stripe,
t_parameters *data);

int				count_lines(t_parameters *prs);
int				count_width(t_parameters *prs);
void			create_map(t_parameters *prs);
void			create_map_test(t_parameters *prs);

void			get_info_line(t_parameters *prs);
char			*get_path(t_parameters *prs, char *path);

int				ft_isprint_wtht_space_digit(int c);
void			get_color_clng(t_parameters *prs);
void			get_color_flr(t_parameters *prs);
void			get_screen_size(t_parameters *prs);

void			f_fill(char **tab, t_point *size, int row, int col);
void			flood_fill(char **tab, t_point *size, t_point *begin);
void			init_prs_1(t_parameters *prs);

int				verify_infos(t_parameters *prs);

unsigned char	*create_file_header(int bmp_size);
unsigned char	*create_image_header(t_parameters *prs);
void			create_image(t_parameters *prs);

void			set_window_properly(t_parameters *data);
void			generate_picture(t_parameters *d);
int				view(t_parameters *data);
void			hooks_manager(t_parameters *data);

void			set_spawn_params(int x, int y, t_parameters *d);
void			set_spawn_params_2(int x, int y, t_parameters *d);

#endif
