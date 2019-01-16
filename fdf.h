/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmelara- <cmelara-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:57:35 by cmelara-          #+#    #+#             */
/*   Updated: 2019/01/16 01:48:56 by cmelara-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define WINDOW_WIDTH	1280
# define WINDOW_HEIGHT	720

# define START_COLOR	0x447E87
# define END_COLOR		0xFF0000

# include <math.h>
# include "minilibx/mlx.h"
# include "libft/libft.h"
# include "keymap.h"
# include "get_next_line.h"

typedef enum	e_proj
{
	ISO,
	DIMETRIC,
	PERSPECTIVE
}				t_proj;

typedef struct	s_vector
{
	float		x;
	float		y;
	float		z;
	int			color;
}				t_vector;

typedef struct	s_line
{
	t_vector	start;
	t_vector	end;
	int			dx;
	int			dy;
	int			dirx;
	int			diry;
	int			err;
	int			err2;
}				t_line;

typedef struct	s_map
{
	int			width;
	int			height;
	int			depth_min;
	int			depth_max;
	int			*z;
	float		scale_factor;
	int			start_color;
	int			end_color;
}				t_map;

typedef struct	s_mouse
{
	char		isdown;
	int			x;
	int			y;
	int			prev_x;
	int			prev_y;
}				t_mouse;

typedef struct	s_image
{
	void		*image;
	char		*ptr;
	int			bpp;
	int			stride;
	int			endian;
}				t_image;

typedef struct	s_color
{
	int			r;
	int			g;
	int			b;
}				t_color;

typedef struct	s_camera
{
	float		x_offset;
	float		y_offset;
	float		x;
	float		y;
	float		z;
	float		scale;
	float		z_scale;
	t_proj		proj;
}				t_camera;

typedef struct	s_mlx
{
	void		*mlx;
	void		*window;
	t_image		*image;
	t_map		*map;
	t_mouse		*mouse;
	t_camera	*camera;
}				t_mlx;

t_mlx			*init(char *title);
void			read_map(int fd, t_map *map);
t_mlx			*mlx_free(t_mlx *mlx);

int				render(t_mlx *mlx);
t_vector		transform(t_vector point, t_mlx *mlx);
int				clipping(t_vector p1, t_vector p2);

t_image			*create_image(t_mlx *mlx);
void			clear_image(t_image *image);
void			image_set_pixel(t_image *image, int x, int y, int color);
t_image			*delete_image(t_mlx *mlx, t_image *img);

int				key_release(int keycode, t_mlx *mlx);
int				close_window(t_mlx *mlx);

int				hook_mousedown(int button, int x, int y, t_mlx *mlx);
int				hook_mouseup(int button, int x, int y, t_mlx *mlx);
int				hook_mousemove(int x, int y, t_mlx *mlx);

int				max(int *a, int size);
int				min(int *a, int size);
int				min_val(int a, int b);
int				max_val(int a, int b);
int				clamp_channel(int c);
float			percent(int start, int end, int current);
int				ft_lerp(int start, int end, float percentage);
int				get_gradient_at(float percentage, int start_color,
								int end_color);
float			to_rad(float a);
float			normalize(float val, float min, float max);
void			shift_color(t_mlx *mlx, int dir);

void			iso(t_vector *p);
void			dimetric(t_vector *p);
void			perspective(t_vector *p);

void			exit_with_message(char *msg);

#endif
