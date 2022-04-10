# ifndef FRACTOL_H
#define FRACTOL_H
# include <mlx.h>
# include"fractol.h"
# include<stdlib.h>
# include<unistd.h>
# include<math.h>
# include<stdio.h>

typedef struct cor
{
	double	corx;
	double	cory;
} t_cor;

typedef struct s_data
{
	int		i;
	int		j;
	void	*mlx;
	void	*mlx_win;
	int		*addr;
	int		x;
	int		y;
	int		width;
	int		height;
	void	*img;
	int		bit_per_pixel;
	int		endian;
	int		line_lenght;
	double	cr;
	double	ci;
	int		m;
	double	maxr;
	double	maxi;
	double	minr;
	double	mini;
	int		itter;
	double	cx;
	double	cy;
	t_cor	zoom;
}		t_data;




void	draw_julia(t_data *fractol);
int	zoom(int keycode, int x, int y, t_data *fractol);
void	clear_redraw(t_data *var);
int	keypress(int keycode, t_data *fractol);
int	keycode(int keycode, t_data *data);
int	closer(int button, t_data *var);
int	ft_julia(t_data data);
int	mosse_mov(int x, int y, t_data *fra);

# endif
