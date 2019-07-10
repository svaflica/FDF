/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 13:15:51 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/12 11:26:21 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t len)
{
	int		i;
	char	*p;

	if ((i = 0) == 0 && !*to_find)
		return ((char*)str);
	if (!len || !*str)
		return (NULL);
	while (*str != to_find[0])
		if (*str++ == '\0' || !len--)
			return (NULL);
	p = (char*)str;
	while (to_find[i] != '\0')
	{
		if (str[i] != to_find[i] && str[i] != '\0')
		{
			str++;
			len--;
			p = ft_strnstr(str, to_find, len);
		}
		if (len - i++ < 1 || !*str)
			return (NULL);
	}
	return (p);
}
