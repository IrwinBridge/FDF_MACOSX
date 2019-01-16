/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_from_file.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 01:26:43 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/16 01:50:24 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	parse_map(int fd, char **map_str, t_map *map, int *numbers_count)
{
	char	*line;
	char	*temp;

	while (get_next_line(fd, &line))
	{
		temp = ft_strnew(ft_strlen(*map_str) + 1);
		temp = ft_strdup(*map_str);
		temp = ft_strjoin(temp, " ");
		ft_strdel(map_str);
		*map_str = ft_strnew(ft_strlen(temp) + ft_strlen(line) + 1);
		*map_str = ft_strjoin(temp, line);
		ft_strdel(&temp);
		map->height++;
		while (*line)
		{
			if (ft_isdigit(*line))
			{
				*numbers_count += 1;
				while (*line != ' ' && *line)
					line++;
			}
			else
				line++;
		}
	}
}

void	read_map(int fd, t_map *map)
{
	char	*map_str;
	int		i;
	int		numbers_count;
	char	**zs;

	numbers_count = 0;
	map_str = ft_strnew(0);
	map->height = 0;
	parse_map(fd, &map_str, map, &numbers_count);
	map->width = numbers_count / map->height;
	zs = ft_strsplit(map_str, ' ');
	if (!(map->z = (int *)malloc(sizeof(int) * numbers_count)))
		return ;
	i = 0;
	while (i < numbers_count)
	{
		map->z[i] = ft_atoi(zs[i]);
		i++;
	}
	map->depth_max = max(map->z, numbers_count);
	map->depth_min = min(map->z, numbers_count);
	close(fd);
	free(map_str);
}
