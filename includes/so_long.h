/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:12:21 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/07 18:29:00 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

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
# define WARNING 1
# define ERROR 2
# define CRITICAL 3
# define SUCCESS 0
# define FAILURE 1
typedef struct s_vars
{
	int win_height;
	int win_width;
	int i;
	int j;
	int fd;
	char *line;
} t_vars;

typedef struct coord_move_s
{
	int x;
	int y;
} t_coord_move;

typedef struct pos_s
{
	int x;
	int y;
} t_pos;

typedef struct s_queue
{
	int debut;
	int fin;
	t_pos *array;
} t_queue;

typedef struct s_voisin
{
	int x_voisin;
	int y_voisin;
	bool **visites;
} t_voisin;

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
	int img_height;
	int img_width;
	void *img_wall;
	void *img_player;
	void *img_collectible;
	void *img_floor;
	void *img_exit;
	char *player;
	char *floor;
	char *wall;
	char *collectible;
	char *exit;
} t_image;

typedef struct s_data
{
	void *mlx;
	void *win;
	char *addr;
	int line_length;
	int endian;
	int count;
	char **map;
	int width;
	int height;
	int player_weight;
	int exit_weight;
	t_image image;
	t_vars vars;
	t_content content;
	t_pos position;
	t_voisin voisin;
	t_queue queue;
	t_coord_move coord_move;
} t_data;

int esc_close(int keycode, t_data *data);
int cross_close(t_data *data);
int move_key(int keycode, t_data *data);
int mouse_win(int x, int y, t_data *data);
int ft_strstr(const char *str, char *comp);
void	alloc_array(t_data *data);

void ft_error(char *str, int exit_code);
void ft_free_img(t_data *data);
void map(char **str, t_data *data);
char **ft_parse_map(int fd, t_data *data);
char **ft_get_map(int fd);
void *ft_clean_map(t_data *data);
void ft_texture(t_data *data);
void ft_content(t_content *content);
int ft_check_format(char **map);
void ft_check_content(t_data *data);
int ft_check_other(char *map_line, t_content *content);
int ft_check_column(char *map_line, char wall, t_data *data);
int ft_check_line(char *map_line, char wall);
char *correct_strjoin(char *s1, char *s2);
void display_img(t_data *data, void *img, int x, int y);
int render_main(t_data *data);
void window_utils(t_data *data);
void render_other(t_data *data);
void render_bg(t_data *data);
int ft_stop(t_data *data);
void ft_check_file(t_data *data);
int ft_count_collect(t_data *data);
void put_weight(t_data *data);
int can_reach_exit(t_data *data);
void ft_move_all(t_data *data, int dy, int dx);

void set_pos(t_pos *pos, const int x, const int y);
void init_deplacement(int deplacements[4][2]);
void init_visites(t_data *data);
void set_queue(t_data *data, t_pos *pos);
void find_player(t_data *data);
bool is_valid(int x, int y, t_data *data);
void check_voisin(t_data *data, int deplacements[4][2]);
int browse_grille(t_data *data, int deplacements[4][2]);
int find_collect_exit(t_data *data, int deplacements[4][2]);
void check_find_collect_exit(t_data *data, int deplacements[4][2]);
void	alloc_visites(t_data *data);
void ft_free_visites(t_data *data);
void ft_free_array(t_data *data);
void	ft_close(t_data *data);
// void	ft_move(t_data *data, int direction);
// void	ft_update_pos(t_data *data, int pos_x, int pos_y);

// void	ft_move_top(t_data *data);
// void	ft_move_bot(t_data *data);
// void	ft_move_left(t_data *data);
// void	ft_move_right(t_data *data);

#endif
