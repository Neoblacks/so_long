/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_map_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 19:59:37 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/11 20:12:51 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	ft_check_map(int fd, t_data *data)
{
	if (count_char_gnl(fd, data->map) == 0)
	{
		ft_error("Error\nEmpty file\n");
		free(data->map);
		exit(1);
	}
}

void	ft_check_nb_symbols(t_data *data)
{
	if ((data->content.count_collectible == 0 || \
		data->content.count_exit != 1 || data->content.count_player != 1) && \
		data->map != NULL)
	{
		ft_clean_map(data);
		ft_error("Error\nNeed 1 P, 1 Exit, and 1 Co");
		exit(1);
	}
}
