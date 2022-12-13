/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:29 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/13 18:03:30 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_gen.h"

// need to make a main more long
int main(void)
{
	int width;
	int height;
	int i;
	int j;
	char *map;
	int count;
	int fd;
	int count_map;

	count_map = 10;
	// while (count_map > 0)
	// {
		//name file with count_map
		fd = open("../map/map.ber", O_CREAT | O_WRONLY | O_TRUNC, 0644);
		srand(time(NULL));
		width = rand() % 10 + 10;
		height = rand() % 10 + 10;
		map = make_wall_rectangle(width, height);
		i = 0;
		j = 0;
		while (j < height)
		{
			while (i < width)
			{
				if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
					map[i + j * (width + 1)] = '1';
				else
					map[i + j * (width + 1)] = '0';
				i++;
			}
			i = 0;
			j++;
		}
		map = add_exit(map, width, height);
		count = rand() % 4 + 4;
		while (count > 0)
		{
			map = add_collectible(map, width, height);
			count--;
		}
		count = rand() % (width * height / 4) + (width * height / 4);
		while (count > 0)
		{
			map = add_wall(map, width, height);
			count--;
		}
		map = add_player(map, width, height);
		dprintf(fd, "%s", map);
		free(map);
	return (0);
}
