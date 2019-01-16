/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:45:27 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/16 00:53:03 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			gradient(t_vector start, t_vector end, t_vector *current)
{
	int		dx;
	int		dy;
	double	percentage;

	dx = ft_abs(end.x - start.x);
	dy = ft_abs(end.y - start.y);
	if (dx > dy)
		percentage = percent(start.x, end.x, current->x);
	else
		percentage = percent(start.y, end.y, current->y);
	return (get_gradient_at(percentage, start.color, end.color));
}

void		rasterize(t_mlx *mlx, t_line *line, t_vector *p1, t_vector *p2)
{
	while (1)
	{
		image_set_pixel(mlx->image, p1->x, p1->y,
						gradient(line->start, line->end, p1));
		if (p1->x == p2->x && p1->y == p2->y)
			break ;
		line->err2 = 2 * line->err;
		if (line->err2 >= line->dy)
		{
			line->err += line->dy;
			p1->x += line->dirx;
		}
		if (line->err2 <= line->dx)
		{
			line->err += line->dx;
			p1->y += line->diry;
		}
	}
}

void		draw_line(t_mlx *mlx, t_vector p1, t_vector p2)
{
	t_line line;

	line.start = p1;
	line.end = p2;
	line.dx = ft_abs(p2.x - p1.x);
	line.dy = -ft_abs(p2.y - p1.y);
	line.dirx = p1.x < p2.x ? 1 : -1;
	line.diry = p1.y < p2.y ? 1 : -1;
	line.err = line.dx + line.dy;
	rasterize(mlx, &line, &p1, &p2);
}

t_vector	point_at(t_map *map, int x, int y)
{
	t_vector point;

	point.x = x;
	point.y = y;
	point.z = map->z[y * map->width + x];
	return (point);
}

int			render(t_mlx *mlx)
{
	t_vector	point;
	int			x;
	int			y;

	clear_image(mlx->image);
	x = 0;
	y = 0;
	while (x < mlx->map->width)
	{
		y = 0;
		while (y < mlx->map->height)
		{
			point = transform(point_at(mlx->map, x, y), mlx);
			if (x + 1 < mlx->map->width)
				draw_line(mlx, point,
						transform(point_at(mlx->map, x + 1, y), mlx));
			if (y + 1 < mlx->map->height)
				draw_line(mlx, point,
						transform(point_at(mlx->map, x, y + 1), mlx));
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(mlx->mlx, mlx->window, mlx->image->image, 0, 0);
	return (0);
}
