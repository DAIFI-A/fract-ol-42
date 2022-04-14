/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_redraw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:30:59 by adaifi            #+#    #+#             */
/*   Updated: 2022/04/13 23:14:23 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

void	clear_redraw(t_data *var)
{
	mlx_destroy_image(var->mlx, var->img);
	var->img = mlx_new_image(var->mlx, 500, 500);
	mlx_clear_window(var->mlx, var->mlx_win);
	if (var->id == 2)
		draw_julia(var);
	else if (var->id == 1)
		draw_mand(var);
	else if (var->id == 3)
		draw_burn(var);
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img, 0, 0);
}

int	mosse_mov(int x, int y, t_data *fra)
{
	fra->zoom.corx = fra->minr + (fra->maxr - fra->minr) * x / 500;
	fra->zoom.cory = fra->mini + (fra->maxi - fra->mini) * y / 500;
	clear_redraw(fra);
	return (0);
}

int	zoom(int keycode, int x, int y, t_data *fractol)
{
	double	im_range;
	double	re_range;

	re_range = fractol->minr
		+ ((double)x * (fractol->maxr - fractol->minr)) / 500;
	im_range = fractol->mini
		+ ((double)y * (fractol->maxi - fractol->mini)) / 500;
	if (keycode == 4)
	{
		fractol->itter += 2;
		fractol->minr = re_range + (fractol->minr - re_range) * 0.9;
		fractol->mini = im_range + (fractol->mini - im_range) * 0.9;
		fractol->maxr = re_range + (fractol->maxr - re_range) * 0.9;
		fractol->maxi = im_range + (fractol->maxi - im_range) * 0.9;
	}
	if (keycode == 5)
	{
		fractol->minr = re_range + (fractol->minr - re_range) * 1.1;
		fractol->mini = im_range + (fractol->mini - im_range) * 1.1;
		fractol->maxr = re_range + (fractol->maxr - re_range) * 1.1;
		fractol->maxi = im_range + (fractol->maxi - im_range) * 1.1;
		fractol->itter -= 2;
	}
	clear_redraw(fractol);
	return (0);
}
