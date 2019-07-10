/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 12:03:11 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/18 18:50:29 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	char	*d;

	d = dest;
	while (*src)
	{
		if (!n--)
			return (d);
		*dest++ = *src++;
	}
	while (n--)
		*dest++ = '\0';
	return (d);
}
