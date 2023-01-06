/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 18:12:21 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/06 20:14:42 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define N 5
#define M 15

typedef struct pos_s
{
	int	x;
	int	y;
}	t_pos;

typedef struct s_queue
{
	int		debut;
	int		fin;
	t_pos	array[N * M];
}	t_queue;

typedef struct s_voisin
{
	int	x_voisin;
	int	y_voisin;
}	t_voisin;

typedef struct s_data
{
	t_pos	position;
	t_queue	queue;
	t_voisin	voisin;
}	t_data;

void	set_pos(t_pos *pos, const int x, const int y)
{
	pos->x = x;
	pos->y = y;
}

void	init_deplacement(int deplacements[4][2])
{
	int			i;
	const int	dx[4] = {1, -1, 0, 0};
	const int	dy[4] = {0, 0, 1, -1};

	i = 0;
	while (i < 4)
	{
		deplacements[i][0] = dx[i];
		deplacements[i][1] = dy[i];
		i++;
	}
}

void	init_visites(bool visites[N][M])
{
	int	i;
	int	j;

	i = 0;
	while (i < N)
	{
		j = 0;
		while (j < M)
		{
			visites[i][j] = (false);
			j++;
		}
		i++;
	}
}

void	set_queue(t_data *data, t_pos *pos)
{
	data->queue.debut = 0;
	data->queue.fin = 1;
	data->queue.array[0] = *pos;
}

bool	is_valid(int x, int y, char grille[N][M])
{
	if (x < 0 || x >= N || y < 0 || y >= M)
	{
		return (false);
	}
	if (grille[x][y] == '1')
	{
		return (false);
	}
	return (true);
}

void	find_player(char grille[N][M], t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < N)
	{
		j = 0;
		while (j < M)
		{
			if (grille[i][j] == 'P')
			{
				data->position.x = i;
				data->position.y = j;
			}
			j++;
		}
		i++;
	}
}

void	check_voisin(char grille[N][M], t_data *data, bool visites[N][M], int deplacements[4][2])
{
	int			i;

	i = 0;
	while (i < 4)
	{
		data->voisin.x_voisin = data->position.x + deplacements[i][0];
		data->voisin.y_voisin = data->position.y + deplacements[i][1];
		if (is_valid(data->voisin.x_voisin, data->voisin.y_voisin, grille) && !visites[data->voisin.x_voisin][data->voisin.y_voisin])
		{
			visites[data->voisin.x_voisin][data->voisin.y_voisin] = true;
			set_pos(&data->queue.array[data->queue.fin], data->voisin.x_voisin, data->voisin.y_voisin);
			data->queue.fin++;
		}
		i++;
	}
}

int	browse_grille(char grille[N][M], t_data *data, bool visites[N][M], int deplacements[4][2])
{
	int		collec_found;
	int		exit_found;

	collec_found = 0;
	exit_found = 0;
	while (data->queue.debut < data->queue.fin)
	{
		data->position = data->queue.array[data->queue.debut];
		data->queue.debut++;
		if (grille[data->position.x][data->position.y] == 'C' || grille[data->position.x][data->position.y] == 'E')
		{
			if (grille[data->position.x][data->position.y] == 'C')
				collec_found = 1;
			if (grille[data->position.x][data->position.y] == 'E')
				exit_found = 1;
			if (collec_found && exit_found)
				return (EXIT_SUCCESS);
		}
		check_voisin(grille, data, visites, deplacements);
	}
	return (EXIT_FAILURE);
}

int find_collect_exit(char grille[N][M], t_data *data, bool visites[N][M], int deplacements[4][2])
{
	int result;

	init_deplacement(deplacements);
	find_player(grille, data);
	set_queue(data, &data->position);
	set_pos(&data->queue.array[data->queue.debut], data->position.x, data->position.y);
	init_visites(visites);
	visites[data->position.x][data->position.y] = true;
	result = browse_grille(grille, data, visites, deplacements)
	return (result);
}

void check_find_collect_exit(char grille[N][M], t_data *data, bool visites[N][M], int deplacements[4][2])
{
	if (find_collect_exit(grille, data, visites, deplacements) == EXIT_FAILURE)
	{
		ft_error("La map n'est pas valide.");
	}
	// else
	// {
	// 	printf("Le Collectible (C) et la sortie (E) ne peuvent pas être atteints depuis la position de départ du P.\n");
	// }
}

int	main(void)
{
	t_data	data;
	bool	visites[N][M];
	int		deplacements[4][2];
	char grille[N][M] = {
		"1111111111111",
		"10000000000C1",
		"1011111110111",
		"1P1000E000001",
		"1111111111111"};

	check_find_collect_exit(grille, &data, visites, deplacements);
	return (0);
}
