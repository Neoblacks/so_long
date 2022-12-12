#include "../mlx/mlx.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <errno.h>



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

//Close window with ESC
int esc_close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

//Close window with cross
int cross_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free(vars->mlx);
	exit(0);
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
	t_vars	vars;
	int		win_width;
	int		win_height;

	win_width = 500;
	win_height = 500;

	vars.mlx = mlx_init();
	mlx_get_screen_size(vars.mlx, &win_width, &win_height); //get screen size
	vars.win = mlx_new_window(vars.mlx, win_width/2, win_height/2, "Hello world!"); //create window with name "Hello world!"

	mlx_hook(vars.win, 2, 1L<<0, print_key, &vars); //key press (not work)
	mlx_hook(vars.win, 17, 1L<<17, cross_close, &vars); //close window
	mlx_hook(vars.win, 2, 1L<<0, esc_close, &vars); //close window with ESC

	char *line;
	// char *line2;
	int i = 0;
	int j = 0;
	int fd;

	fd = open("map_1.ber", O_RDONLY);
	line = get_next_line(fd);

	while (line)
	{
		printf("%s", line);
		while (line[i])
		{
			if (line[i] == '1') //wall
			{
				mlx_pixel_put(vars.mlx, vars.win, i * 20, j * 20, 0x00FF0000);
			}
			if (line[i] == '0') //empty
			{
				mlx_pixel_put(vars.mlx, vars.win, i * 20, j * 20, 0x0000FF00);
			}
			if (line[i] == 'E') //exit
			{
				mlx_pixel_put(vars.mlx, vars.win, i * 20, j * 20, 0x000000FF);
			}
			if (line[i] == 'C') //collectible
			{
				mlx_pixel_put(vars.mlx, vars.win, i * 20, j * 20, 0x00FFFF00);
			}
			if (line[i] == 'P') //player
			{
				mlx_pixel_put(vars.mlx, vars.win, i * 20, j * 20, 0x0000FFFF);
			}
			i++;
		}
		j++;
		line = get_next_line(fd);
		i = 0;
	}
	close(fd);



	mlx_loop(vars.mlx);
}
