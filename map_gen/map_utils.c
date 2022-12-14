/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 12:15:22 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/14 16:45:22 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map_gen.h"

char	*build_empty(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	data->map = malloc(sizeof(char) * (data->width * data->height
				+ data->height + 1));
	while (j < data->height)
	{
		while (i < data->width)
		{
			data->map[i + j * (data->width + 1)] = '0';
			i++;
		}
		data->map[i + j * (data->width + 1)] = '\n';
		i = 0;
		j++;
	}
	data->map[i + j * (data->width + 1)] = '\0';
	return (data->map);
}
