/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 21:26:12 by amugnier          #+#    #+#             */
/*   Updated: 2022/12/13 21:46:04 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_strstr(const char *str, char *comp)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (str[i] == '\0' && comp[j] == '\0')
		return (EXIT_SUCCESS);
	while (str[i] != '\0')
	{
		while (str[i + j] == comp[j] && str[i + j] != '\0' && comp[j] != '\0')
			j++;
		if (comp[j] == '\0' && str[i + j] == '\0')
			return (EXIT_SUCCESS);
		else
			j = 0;
		i++;
	}
	return (EXIT_FAILURE);
}

int	main(int argc, char **argv)
{
	t_vars	vars;
	int		fd;

	fd = 0;
	(void)argv;
	if (argc != 2)
	{
		ft_error("Error ! We need 1 argument .ber\n");
		return (0);
	}
	else //init mlx, get size screen, divide by 2, get key pressed, cross close, esc close
	{
		if (ft_strstr(argv[1], ".ber") == EXIT_FAILURE)
			ft_error("Error no correct format\n");
		else
		{
			fd = open(argv[1], O_RDONLY);
			if (fd < 0)
				ft_error("File doesn't exist\n");
			else
			{
				vars.mlx = mlx_init();
				mlx_get_screen_size(vars.mlx, &vars.win_width,
						&vars.win_height);
				vars.win = mlx_new_window(vars.mlx, vars.win_width / 2,
						vars.win_height / 2, "so_long");
				mlx_hook(vars.win, 2, 1L << 0, print_key, &vars);
				mlx_hook(vars.win, 17, 1L << 17, cross_close, &vars);
				mlx_key_hook(vars.win, esc_close, &vars);
				mlx_loop(vars.mlx);
			}
		}
	}
	return (0);
}
