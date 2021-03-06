/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:53:11 by bede-fre          #+#    #+#             */
/*   Updated: 2019/01/24 14:28:48 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "libft.h"
# include "mlx.h"
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define KEY_Q 12
# define KEY_W 13
# define KEY_E 14
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_Z 6
# define KEY_X 7
# define KEY_C 8
# define KEY_R 15
# define KEY_F 3
# define KEY_SPACE 49
# define KEY_ECHAP 53
# define WINX 800
# define WINY 600
# define DEFAULT_COLOR 0xFFFFFF

typedef struct		s_stock
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				a;
	int				b;
	struct s_stock	*n_x;
	struct s_stock	*n_y;
	struct s_stock	*p_x;
	struct s_stock	*p_y;
}					t_stock;

typedef struct		s_col
{
	unsigned char	r1;
	unsigned char	g1;
	unsigned char	b1;
	unsigned char	r2;
	unsigned char	g2;
	unsigned char	b2;
	short			d_r1;
	short			d_g1;
	short			d_b1;
	short			d_r2;
	short			d_g2;
	short			d_b2;
	unsigned char	l_s_r;
	unsigned char	l_s_g;
	unsigned char	l_s_b;
	unsigned char	l_e_r;
	unsigned char	l_e_g;
	unsigned char	l_e_b;
}					t_col;

typedef struct		s_algo
{
	int				da;
	int				db;
	int				i;
	int				cpta;
	int				cptb;
	int				cumul;
	int				a;
	int				b;
}					t_algo;

typedef struct		s_draw
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*s_px;
	int				endian;
	int				bpp;
	int				sz_ln_px;
	double			zoom;
	double			l_win;
	double			w_win;
	int				var_x;
	int				var_y;
	double			r;
}					t_draw;

typedef struct		s_values
{
	char			**tab;
	int				x_max;
	int				y_max;
	int				ln;
	int				cl;
	int				z_min;
	int				z_max;
	int				z_range;
	double			z_val;
	char			first;
	char			auto_rot;
	t_stock			*tp_y;
	t_stock			*tp_x;
	t_stock			*first_link;
	t_stock			*last_link;
	t_stock			*first_x;
	t_col			col;
	t_algo			algo;
	t_draw			draw;
}					t_values;

t_values			*ft_read_stock(int fd, char **line);
void				ft_params_window(t_values *val);
void				ft_free_lst(t_stock **list, char error);
void				ft_val_z_stock(t_values *val, char **tp);
void				ft_quit_line_more(t_values *val);
void				ft_quit_line_less(t_values *val);
void				ft_color_range(t_values *val);
void				ft_display(t_values *val, t_stock *list);
int					ft_deal_key(int key, t_values *val);
void				ft_gradient_col(t_values *val, t_stock *lst, t_stock *next);
void				ft_algo(t_values *val, t_stock *lst, t_stock *st, int col);
void				ft_proj_iso(t_stock *lst, t_stock *st, t_values *val);
int					ft_merge_color(unsigned char red, unsigned char green,
					unsigned char blue);

#endif
