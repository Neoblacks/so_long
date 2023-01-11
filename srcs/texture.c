/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:22:25 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/11 19:58:15 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_file(t_data *data)
{
	if (data->image.img_wall == NULL)
	{
		ft_error("Error\nFile wall.xpm not found");
		ft_destroy(data, IMG_WALL);
	}
	if (data->image.img_floor == NULL)
	{
		ft_error("Error\nFile floor.xpm not found");
		ft_destroy(data, IMG_FLOOR);
	}
	if (data->image.img_exit_activate == NULL)
	{
		ft_error("Error\nFile exit_activate.xpm not found");
		ft_destroy(data, IMG_EXIT_ACTIVATE);
	}
	if (data->image.img_exit_desactivate == NULL)
	{
		ft_error("Error\nFile exit_desactivate.xpm not found");
		ft_destroy(data, IMG_EXIT_DESACTIVATE);
	}
	ft_check_player(data);
	ft_check_collectible(data);
}

void	ft_choose_img(t_data *data, t_component component)
{
	if (component != IMG_WALL)
		mlx_destroy_image(data->mlx, data->image.img_wall);
	if (component != IMG_FLOOR)
		mlx_destroy_image(data->mlx, data->image.img_floor);
	if (component != IMG_EXIT_ACTIVATE)
		mlx_destroy_image(data->mlx, data->image.img_exit_activate);
	if (component != IMG_EXIT_DESACTIVATE)
		mlx_destroy_image(data->mlx, data->image.img_exit_desactivate);
	if (component != IMG_PLAYER_IDLE1)
		mlx_destroy_image(data->mlx, data->image.img_player_idle1);
	if (component != IMG_PLAYER_IDLE2)
		mlx_destroy_image(data->mlx, data->image.img_player_idle2);
	if (component != IMG_PLAYER_IDLE3)
		mlx_destroy_image(data->mlx, data->image.img_player_idle3);
	if (component != IMG_PLAYER_IDLE4)
		mlx_destroy_image(data->mlx, data->image.img_player_idle4);
	if (component != IMG_COLLECTIBLE_1)
		mlx_destroy_image(data->mlx, data->image.img_collectible_1);
	if (component != IMG_COLLECTIBLE_2)
		mlx_destroy_image(data->mlx, data->image.img_collectible_2);
	if (component != IMG_COLLECTIBLE_3)
		mlx_destroy_image(data->mlx, data->image.img_collectible_3);
	if (component != IMG_COLLECTIBLE_4)
		mlx_destroy_image(data->mlx, data->image.img_collectible_4);
}

void	ft_check_player(t_data *data)
{
	if (data->image.img_player_idle1 == NULL)
	{
		ft_error("Error\nFile player_idle1.xpm not found");
		ft_destroy(data, IMG_PLAYER_IDLE1);
	}
	if (data->image.img_player_idle2 == NULL)
	{
		ft_error("Error\nFile player_idle2.xpm not found");
		ft_destroy(data, IMG_PLAYER_IDLE2);
	}
	if (data->image.img_player_idle3 == NULL)
	{
		ft_error("Error\nFile player_idle3.xpm not found");
		ft_destroy(data, IMG_PLAYER_IDLE3);
	}
	if (data->image.img_player_idle4 == NULL)
	{
		ft_error("Error\nFile player_idle4.xpm not found");
		ft_destroy(data, IMG_PLAYER_IDLE4);
	}
}

void	ft_check_collectible(t_data *data)
{
	if (data->image.img_collectible_1 == NULL)
	{
		ft_error("Error\nFile collect_1.xpm not found");
		ft_destroy(data, IMG_COLLECTIBLE_1);
	}
	if (data->image.img_collectible_2 == NULL)
	{
		ft_error("Error\nFile collect_2.xpm not found");
		ft_destroy(data, IMG_COLLECTIBLE_2);
	}
	if (data->image.img_collectible_3 == NULL)
	{
		ft_error("Error\nFile collect_3.xpm not found");
		ft_destroy(data, IMG_COLLECTIBLE_3);
	}
	if (data->image.img_collectible_4 == NULL)
	{
		ft_error("Error\nFile collect_4.xpm not found");
		ft_destroy(data, IMG_COLLECTIBLE_4);
	}
}

void	ft_destroy(t_data *data, t_component component)
{
	ft_choose_img(data, component);
	ft_clean_map(data);
	mlx_destroy_display(data->mlx);
	ft_free_visits(data);
	ft_free_array(data);
	free(data->mlx);
	exit(1);
}
