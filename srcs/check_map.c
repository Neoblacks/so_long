/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 15:58:15 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/19 19:27:55 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_check_column(char *map_line, char wall, t_data *data) // check line
{
	int	i;

	i = 0;
	// write(1 ,map_line, 100);
	while (map_line[i] != '\0')
		i++;
	if (map_line[0] != wall || map_line[i - 1] != wall)
	{
		ft_error("Error, Map column are not close\n");
		exit(EXIT_FAILURE);
	}
	data->width = i;
	return (EXIT_SUCCESS);
}

int	ft_check_line(char *map_line, char wall) // check column
{
	int	i;

	i = 0;
	while (map_line[i] != '\0')
	{
		if (map_line[i] != wall)
		{
			ft_error("Error, Map line are not close\n");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

int	ft_check_other(char *map_line, t_content *content)
{
	int	i;

	i = 0;
	while (map_line[i] != '\0')
	{
		if (content->count_exit > 1 || content->count_player > 1)
		{
			ft_error("Error, Bad number of exit or player\n");
			exit(EXIT_FAILURE);
		}
		if (map_line[i] != content->wall && map_line[i] != content->player && map_line[i] != content->exit && map_line[i] != content->collectible && map_line[i] != '0')
		{
			ft_error("Error, Bad symbol in map");
			exit(EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

void	ft_check_content(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->map[i])
	{
		while (data->map[i][j])
		{
			if (data->map[i][j] == data->content.collectible)
				data->content.count_collectible += 1;
			data->content.count_collectible += 1;
			if (data->map[i][j] == data->content.player)
				data->content.count_player += 1;
			if (data->map[i][j] == data->content.exit)
				data->content.count_exit += 1;
			j++;
		}
		j = 0;
		i++;
	}
}

int	ft_check_format(char **map)
{
	int	width;
	int	height;
	int	count_width;

	width = 0;
	height = 0;
	count_width = 0;
	while (map[0][count_width] != '\0')
		count_width++;
	while (map[height] != NULL)
	{
		while (map[height][width] != '\0')
			width++;
		if (width != count_width)
		{
			ft_error("Error, Map is not a rectangle");
			exit(EXIT_FAILURE);
		}
		width = 0;
		height++;
	}
	return (EXIT_SUCCESS);
}
