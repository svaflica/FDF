/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:36:52 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/04 14:52:43 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*src;
	const unsigned char	*dst;

	src = s1;
	dst = s2;
	while (n--)
	{
		if (*dst != *src)
			return (*src - *dst);
		else
		{
			src++;
			dst++;
		}
	}
	return (0);
}
