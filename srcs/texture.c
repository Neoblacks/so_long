/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:22:25 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/04 17:06:03 by amugnier         ###   ########.fr       */
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
		ft_error("File collect.xpm doesn't exist\n");
	if (data->image.img_exit == NULL)
		ft_error("File exit.xpm doesn't exist\n");
	if (data->image.img_floor == NULL)
		ft_error("File floor.xpm doesn't exist\n");
	if (data->image.img_wall == NULL)
		ft_error("File wall.xpm doesn't exist\n");
	if (data->image.img_player == NULL)
		ft_error("File player.xpm doesn't exist\n");
}

// void	ft_check_file(t_data *data)
// {
// 	char	*files[5];
// 	void	*images[5];
// 	int		i;

// 	files[0] = "collect.xpm";
// 	files[1] = "exit.xpm";
// 	files[2] = "floor.xpm";
// 	files[3] = "wall.xpm";
// 	files[4] = "player.xpm";

// 	images[0] = data->image.img_collectible;
// 	images[1] = data->image.img_exit;
// 	images[2] = data->image.img_floor;
// 	images[3] = data->image.img_wall;
// 	images[4] = data->image.img_player;

// 	i = 0;
// 	while (i < 5)
// 	{
// 		if (images[i] == NULL)
// 		{
// 			printf("File %s doesn't exist\n", files[i]);
// 			exit(1);
// 		}
// 		i++;
// 	}
// }
