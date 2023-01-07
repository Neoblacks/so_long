/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:22:25 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/07 18:02:03 by amugnier         ###   ########.fr       */
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
	data->image.img_height = 80;
	data->image.img_width = 80;
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
	if (data->image.img_collectible == NULL)
		ft_error("FILE NOT FOUND", ERROR); //DESTROY ALL IMAGE WITHOUT COLLECTIBLE //LEAK
	if (data->image.img_exit == NULL)
		ft_error("FILE NOT FOUND", ERROR); //DESTROY ALL IMAGE WITHOUT EXIT //LEAK
	if (data->image.img_floor == NULL)
		ft_error("FILE NOT FOUND", ERROR); //DESTROY ALL IMAGE WITHOUT FLOOR //LEAK
	if (data->image.img_player == NULL)
		ft_error("FILE NOT FOUND", ERROR); //DESTROY ALL IMAGE WITHOUT PLAYER //LEAK
	if (data->image.img_wall == NULL)
		ft_error("FILE NOT FOUND", ERROR); //DESTROY ALL IMAGE WITHOUT WALL //LEAK
}
