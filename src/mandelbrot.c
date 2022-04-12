#include <mlx.h>
#include"../fractol.h"
#include<stdlib.h>
#include<unistd.h>
# include<stdio.h>

int	itter1(double cr, double ci, double max)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = 0;
	zi = 0;
	i = 0;
	while(i < max && (zr * zr + zi * zi) < 4)
	{
		tmp = zr;
		zr = zr * zr - zi * zi + cr;
		zi = 2*zi * tmp + ci;
		i++;
	}
	return (i);
}

void	draw_mand(t_data *fractol)
{
	int		x;
	int		y;
	int		i;

	x = 0;
	while(x < 500)
	{
		fractol->cr = fractol->minr + (fractol->maxr - fractol->minr) * x / 500;
		y = 0;
		while(y < 500)
		{
			fractol->ci = fractol->mini + (fractol->maxi - fractol->mini) * y / 500;
			i = itter1(fractol->cr, fractol->ci, fractol->itter);
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

// int main(int argc, char **argv)
// {
// 	t_data fra;

// 	fra.mlx = mlx_init();
// 	fra.mlx_win = mlx_new_window(fra.mlx, 500, 500, "fract-ol");
// 	fra.img = mlx_new_image(fra.mlx, 500, 500);
// 		ft_mand(&fra);
// 	mlx_put_image_to_window(fra.mlx, fra.mlx_win, fra.img, 0, 0);
// 	mlx_key_hook(fra.mlx_win, keycode, &fra);
// 	mlx_hook(fra.mlx_win, 4, 0, &zoom, &fra);
// 	mlx_hook(fra.mlx_win, 6, 0, &mosse_mov, &fra);
// 	mlx_hook(fra.mlx_win, 17, 0, &closer, &fra);
// 	mlx_loop(fra.mlx);
// 	return 0;
// }
