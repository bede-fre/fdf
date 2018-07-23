/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:42:53 by bede-fre          #+#    #+#             */
/*   Updated: 2018/07/23 18:37:07 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void		ft_display(t_values *val, t_stock *list)
{
	t_stock	*line;
	t_stock	*col;

	val->first = 0;
	col = list;
	while (col)
	{
		line = col;
		while (line)
		{
			if (line->n_x)
				ft_algo(val, line, line->n_x, line->color);
			if (line->n_y)
			{
				if (val->first == 0)
					val->first = 1;
				else
					ft_algo(val, line, line->n_y, line->color);
			}
			line = line->n_x;
		}
		col = col->n_y;
	}
	mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img, 0, 0);
}

static void	ft_rev_display(t_values *val, t_stock *list)
{
	t_stock	*line;
	t_stock	*col;

	col = list;
	while (col)
	{
		line = col;
		while (line)
		{
			if (line->p_x)
				ft_algo(val, line, line->p_x, line->color);
			if (line->p_y)
				ft_algo(val, line, line->p_y, line->color);
			line = line->p_x;
		}
		col = col->p_y;
	}
	mlx_put_image_to_window(val->draw.mlx, val->draw.win, val->draw.img, 0, 0);
}

static void	ft_move_zoom(int key, t_values *val)
{
	if (key == KEY_C)
		val->draw.zoom += 5;
	if (key == KEY_Z)
		val->draw.zoom -= 5;
	if (key == KEY_A)
		val->draw.var_x -= 10;
	if (key == KEY_D)
		val->draw.var_x += 10;
	if (key == KEY_S)
		val->draw.var_y += 10;
	if (key == KEY_W)
		val->draw.var_y -= 10;
}

static void	ft_rotate(int key, t_values *val)
{
	if (key == KEY_Q)
	{
		if (val->draw.r > 0.0 * (M_PI / 180.0))
			val->draw.r -= 10.0 * (M_PI / 180.0);
		else
			val->draw.r = 350.0 * (M_PI / 180.0);
	}
	if (key == KEY_E)
	{
		if (val->draw.r < 350.0 * (M_PI / 180.0))
			val->draw.r += 10.0 * (M_PI / 180.0);
		else
			val->draw.r = 0.0 * (M_PI / 180.0);
	}
}

int			ft_deal_key(int key, t_values *val)
{
	mlx_clear_window(val->draw.mlx, val->draw.win);
	mlx_destroy_image(val->draw.mlx, val->draw.img);
	val->draw.img = mlx_new_image(val->draw.mlx, val->draw.w_win,
		val->draw.l_win);
	val->draw.s_px = mlx_get_data_addr(val->draw.img, &val->draw.bpp,
		&val->draw.sz_ln_px, &val->draw.endian);
	ft_putnbr(key);
	ft_putchar('\n');
	if (key == KEY_C || key == KEY_Z || key == KEY_A || key == KEY_D
		|| key == KEY_S || key == KEY_W)
		ft_move_zoom(key, val);
	if (key == KEY_Q || key == KEY_E)
		ft_rotate(key, val);
	if (key == KEY_SPACE)
		ft_params_window(val);
	if ((val->draw.r > 46.0 * (M_PI / 180.0))
		&& (val->draw.r < 225.0 * (M_PI / 180.00)))
		ft_rev_display(val, val->last_link);
	else
		ft_display(val, val->first_link);
	if (key == KEY_ECHAP)
	{
		ft_free_lst(&val->first_link, 0);
		exit(0);
	}
	return (0);
}
