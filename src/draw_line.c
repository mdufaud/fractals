/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdufaud <mdufaud@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 18:45:53 by mdufaud           #+#    #+#             */
/*   Updated: 2015/06/27 18:52:41 by mdufaud          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_trace	init_trace(t_rpoint p, t_rpoint p1)
{
	t_trace	trace;

	trace.sx = p.x < p1.x ? 1 : -1;
	trace.sy = p.y < p1.y ? 1 : -1;
	trace.dx = p1.x - p.x > 0 ? p1.x - p.x : p.x - p1.x;
	trace.dy = p1.y - p.y > 0 ? p1.y - p.y : p.y - p1.y;
	trace.err = trace.dx - trace.dy;
	return (trace);
}

static void		do_op(t_rpoint *p, t_trace *t, int node)
{
	if (node)
	{
		t->err += t->dx;
		p->y = p->y + t->sy;
	}
	else
	{
		t->err -= t->dy;
		p->x = p->x + t->sx;
	}
}

static void		real_point(t_point p1, t_point p2, t_rpoint *r1, t_rpoint *r2)
{
	r1->x = (int)p1.x;
	r1->y = (int)p1.y;
	r2->x = (int)p2.x;
	r2->y = (int)p2.y;
}

void			draw_line(t_fractol *f, t_point p, t_point p1, int color)
{
	int			delta;
	t_trace		trace;
	t_rpoint	r;
	t_rpoint	r1;

	real_point(p, p1, &r, &r1);
	trace = init_trace(r, r1);
	while (1)
	{
		put_pixel(f, r.x, r.y, color);
		if (r.x == r1.x && r.y == r1.y)
			break ;
		delta = 2 * trace.err;
		if (delta > -trace.dy)
			do_op(&r, &trace, 0);
		if (r.x == r1.x && r.y == r1.y)
		{
			put_pixel(f, r.x, r.y, color);
			break ;
		}
		if (delta < trace.dx)
			do_op(&r, &trace, 1);
	}
}
