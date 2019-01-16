/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 19:44:43 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/16 01:49:41 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		max(int *a, int size)
{
	int max;
	int i;

	i = 0;
	max = a[0];
	while (i < size)
	{
		max = a[i] > max ? a[i] : max;
		i++;
	}
	return (max);
}

int		min(int *a, int size)
{
	int min;
	int i;

	i = 0;
	min = a[0];
	while (i < size)
	{
		min = a[i] < min ? a[i] : min;
		i++;
	}
	return (min);
}

float	percent(int start, int end, int current)
{
	if (end - start != 0)
		return ((float)(current - start) / (float)(end - start));
	else
		return (0);
}

int		ft_lerp(int start, int end, float percentage)
{
	return (start + (end - start) * percentage);
}

int		get_gradient_at(float percentage, int start_color, int end_color)
{
	int r;
	int g;
	int b;

	r = ft_lerp((start_color >> 16) & 0xFF, (end_color >> 16) & 0xFF,
				percentage);
	g = ft_lerp((start_color >> 8) & 0xFF, (end_color >> 8) & 0xFF,
				percentage);
	b = ft_lerp(start_color & 0xFF, end_color & 0xFF, percentage);
	return ((r << 16) | (g << 8) | b);
}
