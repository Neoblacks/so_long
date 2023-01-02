/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:25:58 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/02 18:36:43 by amugnier         ###   ########.fr       */
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

// int move_key(int keycode, t_data *data)
// {
// 	if (keycode == W_KEY || keycode == UP_KEY)
// 	{
// 		ft_move_top(data);
// 	}
// 	if (keycode == S_KEY || keycode == DOWN_KEY)
// 	{
// 		ft_move_bot(data);
// 	}
// 	if (keycode == A_KEY || keycode == LEFT_KEY)
// 	{
// 		ft_move_left(data);
// 	}
// 	if (keycode == D_KEY || keycode == RIGHT_KEY)
// 	{
// 		ft_move_right(data);
// 	}
// 	return (0);
// }
int move_key(int keycode, t_data *data)
{
	if (keycode == W_KEY || keycode == UP_KEY)
		ft_move(data, 0);
	else if (keycode == S_KEY || keycode == DOWN_KEY)
		ft_move(data, 2);
	if (keycode == A_KEY || keycode == LEFT_KEY)
		ft_move(data, 3);
	else if (keycode == D_KEY || keycode == RIGHT_KEY)
		ft_move(data, 1);
	return (0);
}
