/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 16:05:51 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/16 01:50:27 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_mlx	*mlx_free(t_mlx *mlx)
{
	if (mlx->window)
		mlx_destroy_window(mlx->mlx, mlx->window);
	if (mlx->mouse)
		ft_memdel((void **)&mlx->mouse);
	if (mlx->camera)
		ft_memdel((void **)&mlx->camera);
	if (mlx->map)
		ft_memdel((void **)&mlx->map);
	if (mlx->image)
		delete_image(mlx, mlx->image);
	ft_memdel((void **)&mlx);
	return (NULL);
}

t_mlx	*init(char *title)
{
	t_mlx	*mlx;

	if (!(mlx = ft_memalloc(sizeof(t_mlx))))
		return (NULL);
	if (!(mlx->mlx = mlx_init())
		|| !(mlx->window = mlx_new_window(mlx->mlx,
											WINDOW_WIDTH,
											WINDOW_HEIGHT,
											title))
		|| !(mlx->mouse = ft_memalloc(sizeof(t_mouse)))
		|| !(mlx->camera = ft_memalloc(sizeof(t_camera)))
		|| !(mlx->map = ft_memalloc(sizeof(t_map)))
		|| !(mlx->image = create_image(mlx)))
		return (mlx_free(mlx));
	mlx->camera->x_offset = 0.0f;
	mlx->camera->y_offset = 0.0f;
	mlx->camera->proj = ISO;
	return (mlx);
}
