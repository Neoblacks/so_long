/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gestion_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:25:58 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/07 18:48:40 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//Close window with ESC
int	esc_close(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
	{
		ft_stop(data);
	}
	return (0);
}

int	cross_close(t_data *data)
{
	ft_stop(data);
	return (0);
}

int	move_key(int keycode, t_data *data)
{
	if (keycode == W_KEY || keycode == UP_KEY)
		ft_move_all(data, -1, 0);
	if (keycode == S_KEY || keycode == DOWN_KEY)
		ft_move_all(data, 1, 0);
	if (keycode == A_KEY || keycode == LEFT_KEY)
		ft_move_all(data, 0, -1);
	if (keycode == D_KEY || keycode == RIGHT_KEY)
		ft_move_all(data, 0, 1);
	render_main(data);
	return (0);
}
