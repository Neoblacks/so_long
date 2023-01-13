/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:29 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/11 18:37:02 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_gen.h"

// need to make a main more long
int	main(void)
{
	t_data	data;

	data.count_map = 10;
	data.fd = open("../map/map_gen.ber", O_CREAT | O_WRONLY | O_TRUNC, 0644);
	srand(time(NULL));
	data.width = rand() % 40 + 10;
	data.height = rand() % 35 + 10;
	data.map = make_wall_rectangle(data.width, data.height);
	data.i = 0;
	data.j = 0;
	while (data.j < data.height)
	{
		while (data.i < data.width)
		{
			if (data.i == 0 || data.i == data.width - 1 || \
				data.j == 0 || data.j == data.height - 1)
			data.map[data.i + data.j * (data.width + 1)] = '1';
			else
				data.map[data.i + data.j * (data.width + 1)] = '0';
			data.i++;
		}
		data.i = 0;
		data.j++;
	}
	data.map = add_exit(data.map, data.width, data.height);
	data.count = rand() % 8 + 1;
	while (data.count > 0)
	{
		data.map = add_collectible(data.map, data.width, data.height);
		data.count--;
	}
	data.count = rand() % (data.width * data.height / 4) + \
		(data.width * data.height / 4);
	while (data.count > 0)
	{
		data.map = add_wall(data.map, data.width, data.height);
		data.count--;
	}
	data.map = add_player(data.map, data.width, data.height);
	dprintf(data.fd, "%s", data.map);
	printf("%s", data.map);
	free(data.map);
	return (0);
}
