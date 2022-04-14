/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   burningship.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:26:15 by adaifi            #+#    #+#             */
/*   Updated: 2022/04/13 23:14:38 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	itter2(double cr, double ci, double max)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0;
	zi = 0;
	i = 0;
	while (i < max && (fabs(zr * zr) + fabs(zi * zi)) <= 4)
	{
		tmp = fabs(zr);
		zr = fabs(zr * zr) - fabs(zi * zi) + cr;
		zi = 2 * fabs(zi) * tmp + ci;
		i++;
	}
	return (i);
}

void	draw_burn(t_data *fractol)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	while (x < 500)
	{
		fractol->cr = fractol->minr + (fractol->maxr - fractol->minr) * x / 500;
		y = 0;
		while (y < 500)
		{
			fractol->ci = fractol->mini + (fractol->maxi - fractol->mini)
				* y / 500;
			i = itter2(fractol->cr, fractol->ci, fractol->itter);
			if (i == fractol->itter)
				fractol->addr[(y * 500) + x] = 0x000000;
			else
				fractol->addr[(y * 500) + x] = 0xffffff * i;
			y++;
		}
		x++;
	}
}

void	ft_burn(t_data *data)
{
	data->minr = -2;
	data->mini = -2;
	data->maxr = 2;
	data->maxi = 2;
	data->itter = 250;
	draw_burn(data);
}
