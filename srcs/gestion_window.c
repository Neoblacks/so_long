/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:25:58 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/13 18:09:14 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Close window with ESC
int esc_close(int keycode, t_vars *vars)
{
	if (keycode == 65307)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		// mlx_destroy_image(vars->mlx, img.img);
		mlx_destroy_display(vars->mlx);
		exit(0);
	}
	return (0);
}

//Close window with cross
int cross_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	exit(0);
}

int print_key(int keycode, t_vars *vars)
{
	(void)vars;
	printf("keycode: %d\n", keycode);
	return (0);
}

int mouse_win(int x, int y, t_vars *vars)
{
	(void)vars;
	printf("x: %d, y: %d\n", x, y);
	return (0);
}
