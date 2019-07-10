/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:33:53 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/11 20:26:47 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char *p;

	if (!src && !dst)
		return (NULL);
	p = (char*)dst;
	while (n--)
	{
		*p = *(unsigned char*)src;
		p++;
		src++;
	}
	return (dst);
}
