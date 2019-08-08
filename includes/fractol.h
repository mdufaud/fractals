/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: esusseli <esusseli@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/09/17 14:09:23 by esusseli          #+#    #+#             */
/*   Updated: 2016/01/04 17:48:12 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "libft.h"
# include "fractol_struct.h"

# define GLOBAL_WIN_WIDTH 720
# define GLOBAL_WIN_HEIGHT 480
# define ABS(x) (x < 0 ? -x : x)
# define TRUE(x) (x == 0 ? 1 : x)
# define N_COLORS 256
# define COLOR_MAX N_COLORS * 7
# define FRACTAL_NUMBER 4

# define W_WIDTH f->env->win_width
# define W_HEIGHT f->env->win_height

int				error(char *s);
void			*addr_error(char *s, void *p);
void			swap(int *n1, int *n2);
void			free_fractol(t_fractol **f);
int				init_fractols(t_fractol ***fractols, int argc, char **argv);
void			fractol_origin(t_fractol *f);
t_fractal		parse_type(int argc, char **argv, int *parse_index);
void			create_img(t_fractol **f);
void			destroy_img(t_fractol **f);
int				start_windows(t_fractol **fractols);
int				expose_hook(t_fractol *f);
int				mouse_hook(int button, int x, int y, t_fractol *f);
int				key_hook(int keycode, t_fractol *f);
int				motion_hook(int x, int y, t_fractol *f);
void			describe_hook(void);
void			arrow_keys(t_fractol *f, int keycode);
void			graph_keys(t_fractol *f, int keycode);
void			color_keys(t_fractol *f, int keycode);
void			utility_keys(t_fractol *f, int keycode);
void			describe_keys(void);
void			get_palette(int index, t_fractol *f);
int				gray_palette(t_fractol *f);
int				yolo_palette(t_fractol *f);
int				colorfull_palette(t_fractol *f);
void			rotate_points_int(int *x, int *y, double rotation);
void			rotate_points_double(double *x, double *y, double rotation);
void			change_fract_type(t_fractol *f);
int				print_fractol(t_fractol *f);
void			print_fractol_type(t_fractol *f);
char			*get_fractol_name(t_fractol *f);
int				draw_by_pixels(t_fractol *f);
int				draw_by_iter(t_fractol *f);
void			draw_line(t_fractol *f, t_point p1, t_point p2, int color);
void			put_pixel(t_fractol *f, int x, int y, int color);
void			color_img(t_fractol *f, int color);
int				get_color(t_fractol *f, int iter);
int				get_smooth_color(t_fractol *f, int iter);
double complex	complexe(double x, double y);
int				draw_mandelbrot(t_fractol *f, int i, int j);
int				draw_julia(t_fractol *f, int i, int j);
int				draw_newton(t_fractol *f, int y, int x);
int				draw_burning_ship(t_fractol *f, int y, int x);
int				draw_tricorn(t_fractol *f, int y, int x);
int				draw_triangle(t_fractol *f);
double complex	polynome_1(t_fractol *f, double complex z);
double complex	derivate_1(t_fractol *f, double complex z);
double complex	polynome_2(t_fractol *f, double complex z);
double complex	derivate_2(t_fractol *f, double complex z);
double complex	polynome_3(t_fractol *f, double complex z);
double complex	derivate_3(t_fractol *f, double complex z);
int				draw_popcorn(t_fractol *f, int y, int x);
int				draw_phoenix(t_fractol *f, int y, int x);

#endif
