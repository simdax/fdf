/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scornaz <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 12:48:31 by scornaz           #+#    #+#             */
/*   Updated: 2017/12/28 19:29:19 by scornaz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include "math.h"
# include "stdio.h"
# include "fcntl.h"
# include "stdlib.h"

# define SIZE_X				800
# define SIZE_Y				800
# define OFFSET_X			100
# define OFFSET_Y			100
# define PUT(x, y, color)	mlx_pixel_put(libx->mlx, libx->win, x, y, color);
# define ABS(x)				x < 0 ? -x : x
# define MAX(x, y)			x > y ? x : y

typedef struct		s_libx
{
	void			*win;
	void			*mlx;
}					t_libx;

typedef struct		s_point
{
	float				x;
	float				y;
	float			z;
}					t_point;

typedef struct		s_line
{
	t_point			origin;
	float			slope;
	int				steps;
}					t_line;

typedef struct	s_matrix
{
	int			len;
	int			cols;
	int			rows;
	t_point		*points;
}				t_matrix;
	
typedef struct	s_prog
{
	t_libx		*libx;
	t_matrix	*matrix;
}				t_prog;

typedef struct	s_map
{
	int len;
	int rows;
	int cols;
	int	*values;
}				t_map;

void				line(t_point x1, t_point x2, long color, t_libx *libx);
int					transform(int keycode, void *arg);
void				draw(t_matrix *matrix, long color, t_libx *libx);
int					tab_of_points(int space, t_matrix *matrix);

#endif
