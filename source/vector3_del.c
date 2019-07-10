/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector3_del.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:56:09 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/25 15:57:04 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

void		vector3_del(t_vector3 *del)
{
	if (del->next)
		vector3_del(del->next);
	ft_memdel((void **)&del);
}

void		ft_vecdel(t_vector3 **res)
{
	t_vector3 **tmp;
	t_vector3 *tmp2;
	t_vector3 *to_del;

	tmp = res;
	while (*tmp)
	{
		tmp2 = *tmp;
		while (tmp2)
		{
			to_del = tmp2;
			tmp2 = tmp2->next;
			ft_memdel((void**)&to_del);
		}
		tmp++;
	}
	free(res);
}
