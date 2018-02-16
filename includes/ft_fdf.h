/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fdf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/25 14:53:11 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/16 11:43:26 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_FDF_H
# define FT_FDF_H

# include "libft.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>

# define WHITE_COLOR 0xFFFFFF

typedef struct		s_stock
{
	int				x;
	int				y;
	int				z;
	int				color;
	int				x_2d;
	int				y_2d;
	struct s_stock	*n_x;
	struct s_stock	*n_y;
	struct s_stock	*p_x;
	struct s_stock	*p_y;
}					t_stock;

typedef struct		s_values
{
	int				x_max;
	int				y_max;
	int				ln;
	int				cl;
	int				z_min;
	int				z_max;
	int				z_range;
	void			*mlx;
	void			*win;
	void			*img;
	char			*s_px;
	int				endian;
	int				bpp;
	int				sz_ln_px;
	int				color;
	struct s_stock	*tp_y;
	struct s_stock	*tp_x;
	struct s_stock	*first_link;
	struct s_stock	*first_x;
	struct s_mlx	*init;
}					t_values;

void				ft_val_z_stock(t_values *val, char **tp);
void				ft_color_range(t_values *val);
void				ft_free_lst(t_stock **list);
void				ft_stock_x_max(t_values *val);
void				ft_quit_line_more(t_values *val);
void				ft_quit_line_less(t_values *val);
t_values			*ft_read_stock(int fd, char **line);

#endif