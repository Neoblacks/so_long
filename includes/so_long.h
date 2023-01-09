/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:12:21 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/09 18:51:15 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/*
 * Section 1 : Includes different libs and defines some macros
 */

# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <stddef.h>
# include <fcntl.h>
# include <stdbool.h>
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define S_KEY 115
# define D_KEY 100
# define UP_KEY 65362
# define DOWN_KEY 65364
# define LEFT_KEY 65361
# define RIGHT_KEY 65363
# define P_KEY 112
# define O_KEY 111
# define SUCCESS 0
# define FAIL 1

typedef enum e_component
{
	IMG_WALL,
	IMG_PLAYER,
	IMG_COLLECTIBLE,
	IMG_FLOOR,
	IMG_EXIT,
}	t_component;

/*
 * Section 2 : Initialisation of Structs
 */

typedef struct s_vars
{
	int		win_height;
	int		win_width;
	int		i;
	int		j;
	int		fd;
	char	*line;
}	t_vars;

typedef struct coord_move_s
{
	int	x;
	int	y;
}	t_coord_move;

typedef struct pos_s
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_queue
{
	int		debut;
	int		fin;
	t_pos	*array;
}	t_queue;

typedef struct s_near
{
	int		x_near;
	int		y_near;
	bool	**visits;
}	t_near;

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
	void			*mlx;
	void			*win;
	char			*addr;
	int				line_length;
	int				endian;
	int				count;
	char			**map;
	int				width;
	int				height;
	int				player_weight;
	int				exit_weight;
	t_image			image;
	t_vars			vars;
	t_content		content;
	t_pos			position;
	t_near			near;
	t_queue			queue;
	t_coord_move	coord_move;
}	t_data;

/*
 * Section 3 : Prototypes of functions
 */

/* GESTION_WINDOW.C */
int		esc_close(int keycode, t_data *data);
int		cross_close(t_data *data);
int		move_key(int keycode, t_data *data);

/* CHECK_MAP.C */

int		ft_check_format(char **map);
int		ft_check_other(char *map_line, t_content *content);
int		ft_check_line(char *map_line, char wall);
int		ft_check_column(char *map_line, char wall, t_data *data);
void	ft_check_content(t_data *data);

/* END.C + END_UTILS.c */

void	ft_stop(t_data *data, bool code);
int		ft_urgency(t_data *data);
int		ft_critical(t_data *data);
void	ft_free_array(t_data *data);
void	ft_free_visits(t_data *data);
void	*ft_clean_map(t_data *data);
void	ft_destroy_img(t_data *data);

void	ft_error(char *str);

/* GESTION_MAP.c */

int		count_char_gnl(int fd, char *str);
void	map(char **str, t_data *data);
char	*ft_addstr(char *str, char buffer);
char	**ft_parse_map(int fd, t_data *data);
char	**ft_get_map(int fd);

/* MAIN.C */

int		ft_count_collect(t_data *data);
int		ft_strstr(const char *str, char *comp);
void	ft_check_data_map(t_data *data, int deplacements[4][2]);

/* MOVE.C */

void	ft_move_all(t_data *data, int dy, int dx);

/* RENDER.C */

int		render_main(t_data *data);
void	render_bg(t_data *data);
void	render_other(t_data *data);
void	window_utils(t_data *data);
void	display_img(t_data *data, void *img, int x, int y);

/* TEXTURE.C */

void	ft_content(t_content *content);
void	ft_texture(t_data *data);
void	ft_check_file(t_data *data);
void	ft_destroy(t_data *data, t_component component);

/* VALIDATE_MAP.C */

int		browse_grille(t_data *data, int deplacements[4][2]);
int		find_collect_exit(t_data *data, int deplacements[4][2]);
bool	is_valid(int x, int y, t_data *data);
void	check_find_collect_exit(t_data *data, int deplacements[4][2]);
void	check_near(t_data *data, int deplacements[4][2]);

/* VALIDATE_MAP_UTILS.C */

void	set_pos(t_pos *pos, const int x, const int y);
void	init_deplacement(int deplacements[4][2]);
void	alloc_array(t_data *data);
void	alloc_visits(t_data *data);
void	init_visits(t_data *data);

/* VALIDATE_MAP_UTILS2.C */

void	set_queue(t_data *data, t_pos *pos);
void	find_player(t_data *data);
void	ft_check_malloc_visit(t_data *data);

#endif
