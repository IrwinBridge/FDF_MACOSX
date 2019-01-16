/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   useful.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:57:37 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/16 01:50:25 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	to_rad(float a)
{
	return (a * M_PI / 180);
}

float	normalize(float val, float min, float max)
{
	if (max - min != 0)
		return ((float)(val - min) / (float)(max - min));
	else
		return (0);
}

int		get_new_color(int color, int direction)
{
	int r;
	int g;
	int b;

	r = ((color >> 16) & 0xFF) - direction * 8;
	g = ((color >> 8) & 0xFF);
	b = color & 0xFF - direction * 8;
	return ((r << 16) | (g << 8) | b);
}

void	shift_color(t_mlx *mlx, int dir)
{
	if (dir == 0)
	{
		mlx->map->start_color = get_new_color(mlx->map->start_color, -1);
		mlx->map->end_color = get_new_color(mlx->map->end_color, -1);
	}
	else
	{
		mlx->map->start_color = get_new_color(mlx->map->start_color, 1);
		mlx->map->end_color = get_new_color(mlx->map->end_color, 1);
	}
}
