/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:23:49 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/06 21:18:30 by amugnier         ###   ########.fr       */
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

void	check_voisin(t_data *data, int deplacements[4][2])
{
	int			i;

	i = 0;
	while (i < 4)
	{
		data->voisin.x_voisin = data->position.x + deplacements[i][0];
		data->voisin.y_voisin = data->position.y + deplacements[i][1];
		if (is_valid(data->voisin.x_voisin, data->voisin.y_voisin, data) && !data->voisin.visites[data->voisin.x_voisin][data->voisin.y_voisin])
		{
			data->voisin.visites[data->voisin.x_voisin][data->voisin.y_voisin] = true;
			set_pos(&data->queue.array[data->queue.fin], data->voisin.x_voisin, data->voisin.y_voisin);
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
		if (data->map[data->position.x][data->position.y] == 'C' || data->map[data->position.x][data->position.y] == 'E')
		{
			if (data->map[data->position.x][data->position.y] == 'C')
				collec_found = 1;
			if (data->map[data->position.x][data->position.y] == 'E')
				exit_found = 1;
			if (collec_found && exit_found)
				return (EXIT_SUCCESS);
		}
		check_voisin(data, deplacements);
	}
	return (EXIT_FAILURE);
}

int find_collect_exit(t_data *data, int deplacements[4][2])
{
	int result;

	init_deplacement(deplacements);
	find_player(data);
	set_queue(data, &data->position);
	set_pos(&data->queue.array[data->queue.debut], data->position.x, data->position.y);
	init_visites(data);
	data->voisin.visites[data->position.x][data->position.y] = true;
	result = browse_grille(data, deplacements);
	return (result);
}

void check_find_collect_exit(t_data *data, int deplacements[4][2])
{
	if (find_collect_exit(data, deplacements) == EXIT_FAILURE)
	{
		ft_free_visites(data);
		ft_clean_map(data);
	}
}
