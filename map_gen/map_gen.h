/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:55 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/14 16:45:51 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_GEN_H
# define MAP_GEN_H

# include <stdio.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <stddef.h>

typedef struct s_data
{
	int		width;
	int		height;
	int		i;
	int		j;
	char	*map;
	int		count;
	int		fd;
	int		count_map;
}	t_data;

char	*add_exit(char *map, int width, int height);
char	*add_player(char *map, int width, int height);
char	*add_collectible(char *map, int width, int height);
char	*add_wall(char *map, int width, int height);
char	*add_empty(char *map, int width, int height);
char	*make_wall_rectangle(int width, int height);
char	*build_empty(t_data *data);
#endif
