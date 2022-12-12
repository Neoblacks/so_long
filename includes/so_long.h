/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:12:21 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/12 21:20:29 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../libft/includes/libft.h"
# include "../mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <fcntl.h>

typedef	struct data_s
{
	void	*mlx;
	void	*win;
	int		height;
	int		width;
}				t_data;

typedef struct pos_s
{
    int x;
    int y;
}				t_pos;

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
}					t_content;

typedef struct	image_s
{
	int		height;
	int		width;
	char	*player;
	char	*floor;
	char	*wall;
	char	*collectible;
	char	*exit;
}				t_image;
