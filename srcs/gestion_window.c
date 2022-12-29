/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:25:58 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/29 03:33:45 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Close window with ESC
int esc_close(int keycode, t_data *data)
{
	int	i;

	i = -1;
	if (keycode == 65307)
	{
		mlx_destroy_window(data->mlx, data->win);
		mlx_destroy_image(data->mlx, data->image.img_collectible);
		mlx_destroy_image(data->mlx, data->image.img_wall);
		mlx_destroy_image(data->mlx, data->image.img_player);
		mlx_destroy_image(data->mlx, data->image.img_exit);
		mlx_destroy_image(data->mlx, data->image.img_floor);
		mlx_destroy_display(data->mlx);//FAIRE UNE FONCTION
		while (data->map[++i])
			free(data->map[i]);
		free(data->map);
		free(data->mlx);
		exit(0);
	}
	return (0);
}

//Close window with cross
int cross_close(t_data *data)
{
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	exit(0);
}

int print_key(int keycode, t_data *data)
{
	(void)data;
	printf("keycode: %d\n", keycode);
	return (0);
}

int mouse_win(int x, int y, t_data *data)
{
	(void)data;
	printf("x: %d, y: %d\n", x, y);
	return (0);
}
