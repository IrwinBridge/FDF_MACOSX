/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:58:13 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/16 01:51:57 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	exit_with_message(char *msg)
{
	ft_putendl(msg);
	exit(EXIT_FAILURE);
}

void	setting(t_mlx *mlx)
{
	mlx->map->start_color = START_COLOR;
	mlx->map->end_color = END_COLOR;
	mlx->map->scale_factor = 0.5f;
	if (mlx->map->width > mlx->map->height)
		mlx->camera->scale = (double)((WINDOW_WIDTH - 50) / mlx->map->width);
	else
		mlx->camera->scale = (double)((WINDOW_HEIGHT - 50) / mlx->map->height);
	mlx->camera->z_scale = (double)(ft_abs(mlx->map->depth_min)
									+ ft_abs(mlx->map->depth_max)) / 10.0f;
}

int		main(int argc, char **argv)
{
	t_mlx	*mlx;
	int		fd;

	if (argc < 2)
		exit_with_message("Usage: ./fdf <filename>");
	if ((fd = open(argv[1], O_RDONLY)) < 0)
		exit_with_message("Couldn't be able to open the file!");
	if (!(mlx = init("FDF")))
		exit_with_message("error: mlx wasn't be able to init!");
	read_map(fd, mlx->map);
	setting(mlx);
	render(mlx);
	mlx_hook(mlx->window, 3, 0, key_release, mlx);
	mlx_hook(mlx->window, 4, 0, hook_mousedown, mlx);
	mlx_hook(mlx->window, 5, 0, hook_mouseup, mlx);
	mlx_hook(mlx->window, 6, 0, hook_mousemove, mlx);
	mlx_hook(mlx->window, 17, 0, close_window, mlx);
	mlx_loop_hook(mlx->mlx, render, mlx);
	mlx_loop(mlx->mlx);
	return (0);
}
