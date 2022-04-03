#include <mlx.h>
#include "fractol.h"
# include<stdlib.h>
# include<unistd.h>
# include<stdio.h>
// typedef struct s_data
// {
// 	int		i, j;
// 	void	*img;
// 	void	*addr;
// 	int		bits_per_pixle;
// 	int		line_length;
// 	int		endian;
// }		t_data;
void	draw(t_data *fractol);
int	closer(int keycode, t_data *var)
{
	mlx_destroy_window(var->mlx, var->mlx_win);
	return (0);
}

void	clear_redraw(t_data *var)
{
	mlx_destroy_image(var->mlx, var->img);
	var->img = mlx_new_image(var->mlx, 1000, 1000);
	draw(var);
	mlx_clear_window(var->mlx, var->mlx_win);
}

int	zoom(int keycode, int x, int y, t_data *fractol)
{
	double re_range = (fractol->maxr - fractol->minr) * 0.5;
	double im_range = (fractol->maxi - fractol->mini) * 0.5;
	if(keycode == 4)
	{
		fractol->minr = x - re_range / 2;
		fractol->mini = y  + im_range / 2;
		fractol->maxr = x + re_range / 2;
		fractol->maxi = y  + im_range / 2;
		fractol->itter += 2;
	}
	if(keycode == 5)
	{
		fractol->minr = re_range + (fractol->minr + x) * 1.1;
		fractol->mini = im_range + (fractol->mini + y) * 1.1;
		fractol->maxr = re_range + (fractol->maxr + x) * 1.1;
		fractol->maxi = im_range + (fractol->maxi + y) * 1.1;
		fractol->itter -= 2;
	}
	clear_redraw(fractol);
	return(0);
}



int	itter(double cr, double ci, double max)
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
		zr = zr * zr - zi * zi +cr;
		zi = 2*zi * tmp + ci;
		i++;
	}
	return (i);
}

void	draw(t_data *fractol)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	fractol->addr = (int *)mlx_get_data_addr(fractol->img, &fractol->bit_per_pixel, &fractol->line_lenght, &fractol->endian);
	while(x < 1000)
	{
		fractol->cr = fractol->minr + (fractol->maxr - fractol->minr) * x / 1000;
		y = 0;
		while(y < 1000)
		{
			fractol->ci = fractol->mini + (fractol->maxi - fractol->mini) * y / 1000;
			i = itter(fractol->cr, fractol->ci, fractol->itter);
			if (itter(fractol->cr, fractol->ci, fractol->itter) == fractol->itter)
			{
				fractol->addr[(y*1000) + x] = 0x000000;
			}
			else
				fractol->addr[(y*1000) + x] = 0xffffff*i;
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
	width = 1000;
	height = 1000;
	data.minr = -2;
	data.mini = -2;
	data.maxr = 2;
	data.maxi = 2;
	data.itter = 80;
	data.mlx_win = mlx_new_window(data.mlx, width, height, "fract-ol");
	data.img = mlx_new_image(data.mlx, 1000, 1000);
	draw(&data);

	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_key_hook(data.mlx_win, keycode, &data);
	mlx_hook(data.mlx_win, 4, 0, &zoom, &data);

	//mlx_hook(data.mlx_win, 2, )
	mlx_loop(data.mlx);
}
