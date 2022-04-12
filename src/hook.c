# include"../fractol.h"
# include<unistd.h>

int	closer(int button, t_data *var)
{
	if (button == 0)
		mlx_destroy_window(var->mlx, var->mlx_win);
	exit(1);
	return(0);
}

int	keycode(int keycode, t_data *data)
{
	if (keycode == 53)
		mlx_destroy_window(data->mlx, data->mlx_win);
	//exit(1);
	return (0);
}
