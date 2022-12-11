#include "../mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

int print_key(int keycode, t_vars *vars)
{
	(void)vars;
	printf("keycode: %d\n", keycode);
	return (0);
}

int mouse_win(int x, int y, t_vars *vars)
{
	(void)vars;
	printf("x: %d, y: %d\n", x, y);
	return (0);
}

int	main(void)
{
	// void	*mlx;
	// void	*mlx_win;
	// int		width;
	// int		height;
	// t_data	img

	// mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	// img.img = mlx_new_image(mlx, 1920, 1080);
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 		&img.endian);

	t_vars	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 500, 500, "Hello world!");


	mlx_hook(vars.win, 6, 1L<<6, mouse_win, &vars);
	mlx_hook(vars.win, 2, 1L<<0, print_key, &vars);

	mlx_hook(vars.win, 2, 1L<<0, close, &vars);

	mlx_loop(vars.mlx);
}
