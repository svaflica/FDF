/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:02:40 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/25 17:27:08 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_vector3	*vector3_cross(t_vector3 *first, t_vector3 *second)
{
	return (vector3_new(first->y * second->z - first->z * second->y,
						first->z * second->x - first->x * second->z,
						first->x * second->y - first->y * second->x, WHITE));
}

float		vector3_magnitude(t_vector3 *v3)
{
	return (sqrtf(powf(v3->x, 2) + powf(v3->y, 2) + powf(v3->z, 2)));
}

void		vector3_normal(t_vector3 *vector)
{
	float length;

	length = vector3_magnitude(vector);
	vector->x = vector->x / length;
	vector->y = vector->y / length;
	vector->z = vector->z / length;
}

t_vector3	*vector3_sub(t_vector3 *first, t_vector3 *second)
{
	return (vector3_new(first->x - second->x, first->y - second->y,
						first->z - second->z, WHITE));
}

t_vector3	*triangle_normal(t_vector3 *triangle)
{
	t_vector3 *normal;
	t_vector3 *first;
	t_vector3 *second;

	first = vector3_sub(triangle, triangle->next);
	second = vector3_sub(triangle->next->next, triangle->next);
	normal = vector3_cross(first, second);
	free(first);
	free(second);
	return (normal);
}
