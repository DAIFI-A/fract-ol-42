#include "fractol.h"

int	mosse_mov(int x, int y, t_data *fra)
{
	fra->zoom.corx = fra->minr + (fra->maxr - fra->minr) * x / 500;
	fra->zoom.cory = fra->mini + (fra->maxi - fra->mini) * y / 500;
	clear_redraw(fra);
	return(0);
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

void	clear_redraw(t_data *var)
{
	mlx_destroy_image(var->mlx, var->img);
	mlx_clear_window(var->mlx, var->mlx_win);
	var->img = mlx_new_image(var->mlx, 500, 500);
	draw_mand(var);
	mlx_put_image_to_window(var->mlx, var->mlx_win, var->img, 0, 0);
}
