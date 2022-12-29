/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:12:21 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/29 03:33:27 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <fcntl.h>

typedef struct s_vars
{
	int		win_height;
	int		win_width;
	int		i;
	int		j;
	int		fd;
	char	*line;
}	t_vars;

typedef struct pos_s
{
	int	x;
	int	y;
}	t_pos;

typedef struct content_s
{
	char	wall;
	char	player;
	char	collectible;
	char	empty;
	char	exit;
	int		count_player;
	int		count_exit;
	int		count_collectible;
}	t_content;

typedef struct image_s
{
	int		img_height;
	int		img_width;
	void	*img_wall;
	void	*img_player;
	void	*img_collectible;
	void	*img_floor;
	void	*img_exit;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collectible;
	char	*exit;
}	t_image;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	char	*addr;
	int		line_length;
	int		endian;
	int		count;
	char	**map;
	int		width;
	int		height;
	t_image	image;
	t_vars	vars;
	t_content content;
	t_pos	pos;
}	t_data;

int	esc_close(int keycode, t_data *data);
int	cross_close(t_data *data);
int	print_key(int keycode, t_data *data);
int	mouse_win(int x, int y, t_data *data);
int	ft_strstr(const char *str, char *comp);

int	ft_error(char *str);
void	map(char **str, t_data *data);
char	**ft_parse_map(int fd, t_data *data);
char	**ft_get_map(int fd);
void	*ft_clean_map(t_data *data);
void	ft_texture(t_data *data);
void	ft_content(t_content *content);
int	ft_check_format(char **map);
void	ft_check_content(t_data *data);
int	ft_check_other(char *map_line, t_content *content);
int	ft_check_column(char *map_line, char wall, t_data *data);
int	ft_check_line(char *map_line, char wall);
char	*correct_strjoin(char *s1, char *s2);
void	display_img(t_data *data, void *img, int x, int y);
int	render_main(t_data *data);
void	window_utils(t_data *data);
void	render_other(t_data *data);
void	render_bg(t_data *data);
int	ft_stop(t_data *data);

# endif
