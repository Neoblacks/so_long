/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:39:32 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/09 14:59:06 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	render_bg(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j] != NULL)
	{
		i = 0;
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] == data->content.wall)
				display_img(data, data->image.img_wall, i, j);
			if (data->map[j][i] == data->content.empty)
				display_img(data, data->image.img_floor, i, j);
			i++;
		}
		j++;
	}
}

void	render_other(t_data *data)
{
	int	i;
	int	j;

	j = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i] != '\0')
		{
			if (data->map[j][i] == data->content.collectible)
				display_img(data, data->image.img_collectible, i, j);
			if (data->map[j][i] == data->content.player)
			{
				data->coord_move.x = i * data->image.img_width;
				data->coord_move.y = j * data->image.img_height;
				display_img(data, data->image.img_player, i, j);
			}
			if (data->map[j][i] == data->content.exit)
				display_img(data, data->image.img_exit, i, j);
			i++;
		}
		j++;
	}
}

int	render_main(t_data *data)
{
	render_bg(data);
	render_other(data);
	return (0);
}

void	window_utils(t_data *data)
{
	data->win = mlx_new_window(data->mlx, \
		(data->width * data->image.img_width), \
		(data->height * data->image.img_height), "So long");
	if (data->win == NULL)
	{
		ft_error("Error\nWindow not created");
		ft_stop(data, FAIL);
		return ;
	}
	mlx_loop_hook(data->mlx, &render_main, data);
	mlx_hook(data->win, 2, 1L << 0, move_key, data);
	mlx_hook(data->win, 17, 1L << 17, cross_close, data);
	mlx_key_hook(data->win, esc_close, data);
	mlx_loop(data->mlx);
	ft_stop(data, SUCCESS);
}

void	display_img(t_data *data, void *img, int x, int y)
{
	mlx_put_image_to_window(data->mlx, data->win, img, \
		data->image.img_width * x, data->image.img_height * y);
}
