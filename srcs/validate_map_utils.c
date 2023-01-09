/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 12:23:49 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/09 12:34:30 by amugnier         ###   ########.fr       */
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

void	alloc_array(t_data *data)
{
	int	i;

	i = 0;
	data->queue.array = malloc(sizeof(t_pos) * data->height * data->width);
	while (i < data->height * data->width)
	{
		data->queue.array[i].x = 0;
		data->queue.array[i].y = 0;
		i++;
	}
}

void	alloc_visits(t_data *data)
{
	int	i;

	i = 0;
	data->near.visits = malloc(sizeof(bool *) * (data->height + 1));
	/* TODO PROTECT MALLOC */
	while (i < data->height)
	{
		data->near.visits[i] = malloc(sizeof(bool) * (data->width));
		i++;
	}
	data->near.visits[i] = NULL;
}

void	init_visits(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	alloc_visits(data);
	while (i < data->height)
	{
		j = 0;
		while (j < data->width)
		{
			data->near.visits[i][j] = false;
			j++;
		}
		i++;
	}
}
