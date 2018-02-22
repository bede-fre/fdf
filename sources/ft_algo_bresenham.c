/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo_bresenham.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bede-fre <bede-fre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 13:28:36 by bede-fre          #+#    #+#             */
/*   Updated: 2018/02/22 15:05:59 by bede-fre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_fdf.h"

void	ft_algo(t_values *data, t_stock *lst, t_stock *st, int color)
{
	int		dx;
	int		dy;
	int		e;
	int		a1;
	int		a2;
	int		b1;
	int		b2;
	float	cpt_r;
	float	cpt_g;
	float	cpt_b;

	ft_proj_iso(lst, st, data);
	a1 = (lst->a);
	a2 = (st->a);
	b1 = (lst->b);
	b2 = (st->b);
	//color = (color != (int)(NULL) ? color : ft_merge_color(data->color->l_s_r, data->color->l_s_g, data->color->l_s_b));
	ft_gradient_color(data, lst, st);
	if ((dx = (a2 - a1)) != 0)
	{
		if (dx > 0)
		{
			if ((dy = (b2 - b1)) != 0)
			{
				if (dy > 0)
				{
					if (dx >= dy)
					{
						cpt_r = (float)(data->color->d_r_px) / (float)(dx);
						cpt_g = (float)(data->color->d_g_px) / (float)(dx);
						cpt_b = (float)(data->color->d_b_px) / (float)(dx);
						e = dx;
						dx *= 2;
						dy = (dy * 2);
						while (1)
						{
							ft_fill_px(data, a1, b1, (color != (int)(NULL) ? color : ft_merge_color(data->color->l_s_r, data->color->l_s_g, data->color->l_s_b))); // nb_px = dy
							if ((a1 = (a1 + 1)) == a2)
								break;
							if ((e = (e - dy)) < 0)
							{
								b1 = (b1 + 1);
								e = (e + dx);
							}
							data->color->l_s_r += (unsigned char)(cpt_r);
							data->color->l_s_g += (unsigned char)(cpt_g);
							data->color->l_s_b += (unsigned char)(cpt_b);
						}
					}
					else
					{
						cpt_r = (float)(data->color->d_r_px) / (float)(dy);
						cpt_g = (float)(data->color->d_g_px) / (float)(dy);
						cpt_b = (float)(data->color->d_b_px) / (float)(dy);
						e = dy;
						dy *= 2;
						dx = (dx * 2);
						while (1)
						{
							ft_fill_px(data, a1, b1, (color != (int)(NULL) ? color : ft_merge_color(data->color->l_s_r, data->color->l_s_g, data->color->l_s_b))); // nb_px = dx
							if ((b1 = (b1 + 1)) == b2)
								break;
							if ((e = (e - dx)) < 0)
							{
								a1 = (a1 + 1);
								e = (e + dy);
							}
							data->color->l_s_r += (unsigned char)(cpt_r);
							data->color->l_s_g += (unsigned char)(cpt_g);
							data->color->l_s_b += (unsigned char)(cpt_b);
						}
					}
				}
				else
				{
					if (dx >= -dy)
					{
						cpt_r = (float)(data->color->d_r_px) / (float)(dx);
						cpt_g = (float)(data->color->d_g_px) / (float)(dx);
						cpt_b = (float)(data->color->d_b_px) / (float)(dx);
						e = dx;
						dx *= 2;
						dy = (dy * 2);
						while (1)
						{
							ft_fill_px(data, a1, b1, (color != (int)(NULL) ? color : ft_merge_color(data->color->l_s_r, data->color->l_s_g, data->color->l_s_b))); // nb_px = dy
							if ((a1 = (a1 + 1)) == a2)
								break;
							if ((e = (e + dy)) < 0)
							{
								b1 = (b1 - 1);
								e = (e + dx);
							}
							data->color->l_s_r += (unsigned char)(cpt_r);
							data->color->l_s_g += (unsigned char)(cpt_g);
							data->color->l_s_b += (unsigned char)(cpt_b);
						}
					}
					else
					{
						cpt_r = (float)(data->color->d_r_px) / (float)(dy);
						cpt_g = (float)(data->color->d_g_px) / (float)(dy);
						cpt_b = (float)(data->color->d_b_px) / (float)(dy);
						e = dy;
						dy *= 2;
						dx = (dx * 2);
						while (1)
						{
							ft_fill_px(data, a1, b1, (color != (int)(NULL) ? color : ft_merge_color(data->color->l_s_r, data->color->l_s_g, data->color->l_s_b))); // nb_px = dx
							if ((b1 = (b1 - 1)) == b2)
								break;
							if ((e = (e + dx)) > 0)
							{
								a1 = (a1 + 1);
								e = (e + dy);
							}
							data->color->l_s_r += (unsigned char)(cpt_r);
							data->color->l_s_g += (unsigned char)(cpt_g);
							data->color->l_s_b += (unsigned char)(cpt_b);
						}
					}
				}
			}
			else
			{
				cpt_r = (float)(data->color->d_r_px) / (float)(dy);
				cpt_g = (float)(data->color->d_g_px) / (float)(dy);
				cpt_b = (float)(data->color->d_b_px) / (float)(dy);
				while (a1 < a2)
				{
					ft_fill_px(data, a1, b1, (color != (int)(NULL) ? color : ft_merge_color(data->color->l_s_r, data->color->l_s_g, data->color->l_s_b))); // nb_px = dx
					data->color->l_s_r += (unsigned char)(cpt_r);
					data->color->l_s_g += (unsigned char)(cpt_g);
					data->color->l_s_b += (unsigned char)(cpt_b);
				}
			}
		}
		else
		{
			if ((dy = (b2 - b1)) != 0)
			{
				if (dy > 0)
				{
					if (-dx >= dy)
					{
						cpt_r = (float)(data->color->d_r_px) / (float)(dx);
						cpt_g = (float)(data->color->d_g_px) / (float)(dx);
						cpt_b = (float)(data->color->d_b_px) / (float)(dx);
						e = dx;
						dx *= 2;
						dy = (dy * 2);
						while (1)
						{
							ft_fill_px(data, a1, b1, (color != (int)(NULL) ? color : ft_merge_color(data->color->l_s_r, data->color->l_s_g, data->color->l_s_b))); // nb_px = dy
							if ((a1 = (a1 - 1)) == a2)
								break;
							if ((e = (e + dy)) >= 0)
							{
								b1 = (b1 + 1);
								e = (e + dx);
							}
							data->color->l_s_r += (unsigned char)(cpt_r);
							data->color->l_s_g += (unsigned char)(cpt_g);
							data->color->l_s_b += (unsigned char)(cpt_b);

						}
					}
					else
					{
						cpt_r = (float)(data->color->d_r_px) / (float)(dy);
						cpt_g = (float)(data->color->d_g_px) / (float)(dy);
						cpt_b = (float)(data->color->d_b_px) / (float)(dy);
						e = dy;
						dy *= 2;
						dx = (dx * 2);
						while (1)
						{
							ft_fill_px(data, a1, b1, (color != (int)(NULL) ? color : ft_merge_color(data->color->l_s_r, data->color->l_s_g, data->color->l_s_b))); // nb_px = dx
							if ((b1 = (b1 + 1)) == b2)
								break;
							if ((e = (e + dx)) <= 0)
							{
								a1 = (a1 - 1);
								e = (e + dy);
							}
							data->color->l_s_r += (unsigned char)(cpt_r);
							data->color->l_s_g += (unsigned char)(cpt_g);
							data->color->l_s_b += (unsigned char)(cpt_b);
						}
					}
				}
				else
				{
					if (dx <= dy)
					{
						cpt_r = (float)(data->color->d_r_px) / (float)(dx);
						cpt_g = (float)(data->color->d_g_px) / (float)(dx);
						cpt_b = (float)(data->color->d_b_px) / (float)(dx);
						e = dx;
						dx *= 2;
						dy = (dy * 2);
						while (1)
						{
							ft_fill_px(data, a1, b1, (color != (int)(NULL) ? color : ft_merge_color(data->color->l_s_r, data->color->l_s_g, data->color->l_s_b))); // nb_px = dy
							if ((a1 = (a1 - 1)) == a2)
								break;
							if ((e = (e - dy)) >= 0)
							{
								b1 = (b1 - 1);
								e = (e + dx);
							}
							data->color->l_s_r += (unsigned char)(cpt_r);
							data->color->l_s_g += (unsigned char)(cpt_g);
							data->color->l_s_b += (unsigned char)(cpt_b);
						}
					}
					else
					{
						cpt_r = (float)(data->color->d_r_px) / (float)(dy);
						cpt_g = (float)(data->color->d_g_px) / (float)(dy);
						cpt_b = (float)(data->color->d_b_px) / (float)(dy);
						e = dy;
						dy *= 2;
						dx = (dx * 2);
						while (1)
						{
							ft_fill_px(data, a1, b1, (color != (int)(NULL) ? color : ft_merge_color(data->color->l_s_r, data->color->l_s_g, data->color->l_s_b))); // nb_px = dx
							if ((b1 = (b1 - 1)) == b2)
								break;
							if ((e = (e - dx)) >= 0)
							{
								a1 = (a1 - 1);
								e = (e + dy);
							}
							data->color->l_s_r += (unsigned char)(cpt_r);
							data->color->l_s_g += (unsigned char)(cpt_g);
							data->color->l_s_b += (unsigned char)(cpt_b);
						}
					}
				}
			}
			else
			{
				cpt_r = (float)(data->color->d_r_px) / (float)(dy);
				cpt_g = (float)(data->color->d_g_px) / (float)(dy);
				cpt_b = (float)(data->color->d_b_px) / (float)(dy);
				while (a1 > a2)
				{
					ft_fill_px(data, a1--, b1, (color != (int)(NULL) ? color : ft_merge_color(data->color->l_s_r, data->color->l_s_g, data->color->l_s_b))); // nb_px = dx
					data->color->l_s_r += (unsigned char)(cpt_r);
					data->color->l_s_g += (unsigned char)(cpt_g);
					data->color->l_s_b += (unsigned char)(cpt_b);
				}
			}
		}
	}
	else
	{
		if ((dy = (b2 - b1)) != 0)
		{
			if (dy > 0)
			{
				cpt_r = (float)(data->color->d_r_px) / (float)(dx);
				cpt_g = (float)(data->color->d_g_px) / (float)(dx);
				cpt_b = (float)(data->color->d_b_px) / (float)(dx);
				while (b1 < b2)
				{
					ft_fill_px(data, a1, b1++, (color != (int)(NULL) ? color : ft_merge_color(data->color->l_s_r, data->color->l_s_g, data->color->l_s_b))); // nb_px = dy
					data->color->l_s_r += (unsigned char)(cpt_r);
					data->color->l_s_g += (unsigned char)(cpt_g);
					data->color->l_s_b += (unsigned char)(cpt_b);
				}
			}
			else
			{
				cpt_r = (float)(data->color->d_r_px) / (float)(dx);
				cpt_g = (float)(data->color->d_g_px) / (float)(dx);
				cpt_b = (float)(data->color->d_b_px) / (float)(dx);
				while (b1 > b2)
				{
					ft_fill_px(data, a1, b1--, (color != (int)(NULL) ? color : ft_merge_color(data->color->l_s_r, data->color->l_s_g, data->color->l_s_b))); // nb_px = dy
					data->color->l_s_r += (unsigned char)(cpt_r);
					data->color->l_s_g += (unsigned char)(cpt_g);
					data->color->l_s_b += (unsigned char)(cpt_b);
				}
			}
		}
	}
	ft_fill_px(data, a2, b2, color);
}
