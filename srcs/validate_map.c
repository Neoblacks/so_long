/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:23:49 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/09 17:20:00 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

bool	is_valid(int x, int y, t_data *data)
{
	if (x < 0 || x >= data->height || y < 0 || y >= data->width)
	{
		return (false);
	}
	if (data->map[x][y] == '1')
	{
		return (false);
	}
	return (true);
}

void	check_near(t_data *data, int deplacements[4][2])
{
	int			i;

	i = 0;
	while (i < 4)
	{
		data->near.x_near = data->position.x + deplacements[i][0];
		data->near.y_near = data->position.y + deplacements[i][1];
		if (is_valid(data->near.x_near, data->near.y_near, data) && \
			!data->near.visits[data->near.x_near][data->near.y_near])
		{
			data->near.visits[data->near.x_near][data->near.y_near] = true;
			set_pos(&data->queue.array[data->queue.fin], \
				data->near.x_near, data->near.y_near);
			data->queue.fin++;
		}
		i++;
	}
}

int	browse_grille(t_data *data, int deplacements[4][2])
{
	int		collec_found;
	int		exit_found;

	collec_found = 0;
	exit_found = 0;
	while (data->queue.debut < data->queue.fin)
	{
		data->position = data->queue.array[data->queue.debut];
		data->queue.debut++;
		if (data->map[data->position.x][data->position.y] == 'C' \
			|| data->map[data->position.x][data->position.y] == 'E')
		{
			if (data->map[data->position.x][data->position.y] == 'C')
				collec_found += 1;
			if (data->map[data->position.x][data->position.y] == 'E')
				exit_found = 1;
			if (collec_found == data->content.count_collectible && exit_found)
				return (EXIT_SUCCESS);
		}
		check_near(data, deplacements);
	}
	return (FAIL);
}

int	find_collect_exit(t_data *data, int deplacements[4][2])
{
	int	result;

	init_deplacement(deplacements);
	find_player(data);
	alloc_array(data);
	set_queue(data, &data->position);
	set_pos(&data->queue.array[data->queue.debut], \
		data->position.x, data->position.y);
	init_visits(data);
	data->near.visits[data->position.x][data->position.y] = true;
	result = browse_grille(data, deplacements);
	return (result);
}

void	check_find_collect_exit(t_data *data, int deplacements[4][2])
{
	if (find_collect_exit(data, deplacements) == FAIL)
	{
		ft_error("Error \nPlayer can't get exit or collectible");
		ft_clean_map(data);
		mlx_destroy_display(data->mlx);
		ft_free_visits(data);
		ft_free_array(data);
		free(data->mlx);
		exit(1);
	}
}
