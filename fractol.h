# ifndef FRACTOL_H
#define FRACTOL_H
# include <mlx.h>
#include <math.h>

typedef struct s_data
{
	int		i;
	int		j;
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		width;
	int		height;
	double	cr;
	double	ci;
	double 	maxr;
	double		maxi;
	double		minr;
	double		mini;
	int			itter;
}		t_data;


# endif
