# include"../fractol.h"

int	fractol(t_data *fra)
{
	fra->mlx = mlx_init();
	fra->mlx_win = mlx_new_window(fra->mlx, 500, 500, "fract-ol");
	fra->img = mlx_new_image(fra->mlx, 500, 500);
	fra->addr = (int *)mlx_get_data_addr(fra->img, &fra->bit_per_pixel, &fra->line_lenght, &fra->endian);
	if (fra->id == 0)
		ft_mand(fra);
	else if (fra->id == 1)
		ft_julia(fra);
	mlx_put_image_to_window(fra->mlx, fra->mlx_win, fra->img, 0, 0);
	mlx_key_hook(fra->mlx_win, keycode, &fra);
	mlx_hook(fra->mlx_win, 4, 0, &zoom, &fra);
	//mlx_hook(fra->mlx_win, 6, 0, &mosse_mov, &fra);
	mlx_hook(fra->mlx_win, 17, 0, &closer, &fra);
	mlx_loop(fra->mlx);
	return (0);
}

int main(int argc, char **argv)
{
	t_data fra;

	if (argc > 1)
	{
		if (!(ft_strncmp(argv[1], "mandelbrot", 11)))
		{
			fra.id = 0;
			fractol(&fra);
		}
		else if (!(ft_strncmp(argv[1], "julia", 6)))
		{
			fra.id = 1;
			fractol(&fra);
		}
	}
	return 0;
}
