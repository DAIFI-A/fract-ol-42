/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:30:12 by adaifi            #+#    #+#             */
/*   Updated: 2022/04/12 22:30:32 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fractol.h"

int	closer(t_data *var)
{
	mlx_destroy_window(var->mlx, var->mlx_win);
	exit(1);
	return (0);
}

int	keycode(int keycode, t_data *data)
{
	if (keycode == 53)
		mlx_destroy_window(data->mlx, data->mlx_win);
	exit(1);
	return (0);
}
