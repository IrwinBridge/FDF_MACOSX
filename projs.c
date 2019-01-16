/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jefferso <jefferso@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 20:12:25 by jefferso          #+#    #+#             */
/*   Updated: 2019/01/15 12:50:16 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		iso(t_vector *p)
{
	float x;
	float y;

	x = p->x;
	y = p->y;
	p->x = (x - y) * cos(0.523599);
	p->y = -p->z + (x + y) * sin(0.523599);
}

void		dimetric(t_vector *p)
{
	float x;
	float y;

	x = p->x;
	y = p->y;
	p->x = x * cos(0.122173f) + (y * cos(0.733038f) * 0.5f);
	p->y = -p->z + (y * sin(0.733038f) * 0.5f) - x * sin(0.122173f);
}

void		perspective(t_vector *p)
{
	float x;
	float y;
	float z;

	x = p->x;
	y = p->y;
	z = p->z;
	p->x = x / (-0.005f * z + 1.0f);
	p->y = y / (-0.005f * z + 1.0f);
	p->z = z / (-0.005f * z + 1.0f);
}
