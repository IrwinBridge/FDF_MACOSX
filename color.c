/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 22:06:34 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/16 01:49:54 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		min_val(int a, int b)
{
	return (a < b ? a : b);
}

int		max_val(int a, int b)
{
	return (a > b ? a : b);
}

int		clamp_channel(int c)
{
	if (c < 0)
		return (0);
	if (c > 255)
		return (255);
	return (round(c + 0.5f));
}
