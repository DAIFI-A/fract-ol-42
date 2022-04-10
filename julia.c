# include"fractol.h"

int	itter(double cr, double ci, double max, t_data *fra)
{
	double	zr;
	double	zi;
	double	tmp;
	int		i;

	zr = cr;
	zi = ci;
	i = 0;
	while(i <= max && (zr * zr + zi * zi) <= 4)
	{
		tmp = zr;
		zr = zr * zr - zi * zi - fra->zoom.corx;
		zi = 2*zi * tmp + fra->zoom.cory;
		i++;
	}
	return (i);
}

void	draw_julia(t_data *fractol)
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

int ft_julia(t_data data)
{
	data.zoom.corx = 0.285;
	data.zoom.cory = 0.013;
	data.minr = -2;
	data.mini = -2;
	data.maxr = 2;
	data.maxi = 2;
	data.itter = 250;
	draw_julia(&data);
	return (0);
}

int main(int ac, char **av)
{
	t_data	data;
	int		width;
	int		height;

	width = 500;
	height = 500;
	data.mlx = mlx_init();
	data.mlx_win = mlx_new_window(data.mlx, width, height, "fract-ol");
	data.img = mlx_new_image(data.mlx, 500, 500);
	ft_julia(data);
	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
	mlx_key_hook(data.mlx_win, keycode, &data);
	mlx_hook(data.mlx_win, 4, 0, &zoom, &data);
	mlx_hook(data.mlx_win, 6, 0, &mosse_mov, &data);
	mlx_hook(data.mlx_win, 17, 0, &closer, &data);
	mlx_loop(data.mlx);
}
