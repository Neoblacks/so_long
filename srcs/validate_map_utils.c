/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:23:49 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/06 21:07:12 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_pos(t_pos *pos, const int x, const int y)
{
	pos->x = x;
	pos->y = y;
}

void	init_deplacement(int deplacements[4][2])
{
	int			i;
	const int	dx[4] = {1, -1, 0, 0};
	const int	dy[4] = {0, 0, 1, -1};

	i = 0;
	while (i < 4)
	{
		deplacements[i][0] = dx[i];
		deplacements[i][1] = dy[i];
		i++;
	}
}

void	alloc_visites(t_data *data)
{
	int	i;

	i = 0;
	data->voisin.visites = malloc(sizeof(bool *) * data->height);
	while (i < data->height)
	{
		data->voisin.visites[i] = malloc(sizeof(bool) * data->width);
		i++;
	}
}

void	init_visites(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	alloc_visites(data);
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			data->voisin.visites[i][j] = false;
			j++;
		}
		i++;
	}
}

void	set_queue(t_data *data, t_pos *pos)
{
	data->queue.debut = 0;
	data->queue.fin = 1;
	data->queue.array[0] = *pos;
}

void	find_player(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			if (data->map[i][j] == 'P')
			{
				data->position.x = i;
				data->position.y = j;
			}
			j++;
		}
		i++;
	}
}
