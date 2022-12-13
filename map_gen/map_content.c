/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_content.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:20:58 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/13 16:05:42 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_gen.h"

char	*make_wall_rectangle(int width, int height)
{
	char	*map;
	int		i;
	int		j;

	i = 0;
	j = 0;
	map = malloc(sizeof(char) * (width * height + height + 1));
	while (j < height)
	{
		while (i < width)
		{
			map[i + j * (width + 1)] = '1';
			i++;
		}
		map[i + j * (width + 1)] = '\n';
		i = 0;
		j++;
	}
	map[i + j * (width + 1)] = '\0';
	return (map);
}

char	*add_exit(char *map, int width, int height)
{
	int	i;
	int	j;
	int	exit;

	i = 0;
	j = 0;
	exit = 0;
	while (exit == 0)
	{
		i = rand() % width;
		j = rand() % height;
		if (map[i + j * (width + 1)] == '0')
		{
			map[i + j * (width + 1)] = 'E';
			exit = 1;
		}
	}
	return (map);
}

char	*add_collectible(char *map, int width, int height)
{
	int	i;
	int	j;
	int	collectible;

	i = 0;
	j = 0;
	collectible = 0;
	while (collectible == 0)
	{
		i = rand() % width;
		j = rand() % height;
		if (map[i + j * (width + 1)] == '0')
		{
			map[i + j * (width + 1)] = 'C';
			collectible = 1;
		}
	}
	return (map);
}

char	*add_player(char *map, int width, int height)
{
	int	i;
	int	j;
	int	player;

	i = 0;
	j = 0;
	player = 0;
	while (player == 0)
	{
		i = rand() % width;
		j = rand() % height;
		if (map[i + j * (width + 1)] == '0')
		{
			map[i + j * (width + 1)] = 'P';
			player = 1;
		}
	}
	return (map);
}

char	*add_wall(char *map, int width, int height)
{
	int	i;
	int	j;
	int	wall;

	i = 0;
	j = 0;
	wall = 0;
	while (wall == 0)
	{
		i = rand() % width;
		j = rand() % height;
		if (map[i + j * (width + 1)] == '0')
		{
			map[i + j * (width + 1)] = '1';
			wall = 1;
		}
	}
	return (map);
}
