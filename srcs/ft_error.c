/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amugnier <amugnier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 21:32:59 by amugnier          #+#    #+#             */
/*   Updated: 2023/01/07 18:37:42 by amugnier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

//WARNING = 1 (NO FREE)
//ERROR = 2 (FREE)
//CRITICAL = 3 (FREE)
void	ft_error(char *str, int exit_code)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(2, &str[i], 1);
		i++;
	}
	if (exit_code == WARNING)
	{
		printf("WARNING");
		exit(1);
	}
	else if (exit_code == ERROR)
		printf("ERROR");
}

void	ft_free_img(t_data *data)
{
	ft_stop(data);
}
