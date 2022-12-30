/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:26:12 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/30 19:35:10 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_count_collect(t_data *data)
{
	int	i;
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (data->map[j])
	{
		i = 0;
		while (data->map[j][i])
		{
			if (data->map[j][i]== data->content.collectible)
				count++;
			i++;
		}
		j++;
	}
	return (count);
}

int ft_strstr(const char *str, char *comp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (str[i] == '\0' && comp[j] == '\0')
		return (EXIT_SUCCESS);
	while (str[i] != '\0')
	{
		while (str[i + j] == comp[j] && str[i + j] != '\0' && comp[j] != '\0')
			j++;
		if (comp[j] == '\0' && str[i + j] == '\0')
			return (EXIT_SUCCESS);
		else
			j = 0;
		i++;
	}
	return (EXIT_FAILURE);
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
	free(data->mlx);
	exit(0);
}

int main(int argc, char **argv)
{
	t_data data;

	if (argc != 2)
		ft_error("Error ! We need 1 argument .ber\n");
	else
	{
		data.count = 0;
		data.mlx = mlx_init();
		ft_content(&(data.content));
		// data.map = map(argv, &(data));
		map(argv, &(data));
		//backtracking
		if (data.map != NULL)
		{
			ft_texture(&data);
			window_utils(&data);
		}
		else
			ft_stop(&data);
	}
	return (1);
}
