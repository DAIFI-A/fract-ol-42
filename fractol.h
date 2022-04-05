# ifndef FRACTOL_H
#define FRACTOL_H
# include <mlx.h>
#include <math.h>

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
	void	*zoom;
	double	zoomx;
	double	zoomy;
	int		width;
	int		height;
	void	*img;
	int		bit_per_pixel;
	int		endian;
	int		line_lenght;
	double		cr;
	double		ci;
	double		maxr;
	double		maxi;
	double		minr;
	double		mini;
	int			itter;
	t_cor		c;
	t_cor		cor;
}		t_data;




void	draw(t_data *fractol);
int	zoom(int keycode, int x, int y, t_data *fractol);
void	clear_redraw(t_data *var);
int	closer(int keycode, t_data *var);

# endif
