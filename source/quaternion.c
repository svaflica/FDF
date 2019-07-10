/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quaternion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 17:09:31 by acalandr          #+#    #+#             */
/*   Updated: 2019/05/25 17:27:57 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_quaternion	*quaternion_new_rot(t_vector3 *axis, float angle)
{
	t_quaternion *rot;

	rot = (t_quaternion*)malloc(sizeof(t_quaternion));
	if (!rot)
		return (ft_perror());
	vector3_normal(axis);
	rot->w = cosf(angle / 2);
	rot->x = sinf(angle / 2) * axis->x;
	rot->y = sinf(angle / 2) * axis->y;
	rot->z = sinf(angle / 2) * axis->z;
	return (rot);
}

t_quaternion	*quaternion_invert(t_quaternion *q)
{
	t_quaternion	*invert;
	float			length;

	invert = (t_quaternion*)malloc(sizeof(t_quaternion));
	if (!invert)
		return (ft_perror());
	invert->w = q->w;
	invert->x = -q->x;
	invert->y = -q->y;
	invert->z = -q->z;
	length = sqrtf(powf(invert->w, 2) + powf(invert->x, 2) +
					powf(invert->y, 2) + powf(invert->z, 2));
	invert->w = invert->w / length;
	invert->x = invert->x / length;
	invert->y = invert->y / length;
	invert->z = invert->z / length;
	return (invert);
}

void			rotate_vector3(t_vector3 *vertex, t_quaternion *rot)
{
	t_quaternion *quat;
	t_quaternion *invert;

	quat = (t_quaternion*)malloc(sizeof(t_quaternion));
	if (!quat)
		ft_perror();
	quat->w = -rot->x * vertex->x - rot->y * vertex->y - rot->z * vertex->z;
	quat->x = rot->w * vertex->x + rot->y * vertex->z - rot->z * vertex->y;
	quat->y = rot->w * vertex->y - rot->x * vertex->z + rot->z * vertex->x;
	quat->z = rot->w * vertex->z + rot->x * vertex->y - rot->y * vertex->x;
	invert = quaternion_invert(rot);
	vertex->x = quat->w * invert->x + quat->x * invert->w + quat->y * invert->z
				- quat->z * invert->y;
	vertex->y = quat->w * invert->y - quat->x * invert->z + quat->y * invert->w
				+ quat->z * invert->x;
	vertex->z = quat->w * invert->z + quat->x * invert->y - quat->y * invert->x
				+ quat->z * invert->w;
	free(quat);
	free(invert);
}
