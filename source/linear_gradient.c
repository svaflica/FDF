/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linear_gradient.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 09:30:01 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/25 17:29:57 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static float	percent(int start, int end, int current)
{
	float placement;
	float distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

static int		get_light(int start, int end, float percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int				get_color(t_vector3 *current, float alpha)
{
	int			rgb[3];
	float		percentage;
	t_vector3	*delta;
	t_vector3	*start;
	t_vector3	*end;

	delta = current->next->next->next;
	start = current->next;
	end = current->next->next;
	if (current->color == end->color)
		return (current->color);
	if (delta->x > delta->y)
		percentage = percent(start->x, end->x, current->x);
	else
		percentage = percent(start->y, end->y, current->y);
	rgb[0] = get_light((start->color >> 16) & 0xFF,
			(end->color >> 16) & 0xFF, percentage) * alpha;
	rgb[1] = get_light((start->color >> 8) & 0xFF,
			(end->color >> 8) & 0xFF, percentage) * alpha;
	rgb[2] = get_light(start->color & 0xFF,
			end->color & 0xFF, percentage) * alpha;
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

int				get_col_z(t_vector3 *curr, t_vector3 *start, t_vector3 *end)
{
	int		red;
	int		green;
	int		blue;
	float	percentage;

	if (curr->color == end->color)
		return (curr->color);
	percentage = percent(-20, 20, curr->z);
	red = get_light((start->color >> 16) & 0xFF,
			(end->color >> 16) & 0xFF, percentage);
	green = get_light((start->color >> 8) & 0xFF,
			(end->color >> 8) & 0xFF, percentage);
	blue = get_light(start->color & 0xFF,
			end->color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
