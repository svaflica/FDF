/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:26:31 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/12 13:35:06 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d;

	if (!dst && !src)
		return (NULL);
	d = dst;
	if (dst < src)
		ft_memcpy(d, src, len);
	else
	{
		d += len - 1;
		src += len - 1;
		while (len--)
		{
			*d = *(unsigned char*)src;
			d--;
			src--;
		}
	}
	return (dst);
}
