/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:23:31 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/14 19:55:04 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	*ft_clean_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map[i] != NULL)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	data->map = NULL;
	return (0);
}

char	*ft_get_map(int fd)
{
	char	*line;
	char	*buffer;
	int		count_char;
	char	*tmp;

	line = ft_strdup(" ");
	buffer = ft_strdup(" ");
	count_char = get_next_line(fd);
	if (count_char == -1)
	{
		ft_error("Error reading file\n");
		return (NULL);
	}
	while (count_char > 0)
	{
		tmp = ft_strjoin(line, buffer);
		free(line);
		line = tmp;
		count_char = get_next_line(fd);
	}
	return (line);
}

char	**ft_parse_map(int fd, t_data *data)
{
	int	i;

	i = 0;
	data->map = ft_split(ft_get_map(fd), '\n');
	ft_check_content(data);
	if (ft_check_format(data->map) == EXIT_FAILURE)
		return (ft_clean_map(data));
	if (ft_check_line(data->map[0], data->content.wall, data))
		return (ft_clean_map(data));
	while (data->map[i] != NULL)
	{
		if (ft_check_column(data->map[i - 1], data->content.wall, data) == EXIT_FAILURE)
			return (ft_clean_map(data));
		else if (ft_check_other(data->map[i], &(data->content)) == EXIT_FAILURE)
			return (ft_clean_map(data));
		i++;
	}
	data->height = i;
	if (ft_check_line(data->map[i - 1], data->content.wall, data) == EXIT_FAILURE)
		return (ft_clean_map(data));
	return (data->map);
}

char	**map(char **str, t_data *data)
{
	int		fd;

	fd = 0;
	data->map = NULL;
	if (ft_strstr(str[1], ".ber") == 0)
	{
		return(ft_error("Error no correct format\n"));
	}
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd > 0)
			data->map = ft_parse_map(fd , data);
		else
			return (ft_error("Error, failed to open file\n"));
		if ((data->content.count_collectible == 0 || data->content.count_exit != 1
			|| data->content.count_player != 1) && data->map != NULL)
		{
			ft_clean_map(data);
			return (ft_error("Error, need 1 P, 1 Exit, and 1 Co"));
		}
	}
	return (data->map);
}
