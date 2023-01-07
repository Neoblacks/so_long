/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:23:31 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/07 18:35:04 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_addstr(char *str, char buffer)
{
	int		i;
	char	*ret;

	i = 0;
	if (str == NULL)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen(str) + 2)); // avoir le + 2 en plus 1
	if (!ret)
		return (NULL);
	while (str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	free(str);
	ret[i] = buffer;
	ret[i++] = '\0'; //Incrementation avant le /0 pour le mettre au bon endroit
	return (ret);
}

int	count_char_gnl(int fd, char **str)
{
	char	buffer;
	int		ret;

	ret = read(fd, &buffer, 1);
	while (ret > 0)
	{
		*str = ft_addstr(*str, buffer);
		if (buffer == '\n')
			return (ret);
		else
			ret = ret + 1;
		ret = read(fd, &buffer, 1);
	}
	if (ret == 0)
	{
		free(*str);
		*str = NULL;
	}
	return (ret);
}

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
	if (ft_check_format(data->map) == EXIT_FAILURE)
		return (ft_clean_map(data));
	if (ft_check_line(data->map[0], data->content.wall) == EXIT_FAILURE)
		return (ft_clean_map(data));
	while (data->map[i] != NULL)
	{
		if (ft_check_column(data->map[i], data->content.wall, data) == FAILURE)
			return (ft_clean_map(data));
		else if (ft_check_other(data->map[i], &(data->content)) == EXIT_FAILURE)
			return (ft_clean_map(data));
		i++;
	}
	data->height = i;
	if (ft_check_line(data->map[i - 1], data->content.wall) == EXIT_FAILURE)
		return (ft_clean_map(data));
	return (data->map); //A enlever si je mets en void *
}

void	map(char **str, t_data *data)
{
	int	fd;

	fd = 0;
	data->map = NULL;
	if (ft_strstr(str[1], ".ber") == EXIT_FAILURE)
		ft_error("Error no correct format\n", WARNING);
	else
	{
		fd = open(str[1], O_RDONLY);
		if (fd > 0)
		{
			data->map = ft_parse_map(fd, data);
		}
		else
			ft_error("Error, failed to open file\n", WARNING);
		if ((data->content.count_collectible == 0 || \
			data->content.count_exit != 1 || data->content.count_player != 1) \
				&& data->map != NULL)
		{
			ft_clean_map(data);
			ft_error("Error, need 1 P, 1 Exit, and 1 Co", WARNING);
		}
	}
}
