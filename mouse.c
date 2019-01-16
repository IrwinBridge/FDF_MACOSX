/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 18:00:13 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/16 01:50:15 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

int		hook_mousedown(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	if (y < 0)
		return (0);
	mlx->mouse->isdown |= 1 << button;
	return (0);
}

int		hook_mouseup(int button, int x, int y, t_mlx *mlx)
{
	(void)x;
	(void)y;
	mlx->mouse->isdown &= ~(1 << button);
	return (0);
}

int		hook_mousemove(int x, int y, t_mlx *mlx)
{
	mlx->mouse->prev_x = mlx->mouse->x;
	mlx->mouse->prev_y = mlx->mouse->y;
	mlx->mouse->x = x;
	mlx->mouse->y = y;
	if (mlx->mouse->isdown & (1 << 1) && mlx->mouse->isdown & (1 << 2))
	{
		mlx->camera->x_offset += (x - mlx->mouse->prev_x) * 0.5f;
		mlx->camera->y_offset -= (y - mlx->mouse->prev_y) * 0.5f;
	}
	else if (mlx->mouse->isdown & (1 << 1))
	{
		mlx->camera->x -= (mlx->mouse->prev_y - y);
		mlx->camera->y -= (mlx->mouse->prev_x - x);
	}
	else if (mlx->mouse->isdown & (1 << 2))
	{
		mlx->camera->scale += mlx->map->scale_factor * (mlx->mouse->prev_y - y);
		if (mlx->camera->scale < 1.0f)
			mlx->camera->scale = 1.0f;
		else if (mlx->camera->scale > 100.0f)
			mlx->camera->scale = 100.0f;
	}
	return (0);
}
