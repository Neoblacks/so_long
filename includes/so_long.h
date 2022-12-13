/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:12:21 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/13 17:57:39 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"
#include "../mlx/mlx.h"
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>

typedef struct s_data
{
	void *img;
	char *addr;
	int bits_per_pixel;
	int line_length;
	int endian;
} t_data;

typedef struct s_vars
{
	void *mlx;
	void *win;
	int win_height;
	int win_width;
} t_vars;

typedef struct pos_s
{
	int x;
	int y;
} t_pos;

typedef struct content_s
{
	char wall;
	char player;
	char collectible;
	char empty;
	char exit;
	int count_player;
	int count_exit;
	int count_collectible;
} t_content;

typedef struct image_s
{
	int height;
	int width;
	char *player;
	char *floor;
	char *wall;
	char *collectible;
	char *exit;
} t_image;

int esc_close(int keycode, t_vars *vars);
int cross_close(t_vars *vars);
int print_key(int keycode, t_vars *vars);
int mouse_win(int x, int y, t_vars *vars);
