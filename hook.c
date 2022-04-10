# include"fractol.h"
# include<unistd.h>

int	closer(int button, t_data *var)
{
	exit(1);
	return(0);
}

int	keycode(int keycode, t_data *data)
{
	if (keycode == 53)
		exit(1);
	return (0);
}
