/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/13 14:44:13 by acalandr          #+#    #+#             */
/*   Updated: 2019/05/25 17:27:16 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

t_vector3	*vector3_new(float x, float y, float z, int color)
{
	t_vector3 *new;

	if (!(new = (t_vector3*)malloc(sizeof(t_vector3))))
		return (ft_perror());
	new->x = x;
	new->y = y;
	new->z = z;
	new->next = NULL;
	new->color = color;
	if (color == -1)
	{
		if (new->z < 0)
			new->color = get_col_z(vector3_new(x, y, z, -2),
									vector3_new(0, 0, -100, 0x009999),
									vector3_new(0, 0, 0, 0x0F4FA8));
		else
			new->color = get_col_z(vector3_new(x, y, z * (-1), -2),
									vector3_new(0, 0, -100, 0x009999),
									vector3_new(0, 0, 100, 0x00BB3F));
	}
	return (new);
}

int			vector3_pushback(t_vector3 **beg, t_vector3 *new)
{
	t_vector3 *tmp;

	if (new == NULL)
		return (0);
	if (!*beg)
	{
		*beg = new;
		return (1);
	}
	tmp = *beg;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (1);
}

t_vector3	*vector3_copy(t_vector3 *src)
{
	return (vector3_new(src->x, src->y, src->z, src->color));
}

void		vector3_null(t_vector3 **beg, int size)
{
	while (--size >= 0)
		beg[size] = NULL;
}
