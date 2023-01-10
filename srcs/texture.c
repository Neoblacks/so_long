/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:22:25 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/10 14:47:49 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_content(t_content *content)
{
	content->wall = '1';
	content->exit = 'E';
	content->empty = '0';
	content->player = 'P';
	content->collectible = 'C';
	content->count_player = 0;
	content->count_exit = 0;
	content->count_collectible = 0;
}

void	ft_texture(t_data *data)
{
	data->image.img_height = 32;
	data->image.img_width = 32;
	data->image.collectible = "xpm/collect.xpm";
	data->image.player = "xpm/player.xpm";
	data->image.exit = "xpm/exit.xpm";
	data->image.wall = "xpm/wall.xpm";
	data->image.floor = "xpm/floor.xpm";
	data->image.img_wall = mlx_xpm_file_to_image(data->mlx, data->image.wall, \
		&(data->image.img_height), &(data->image.img_width));
	data->image.img_player = mlx_xpm_file_to_image(data->mlx, \
		data->image.player, &(data->image.img_height), \
		&(data->image.img_width));
	data->image.img_exit = mlx_xpm_file_to_image(data->mlx, data->image.exit, \
		&(data->image.img_height), &(data->image.img_width));
	data->image.img_floor = mlx_xpm_file_to_image(data->mlx, data->image.floor, \
		&(data->image.img_height), &(data->image.img_width));
	data->image.img_collectible = mlx_xpm_file_to_image(data->mlx, \
		data->image.collectible, &(data->image.img_height), \
		&(data->image.img_width));
	ft_check_file(data);
}

void	ft_check_file(t_data *data)
{
	if (data->image.img_wall == NULL)
	{
		ft_error("Error\nFile wall.xpm not found");
		ft_destroy(data, IMG_WALL);
	}
	if (data->image.img_player == NULL)
	{
		ft_error("Error\nFile player.xpm not found");
		ft_destroy(data, IMG_PLAYER);
	}
	if (data->image.img_exit == NULL)
	{
		ft_error("Error\nFile exit.xpm not found");
		ft_destroy(data, IMG_EXIT);
	}
	if (data->image.img_floor == NULL)
	{
		ft_error("Error\nFile floor.xpm not found");
		ft_destroy(data, IMG_FLOOR);
	}
	if (data->image.img_collectible == NULL)
	{
		ft_error("Error\nFile collect.xpm not found");
		ft_destroy(data, IMG_COLLECTIBLE);
	}
}

void	ft_destroy(t_data *data, t_component component)
{
	if (component != IMG_WALL)
		mlx_destroy_image(data->mlx, data->image.img_wall);
	if (component != IMG_FLOOR)
		mlx_destroy_image(data->mlx, data->image.img_floor);
	if (component != IMG_EXIT)
		mlx_destroy_image(data->mlx, data->image.img_exit);
	if (component != IMG_PLAYER)
		mlx_destroy_image(data->mlx, data->image.img_player);
	if (component != IMG_COLLECTIBLE)
		mlx_destroy_image(data->mlx, data->image.img_collectible);
	ft_clean_map(data);
	mlx_destroy_display(data->mlx);
	ft_free_visits(data);
	ft_free_array(data);
	free(data->mlx);
	exit(1);
}
