/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:23:31 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/14 13:29:44 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	**ft_get_map(int fd)
{
	char	**map_final;
	char	*fichier;
	char	*backup;
	char	*map;

	if (fd == -1)
		return (NULL);
	map = ft_strdup("");
	fichier = get_next_line(fd);
	while (fichier)
	{
		if (!fd)
			return (NULL);
		backup = map;
		map = ft_strjoin(backup, fichier);
		free(backup);
		free(fichier);
		fichier = get_next_line(fd);
	}
	free(fichier);
	map_final = ft_split(map, '\n');
	free(map);
	close(fd);
	return (map_final);
}

char	**ft_parse_map(int fd, t_data *data)
{
	int	i;

	i = 0;
	data->map = ft_get_map(fd);
	ft_check_content(data);
	if (ft_check_format(data->map) == FAIL)
		return (ft_clean_map(data));
	if (ft_check_line(data->map[0], data->content.wall) == FAIL)
		return (ft_clean_map(data));
	while (data->map[i] != NULL)
	{
		if (ft_check_column(data->map[i], data->content.wall, data) == FAIL)
			return (ft_clean_map(data));
		else if (ft_check_other(data->map[i], &(data->content)) == FAIL)
			return (ft_clean_map(data));
		i++;
	}
	data->height = i;
	if (ft_check_line(data->map[i - 1], data->content.wall) == FAIL)
		return (ft_clean_map(data));
	return (data->map);
}

void	ft_open_file(char **str)
{
	int		fd;

	fd = open(str[1], O_RDONLY);
	if (fd > 0)
	{
		ft_check_file_empty(fd);
		close(fd);
	}
	else
	{
		ft_error("Error\nFailed to open file\n");
		close(fd);
		exit(1);
	}
}

void	ft_start_map(char **str, t_data *data)
{
	int	fd;

	fd = open(str[1], O_RDONLY);
	if (fd > 0)
	{
		data->map = ft_parse_map(fd, data);
		close(fd);
	}
	else
	{
		ft_error("Error\nFailed to open file\n");
		close(fd);
		exit(1);
	}
}

void	map(char **str, t_data *data)
{
	int		ret;

	ret = 0;
	data->map = NULL;
	if (ft_strstr(str[1], ".ber") == FAIL)
	{
		ft_error("Error\nNo correct format\n");
		exit(1);
	}
	else
	{
		ft_open_file(str);
		ft_start_map(str, data);
		ft_check_nb_symbols(data);
	}
}
