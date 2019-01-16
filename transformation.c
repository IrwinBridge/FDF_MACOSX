/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 17:54:19 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/16 01:50:22 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		project(t_mlx *mlx, t_vector *projected)
{
	if (mlx->camera->proj == ISO)
		iso(projected);
	else if (mlx->camera->proj == PERSPECTIVE)
		perspective(projected);
	else if (mlx->camera->proj == DIMETRIC)
		dimetric(projected);
}

t_vector	rotate(t_vector point, t_mlx *mlx)
{
	t_vector	r;
	float		x;
	float		y;
	float		z;

	x = point.x;
	y = point.y;
	z = point.z;
	r.x = x;
	r.y = y * cos(to_rad(mlx->camera->x)) + z * sin(to_rad(mlx->camera->x));
	r.z = -y * sin(to_rad(mlx->camera->x)) + z * cos(to_rad(mlx->camera->x));
	x = r.x;
	y = r.y;
	z = r.z;
	r.x = x * cos(to_rad(mlx->camera->y)) + z * sin(to_rad(mlx->camera->y));
	r.y = y;
	r.z = -x * sin(to_rad(mlx->camera->y)) + z * cos(to_rad(mlx->camera->y));
	x = r.x;
	y = r.y;
	z = r.z;
	r.x = x * cos(to_rad(mlx->camera->z)) - y * sin(to_rad(mlx->camera->z));
	r.y = x * sin(to_rad(mlx->camera->z)) + y * cos(to_rad(mlx->camera->z));
	r.z = z;
	return (r);
}

t_vector	transform(t_vector point, t_mlx *mlx)
{
	t_vector	projected;
	double		z_percentage;

	projected.x = point.x - mlx->map->width / 2;
	projected.y = point.y - mlx->map->height / 2;
	projected.z = normalize(point.z, mlx->map->depth_min,
									mlx->map->depth_max) * mlx->camera->z_scale;
	projected = rotate(projected, mlx);
	project(mlx, &projected);
	projected.x -= mlx->camera->x_offset;
	projected.y += mlx->camera->y_offset;
	projected.x *= mlx->camera->scale;
	projected.y *= mlx->camera->scale;
	projected.x += WINDOW_WIDTH / 2;
	projected.y += WINDOW_HEIGHT / 2;
	projected.x = (int)projected.x;
	projected.y = (int)projected.y;
	projected.z = (int)projected.z;
	z_percentage = percent(mlx->map->depth_min, mlx->map->depth_max, point.z);
	projected.color = get_gradient_at(z_percentage,
									mlx->map->start_color, mlx->map->end_color);
	return (projected);
}
