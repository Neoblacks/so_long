/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 12:28:17 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/30 18:38:52 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_move_top(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->image.img_height;
	pos_y = data->pos.y / data->image.img_width;
	if (data->map[pos_y - 1][pos_x] != data->content.wall)
	{
		if (!(data->map[pos_y - 1][pos_x] == data->content.exit))
		{
			data->map[pos_y - 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.empty;
			data->count += 1;
			printf("count = %d\n", data->count);
			//JE DOIS COMPTER AVEC MON PRINTF (JE L AI PAS DANS MA LIBFT OUIN OUIN)
		}
		else
		{
			if (ft_count_collect(data) == 0)
			{
				printf("GG vous avez gagne en %d coups\n", data->count);
				ft_stop(data);
			}
		}
	}
}

void	ft_move_bot(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->image.img_height;
	pos_y = data->pos.y / data->image.img_width;
	if (data->map[pos_y + 1][pos_x] != data->content.wall)
	{
		if (!(data->map[pos_y + 1][pos_x] == data->content.exit))
		{
			data->map[pos_y + 1][pos_x] = data->content.player;
			data->map[pos_y][pos_x] = data->content.empty;
			data->count += 1;
			printf("count = %d\n", data->count);
			//JE DOIS COMPTER AVEC MON PRINTF (JE L AI PAS DANS MA LIBFT OUIN OUIN)
		}
		else
		{
			if (ft_count_collect(data) == 0)
			{
				printf("GG vous avez gagne en %d coups\n", data->count);
				ft_stop(data);
			}
		}
	}
}

void	ft_move_left(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->image.img_height;
	pos_y = data->pos.y / data->image.img_width;
	if (data->map[pos_y][pos_x - 1] != data->content.wall)
	{
		if (!(data->map[pos_y][pos_x - 1] == data->content.exit))
		{
			data->map[pos_y][pos_x - 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.empty;
			data->count += 1;
			//print count a chaque mouvement
			printf("count = %d\n", data->count);

		}
		else
		{
			if (ft_count_collect(data) == 0)
			{
				printf("GG vous avez gagne en %d coups\n", data->count);
				ft_stop(data);
			}
		}
	}
}

void	ft_move_right(t_data *data)
{
	int	pos_x;
	int	pos_y;

	pos_x = data->pos.x / data->image.img_height;
	pos_y = data->pos.y / data->image.img_width;
	if (data->map[pos_y][pos_x + 1] != data->content.wall)
	{
		if (!(data->map[pos_y][pos_x + 1] == data->content.exit))
		{
			data->map[pos_y][pos_x + 1] = data->content.player;
			data->map[pos_y][pos_x] = data->content.empty;
			printf("count = %d\n", data->count);
			data->count += 1;
			printf("count = %d\n", data->count);
			//JE DOIS COMPTER AVEC MON PRINTF (JE L AI PAS DANS MA LIBFT OUIN OUIN)
		}
		else
		{
			if (ft_count_collect(data) == 0)
			{
				printf("GG vous avez gagne en %d coups\n", data->count);
				ft_stop(data);
			}
		}
	}
}