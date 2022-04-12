# ifndef FRACTOL_H
#define FRACTOL_H
# include <mlx.h>
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
	double	maxr;
	double	maxi;
	double	minr;
	double	mini;
	int		itter;
	int		id;
	t_cor	zoom;
}		t_data;

int	zoom(int keycode, int x, int y, t_data *fractol);
int	keypress(int keycode, t_data *fractol);
int	keycode(int keycode, t_data *data);
int	closer(int button, t_data *var);
int	itter(double cr, double ci, double max, t_data *fra);
int	itter1(double cr, double ci, double max);
int	mosse_mov(int x, int y, t_data *fra);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	fractol(t_data *fra);
int main(int argc, char **argv);
void	ft_julia(t_data *data);
void	draw_mand(t_data *fractol);
void	ft_mand(t_data *fractol);
void	draw_julia(t_data *fractol);
void	clear_redraw(t_data *var);

# endif
