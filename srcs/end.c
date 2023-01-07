/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 11:49:22 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/07 18:40:41 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_free_visites(t_data *data)
{
	int	i;

	i = 0;
	while (data->voisin.visites[i])
	{
		free(data->voisin.visites[i]);
		printf("I = %d", i);
		i++;
	}
	free(data->voisin.visites);
}

void	ft_free_array(t_data *data)
{
	free(data->queue.array);
}

int	ft_stop(t_data *data)
{
	int	i;

	i = 0;
	if (data->map != NULL)
	{
		while (data->map[i] != NULL)
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
		mlx_destroy_image(data->mlx, data->image.img_wall);
		mlx_destroy_image(data->mlx, data->image.img_floor);
		mlx_destroy_image(data->mlx, data->image.img_exit);
		mlx_destroy_image(data->mlx, data->image.img_player);
		mlx_destroy_image(data->mlx, data->image.img_collectible);
		mlx_destroy_window(data->mlx, data->win);
	}
	mlx_destroy_display(data->mlx);
	ft_free_visites(data);
	ft_free_array(data);
	free(data->mlx);
	exit(0);
}

void	*ft_clean_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map == NULL)
		return (0);
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return (0);
}
