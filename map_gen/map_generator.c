/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:20:58 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/12 21:02:39 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//make a map with this rules 
// 1. the map must be surrounded by walls
// 2. the map must have at least one exit
// 3. the map must have at least one collectible
// 4. the map must have at least one player
// 5. the map must have at least one empty space
// 6. the map must be a rectangle
// 7. the map must have a correct format
// 8. the map must have a correct way to exit

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char *make_wall_rectangle(int width, int height)
{
    char *map;
    int i;
    int j;

    i = 0;
    j = 0;
    map = malloc(sizeof(char) * (width * height + height + 1));
    while (j < height)
    {
        while (i < width)
        {
            map[i + j * (width + 1)] = '1';
            i++;
        }
        map[i + j * (width + 1)] = '\n';
        i = 0;
        j++;
    }
    map[i + j * (width + 1)] = '\0';
    return (map);
}

char *add_exit(char *map, int width, int height)
{
    int i;
    int j;
    int exit;

    i = 0;
    j = 0;
    exit = 0;
    while (exit == 0)
    {
        i = rand() % width;
        j = rand() % height;
        if (map[i + j * (width + 1)] == '0')
        {
            map[i + j * (width + 1)] = 'E';
            exit = 1;
        }
    }
    return (map);
}

char *add_collectible(char *map, int width, int height)
{
    int i;
    int j;
    int collectible;

    i = 0;
    j = 0;
    collectible = 0;
    while (collectible == 0)
    {
        i = rand() % width;
        j = rand() % height;
        if (map[i + j * (width + 1)] == '0')
        {
            map[i + j * (width + 1)] = 'C';
            collectible = 1;
        }
    }
    return (map);
}

char *add_player(char *map, int width, int height)
{
    int i;
    int j;
    int player;

    i = 0;
    j = 0;
    player = 0;
    while (player == 0)
    {
        i = rand() % width;
        j = rand() % height;
        if (map[i + j * (width + 1)] == '0')
        {
            map[i + j * (width + 1)] = 'P';
            player = 1;
        }
    }
    return (map);
}

int main(void)
{
    int width;
    int height;
    int i;
    int j;
    char *map;

    srand(time(NULL));
    width = rand() % 10 + 10;
    height = rand() % 10 + 10;
    map = make_wall_rectangle(width, height);
    i = 0;
    j = 0;
    while (j < height)
    {
        while (i < width)
        {
            if (i == 0 || i == width - 1 || j == 0 || j == height - 1)
                map[i + j * (width + 1)] = '1';
            else
                map[i + j * (width + 1)] = '0';
            i++;
        }
        i = 0;
        j++;
    }
    map = add_exit(map, width, height);
    map = add_collectible(map, width, height);
    map = add_player(map, width, height);
    printf("%s", map);
    free(map);
    return (0);
}

