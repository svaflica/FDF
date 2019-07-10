/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 14:35:14 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/21 17:58:45 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char *src;

	src = (unsigned char*)b;
	while (len--)
	{
		*src = (unsigned char)c;
		src++;
	}
	return (b);
}
