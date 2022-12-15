/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 18:23:31 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/15 18:34:33 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char	*ft_addstr(char *str, char buffer)
{
	int	i;
	char	*ret;

	i = 0;
	if (str == NULL)
		return NULL;
	ret = malloc(sizeof(char) * (ft_strlen(str) + 2));
	if (!ret)
		return (NULL);
	while(str[i] != '\0')
	{
		ret[i] = str[i];
		i++;
	}
	free(str);
	ret[i] = buffer;
	ret[i++] = '\0';
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
			return ret;
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

void	*ft_clean_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map == NULL)
		return (0);
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

	line = ft_strdup("");
	buffer = ft_strdup("");
	count_char = count_char_gnl(fd, &line);
	if (count_char > 0)
	{
		tmp = buffer;
		while (count_char > 0)
		{
			buffer = ft_strjoin(buffer, line);
			free(tmp);
			free(line);
			line = ft_strdup("");
			count_char = count_char_gnl(fd, &line);
			tmp = buffer;
		}
		return (buffer);
	}
	ft_error("Error, map reading");
	return (NULL);
}

char	**ft_parse_map(int fd, t_data *data)
{
	int	i;
	(void)fd;

	i = 0;
	// printf("%s", ft_split(ft_get_map(fd), '\n')[1]);
	data->map = ft_split(ft_get_map(fd), '\n');
	// if (data->map == NULL)
	// 	return(ft_clean_map(data));
	printf("%s" ,*data->map);
	ft_check_content(data);
	if (ft_check_format(data->map) == EXIT_FAILURE)
		return (ft_clean_map(data));
	if (ft_check_line(data->map[0], data->content.wall) == EXIT_FAILURE)
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
	if (ft_check_line(data->map[i - 1], data->content.wall) == EXIT_FAILURE)
		return (ft_clean_map(data));
	return (data->map);
}

char	**map(char **str, t_data *data)
{
	int		fd;

	fd = 0;
	data->map = NULL;
	if (ft_strstr(str[1], ".ber") == EXIT_FAILURE)
	{
		ft_error("Error no correct format\n");
	}
	else
	{
		fd = open(str[1], O_RDONLY);
		printf("FD : %d\n", fd);
		if (fd > 0)
		{
			data->map = ft_parse_map(fd, data);
		}
		else
			ft_error("Error, failed to open file\n");
		if ((data->content.count_collectible == 0 || data->content.count_exit != 1
			|| data->content.count_player != 1) && data->map != NULL)
		{
			ft_clean_map(data);
			ft_error("Error, need 1 P, 1 Exit, and 1 Co");
		}
	}
	return (data->map);
}