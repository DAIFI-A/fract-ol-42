/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adaifi <adaifi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 22:39:06 by adaifi            #+#    #+#             */
/*   Updated: 2022/04/13 22:29:52 by adaifi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <mlx.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <stdio.h>

typedef struct cor
{
	double	corx;
	double	cory;
}	t_cor;

typedef struct s_data
{
	int		i;
	void	*mlx;
	void	*mlx_win;
	int		*addr;
	int		x;
	int		y;
	int		width;
	int		height;
	void	*img;
	int		bpp;
	int		endian;
	int		l_lenght;
	double	cr;
	double	ci;
	double	maxr;
	double	maxi;
	double	minr;
	double	mini;
	int		itter;
	int		id;
	t_cor	zoom;
}	t_data;

void	ft_julia(t_data	*data);
void	ft_burn(t_data	*data);
void	draw_mand(t_data	*fractol);
void	draw_burn(t_data	*fractol);
void	ft_mand(t_data	*fractol);
void	draw_julia(t_data	*fractol);
void	clear_redraw(t_data	*var);
int		zoom(int keycode, int x, int y, t_data *fractol);
int		keypress(int keycode, t_data *fractol);
int		keycode(int keycode, t_data *data);
int		closer(t_data *var);
int		itter(double cr, double ci, double max, t_data *fra);
int		itter1(double cr, double ci, double max);
int		itter2(double cr, double ci, double max);
int		mosse_mov(int x, int y, t_data *fra);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		fractol(int id);
int		main(int argc, char **argv);

#endif
