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

int	closer(int keycode, t_data *var)
{
	mlx_destroy_window(var->mlx, var->mlx_win);
	return (0);
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
	double	x;
	double	y;
	int		i;

	x = 0;
	fractol->minr = -2;
	fractol->mini = -2;
	fractol->maxr = 2;
	fractol->maxi = 2;
	fractol->itter = 80;
	while(x <= 1000)
	{
		fractol->cr = fractol->minr + (fractol->maxr - fractol->minr) * x / 1000;
		y = 0;
		while(y <= 1000)
		{
			fractol->ci = fractol->mini + (fractol->maxi - fractol->mini) * y / 1000;
			i = itter(fractol->cr, fractol->ci, fractol->itter);
			if (itter(fractol->cr, fractol->ci, fractol->itter) == fractol->itter)
			{
				mlx_pixel_put(fractol->mlx, fractol->mlx_win, x, y, 0x000000);
			}
			else
				mlx_pixel_put(fractol->mlx, fractol->mlx_win, x, y, 0xd2fff*i);
			y++;
		}
		x++;
	}
}

int main(int ac, char **av)
{
	void	*mlx;
	void	*mlx_win;
	t_data	data;
	t_data	var;
	int		i;
	int		j;
	int		width;
	int		height;

	data.mlx = mlx_init();
	width = 1000;
	height = 1000;
	data.mlx_win = mlx_new_window(data.mlx, width, height, "fract-ol");
	data.img = mlx_new_image(mlx, 1000, 1000);
	//fr->mlx_addr[(j * 500) + i] = res * fr->color;
	draw(&data);
	mlx_hook(data.mlx_win, 2, 1L<<2, closer, &var);
	mlx_loop(data.mlx);
}
