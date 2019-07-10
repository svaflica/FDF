/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:23:25 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/12 14:40:18 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void *p;

	if (size < 1)
		return (NULL);
	if ((p = malloc(size)))
		return (ft_memset(p, 0, size));
	return (NULL);
}
