/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:18:33 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/04 16:42:49 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *dest;

	dest = s1;
	while (*dest)
		dest++;
	while (*s2 && n--)
		*dest++ = *s2++;
	*dest = 0;
	return (s1);
}
