/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:33:08 by adaifi            #+#    #+#             */
/*   Updated: 2022/04/13 23:01:20 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	fractol(int id)
{
	t_data	fra;
	if (id > 0)
	{
		fra.id = id;
		fra.mlx = mlx_init();
		fra.mlx_win = mlx_new_window(fra.mlx, 500, 500, "fract-ol");
		fra.img = mlx_new_image(fra.mlx, 500, 500);
		fra.addr = (int *)
			mlx_get_data_addr(fra.img, &fra.bpp, &fra.l_lenght, &fra.endian);
		if (fra.id == 1)
			ft_mand(&fra);
		else if (fra.id == 2)
			ft_julia(&fra);
		else if (fra.id == 3)
			ft_burn(&fra);
		mlx_put_image_to_window(fra.mlx, fra.mlx_win, fra.img, 0, 0);
		mlx_key_hook(fra.mlx_win, keycode, &fra);
		mlx_hook(fra.mlx_win, 4, 0, &zoom, &fra);
		mlx_hook(fra.mlx_win, 6, 0, &mosse_mov, &fra);
		mlx_hook(fra.mlx_win, 17, 0, &closer, &fra);
		mlx_loop(fra.mlx);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc > 1)
	{
		if (!(ft_strncmp(argv[1], "mandelbrot", 11)))
			fractol(1);
		else if (!(ft_strncmp(argv[1], "julia", 6)))
			fractol(2);
		else if (!(ft_strncmp(argv[1], "burn\0", 6)))
			fractol(3);
	}
	return (0);
}
