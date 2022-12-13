/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_gen.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 16:00:55 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/13 17:07:37 by amugnier         ###   ########.fr       */
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

char	*add_exit(char *map, int width, int height);
char	*add_player(char *map, int width, int height);
char	*add_collectible(char *map, int width, int height);
char	*add_wall(char *map, int width, int height);
char	*add_empty(char *map, int width, int height);
char	*make_wall_rectangle(int width, int height);
#endif

