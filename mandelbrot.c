#include <mlx.h>
#include "fractol.h"
# include<stdlib.h>
# include<unistd.h>
# include<stdio.h>
void	draw(t_data *fractol);
int	closer(int keycode, t_data *var)
{
	mlx_destroy_window(var->mlx, var->mlx_win);
	return (0);
}

void	clear_redraw(t_data *var)
{
	mlx_destroy_image(var->mlx, var->img);
	mlx_clear_window(var->mlx, var->mlx_win);
	var->img = mlx_new_image(var->mlx, 500, 500);
	draw(var);
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img, 0, 0);
}

int	zoom(int keycode, int x, int y, t_data *fractol)
{
	double re_range = fractol->minr + ((double)x * (fractol->maxr - fractol->minr)) / 500;
	double im_range = fractol->mini + ((double)y * (fractol->maxi - fractol->mini)) / 500;
	if(keycode == 4)
	{
		fractol->itter += 15;
		fractol->minr = re_range + (fractol->minr - re_range) * 0.9;
		fractol->mini = im_range + (fractol->mini - im_range) * 0.9;
		fractol->maxr = re_range + (fractol->maxr - re_range) * 0.9;
		fractol->maxi = im_range + (fractol->maxi - im_range) * 0.9;
	}
	if(keycode == 5)
	{
		fractol->minr = re_range + (fractol->minr - re_range) * 1.1;
		fractol->mini = im_range + (fractol->mini - im_range) * 1.1;
		fractol->maxr = re_range + (fractol->maxr - re_range) * 1.1;
		fractol->maxi = im_range + (fractol->maxi - im_range) * 1.1;
		fractol->itter -= 15;
	}
	clear_redraw(fractol);
	return(0);
}

int	itter(double cr, double ci, double max, t_data *fra)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0;
	zi = 0;
	i = 0;
	while(i < max && (zr * zr + zi * zi) <= 4)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + fra->zoomx;
		zi = 2*zi * tmp + fra->zoomy;
		i++;
	}
	return (i);
}

void	init(t_data *fra)
{
	fra->cr = (fra->x / 500) * (fra->maxr - fra->minr) + fra->minr;
	fra->ci = (fra->y / 500) * (fra->maxi - fra->mini) + fra->mini;
}

void	draw(t_data *fractol)
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
			if (itter(fractol->cr, fractol->ci, fractol->itter, fractol) == fractol->itter)
			{
				fractol->addr[(y*500) + x] = 0x000000;
			}
			else
				fractol->addr[(y*500) + x] = 0x0000ff*i;
			y++;
		}
		x++;
	}
}

int	keycode(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(1);
	return (1);
}

int main(int ac, char **av)
{
	t_data	data;
	int		width;
	int		height;

	data.mlx = mlx_init();
	width = 500;
	height = 500;
	data.zoomx = 0.285;
	data.zoomy = 0.013;
	data.minr = -2;
	data.mini = -2;
	data.maxr = 2;
	data.maxi = 2;
	data.itter = 250;
	data.mlx_win = mlx_new_window(data.mlx, width, height, "fract-ol");
	data.img = mlx_new_image(data.mlx, 500, 500);
	draw(&data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_key_hook(data.mlx_win, keycode, &data);
	mlx_hook(data.mlx_win, 4, 0, &zoom, &data);
	mlx_loop(data.mlx);
}
