/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 12:26:24 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/09 15:00:38 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_destroy_img(t_data *data)
{
	mlx_destroy_image(data->mlx, data->image.img_wall);
	mlx_destroy_image(data->mlx, data->image.img_floor);
	mlx_destroy_image(data->mlx, data->image.img_exit);
	mlx_destroy_image(data->mlx, data->image.img_player);
	mlx_destroy_image(data->mlx, data->image.img_collectible);
}
