/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:33:31 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/08 15:33:24 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char ch;

	ch = c;
	while (n--)
	{
		*(unsigned char*)dst = *(unsigned char*)src;
		if (*(unsigned char*)src == ch)
		{
			dst++;
			return (dst);
		}
		src++;
		dst++;
	}
	return (NULL);
}
