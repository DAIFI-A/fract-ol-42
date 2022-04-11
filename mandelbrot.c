#include <mlx.h>
#include"fractol.h"
#include<stdlib.h>
#include<unistd.h>
# include<stdio.h>

// int	itter(double cr, double ci, double max, t_data *fra)
// {
// 	double	zr;
// 	double	zi;
// 	double	tmp;
// 	int		i;

// 	zr = 0;
// 	zi = 0;
// 	i = 0;
// 	while(i < max && (zr * zr + zi * zi) < 4)
// 	{
// 		tmp = zr;
// 		zr = zr * zr - zi * zi + cr;
// 		zi = 2*zi * tmp + ci;
// 		i++;
// 	}
// 	return (i);
// }

void	draw_mand(t_data *fractol)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	fractol->addr = (int *)mlx_get_data_addr(fractol->img, &fractol->bit_per_pixel, &fractol->line_lenght, &fractol->endian);
	while(x < 500)
	{
		fractol->cr = fractol->minr + (fractol->maxr - fractol->minr) * x / 500;
		y = 0;
		while(y < 500)
		{
			fractol->ci = fractol->mini + (fractol->maxi - fractol->mini) * y / 500;
			i = itter(fractol->cr, fractol->ci, fractol->itter, fractol);
			if (i == fractol->itter)
			{
				fractol->addr[(y*500) + x] = 0x000000;
			}
			else
				fractol->addr[(y*500) + x] = 0xffffff*i;
			y++;
		}
		x++;
	}
}

void	ft_mand(t_data *data)
{
	data->minr = -2;
	data->mini = -2;
	data->maxr = 2;
	data->maxi = 2;
	data->itter = 250;
	draw_mand(data);
}
