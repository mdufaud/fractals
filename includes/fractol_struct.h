/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol_struct.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/01 18:16:10 by mdufaud           #+#    #+#             */
/*   Updated: 2016/01/04 17:48:12 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_STRUCT_H
# define FRACTOL_STRUCT_H

# include <complex.h>

typedef struct	s_point
{
	float		x;
	float		y;
}				t_point;

typedef struct	s_rpoint
{
	int			x;
	int			y;
}				t_rpoint;

typedef struct	s_triangle
{
	t_point		p1;
	t_point		p2;
	t_point		p3;
}				t_triangle;

typedef struct	s_trace
{
	int			dx;
	int			dy;
	int			sx;
	int			sy;
	int			err;
}				t_trace;

typedef enum	e_fractal
{
	none,
	julia,
	mandelbrot,
	newton,
	newton2,
	newton3,
	burning_ship,
	tricorn,
	triangle,
	popcorn,
	phoenix,
}				t_fractal;

typedef struct	s_img
{
	int			width;
	int			height;
	int			bpp;
	int			sizel;
	int			endian;
	char		*data;
	void		*img;
}				t_img;

typedef struct	s_env
{
	void		*mlx;
	void		*win;
	int			win_width;
	int			win_height;
	t_img		*img;
}				t_env;

typedef struct		s_fractol
{
	t_fractal		type;
	t_env			*env;
	int				smooth;
	int				motion;
	int				iter;
	int				iterations;
	int				color;
	int				color_speed;
	int				hide;
	int				*colors;
	int				colors_i;
	int				n_colors;
	int				color_max;
	int				ended;
	double			mx;
	double			my;
	double			kx;
	double			ky;
	double			zoom;
	double			rotation;
	double			x;
	double			y;
	double			real;
	double			im;
	double			real_tmp;
	double			im_tmp;
	double			cx;
	double			cy;
	double			pow;
	double			utility_one;
	double complex	z0;
	double complex	z;
}					t_fractol;

typedef struct	s_fracprinttab
{
	t_fractal	type;
	int			(*fun)(t_fractol *f);
}				t_fracprinttab;

typedef struct	s_fracpixeltab
{
	t_fractal	type;
	int			(*fun)(t_fractol *f, int i, int j);
}				t_fracpixeltab;

typedef struct	s_fracitertab
{
	t_fractal	type;
	int			(*fun)(t_fractol *f);
}				t_fracitertab;

typedef struct	s_fracmatch
{
	t_fractal	type;
	char		*name;
}				t_fracmatch;

typedef struct	s_keycode
{
	int			keycode;
	void		(*fun)(t_fractol *f, int keycode);
}				t_keycode;

typedef struct		s_newton
{
	t_fractal		type;
	double complex	(*poly)(t_fractol *f, double complex z);
	double complex	(*deriv)(t_fractol *f, double complex z);
}					t_newton;

typedef struct		s_colors
{
	int				(*fun)(t_fractol *f);
}					t_colors;

#endif
