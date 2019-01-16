/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 19:08:38 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/09 19:49:17 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	clear_image(t_image *image)
{
	ft_bzero(image->ptr, WINDOW_WIDTH * WINDOW_HEIGHT * image->bpp);
}

t_image	*delete_image(t_mlx *mlx, t_image *img)
{
	if (img)
	{
		if (img->image)
			mlx_destroy_image(mlx->mlx, img->image);
		ft_memdel((void **)&img);
	}
	return (NULL);
}

t_image	*create_image(t_mlx *mlx)
{
	t_image *img;

	if (!(img = ft_memalloc(sizeof(t_image))))
		return (NULL);
	if (!(img->image = mlx_new_image(mlx->mlx, WINDOW_WIDTH, WINDOW_HEIGHT)))
		return (delete_image(mlx, img));
	img->ptr = mlx_get_data_addr(img->image, &img->bpp, &img->stride,
								&img->endian);
	img->bpp /= 8;
	return (img);
}

void	image_set_pixel(t_image *image, int x, int y, int color)
{
	if (x < 0 || x >= WINDOW_WIDTH || y < 0 || y >= WINDOW_HEIGHT)
		return ;
	*(int *)(image->ptr + ((x + y * WINDOW_WIDTH) * image->bpp)) = color;
}
