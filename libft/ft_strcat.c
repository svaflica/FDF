/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 16:03:55 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/04 16:24:23 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strcat(char *s1, const char *s2)
{
	char *dest;

	dest = s1;
	while (*dest)
		dest++;
	while (*s2)
		*dest++ = *s2++;
	*dest = 0;
	return (s1);
}
