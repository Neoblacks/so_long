/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:28:17 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/09 17:42:05 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_all(t_data *data, int dy, int dx)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->coord_move.x / data->image.img_height;
	pos_y = data->coord_move.y / data->image.img_width;
	if (data->map[pos_y + dy][pos_x + dx] != data->content.wall)
	{
		if (!(data->map[pos_y + dy][pos_x + dx] == data->content.exit))
		{
			data->map[pos_y + dy][pos_x + dx] = data->content.player;
			data->map[pos_y][pos_x] = data->content.empty;
			data->count++;
			ft_printf("count : %d\n", data->count);
		}
		else
		{
			if (ft_count_collect(data) == 0)
			{
				ft_printf("GG vous avez gagne en %d coups\n", data->count);
				ft_stop(data, SUCCESS);
			}
		}
	}
}
