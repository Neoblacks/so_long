/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:26:12 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/13 19:33:11 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int main(int argc, char **argv)
{
	t_vars vars;
	char	*map_extend;

	(void)argv;
	if (argc != 2)
	{
		printf("Error ! We need 1 argument\n");
		return (0);
	}
	else //init mlx, get size screen, divide by 2, get key pressed, cross close, esc close
	{
		vars.mlx = mlx_init();
		mlx_get_screen_size(vars.mlx, &vars.win_width, &vars.win_height);
		vars.win = mlx_new_window(vars.mlx, vars.win_width / 2,
								  vars.win_height / 2, "so_long");

		mlx_hook(vars.win, 2, 1L << 0, print_key, &vars);
		mlx_hook(vars.win, 17, 1L << 17, cross_close, &vars);
		mlx_key_hook(vars.win, esc_close, &vars);

		mlx_loop(vars.mlx);
	}
	return (0);
}
