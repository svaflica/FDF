/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:46:34 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/25 10:44:08 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		draw_y(t_vector3 *v1, t_vector3 *v2, t_mlx *mlx, float a)
{
	float		x;
	float		y;
	float		inter;
	t_vector3	*current;

	x = v1->x;
	y = v1->y;
	plot(x, y, v1->color, mlx);
	inter = x + a;
	y++;
	while (y < v2->y)
	{
		current = vector3_new(x, y, 0, v1->color + v2->color + 2);
		current->next = vector3_copy(v1);
		current->next->next = vector3_copy(v2);
		current->next->next->next = vector3_new(v2->x - v1->x,
				v2->y - v1->y, 0, v1->color + v2->color + 2);
		plot(inter, y, get_color(current, 1 - fpart(inter)), mlx);
		plot(inter + 1, y, get_color(current, fpart(inter)), mlx);
		y++;
		inter += a;
		vector3_del(current);
	}
	plot(v2->x, v2->y, v2->color, mlx);
}

static void		draw_x(t_vector3 *v1, t_vector3 *v2, t_mlx *mlx, float a)
{
	float		x;
	float		y;
	float		inter;
	t_vector3	*current;

	x = v1->x;
	y = v1->y;
	plot(x, y, v1->color, mlx);
	inter = y + a;
	x++;
	while (x < v2->x)
	{
		current = vector3_new(x, y, 0, v1->color + v2->color + 2);
		current->next = vector3_copy(v1);
		current->next->next = vector3_copy(v2);
		current->next->next->next = vector3_new(v2->x - v1->x,
				v2->y - v1->y, 0, v1->color + v2->color + 2);
		plot(x, inter, get_color(current, 1 - fpart(inter)), mlx);
		plot(x, inter + 1, get_color(current, fpart(inter)), mlx);
		x++;
		inter += a;
		vector3_del(current);
	}
	plot(v2->x, v2->y, v2->color, mlx);
}

void			draw_line(t_vector3 *start, t_mlx *mlx)
{
	float dx;
	float dy;
	float a;

	dx = start->next->x - start->x;
	dy = start->next->y - start->y;
	if (fabsf(dy) < fabsf(dx))
	{
		a = dy / dx;
		if (start->x > start->next->x)
			draw_x(start->next, start, mlx, a);
		else
			draw_x(start, start->next, mlx, a);
	}
	else
	{
		a = dx / dy;
		if (start->y > start->next->y)
			draw_y(start->next, start, mlx, a);
		else
			draw_y(start, start->next, mlx, a);
	}
}

void			draw_poly(t_vector3 *triangle, t_mlx *mlx)
{
	t_vector3	*normal;

	normal = triangle_normal(triangle);
	if (normal->z * -1 > 0)
	{
		draw_line(triangle, mlx);
		draw_line(triangle->next, mlx);
	}
	free(normal);
}

void			ft_draw(t_mlx *mlx)
{
	t_vector3 *tmp;

	tmp = mlx->poly;
	while (tmp && tmp->next && tmp->next->next)
	{
		draw_poly(tmp, mlx);
		tmp = tmp->next->next->next;
	}
}
