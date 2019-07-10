/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 15:39:13 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/10 12:14:22 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *str, const char *to_find)
{
	int i;

	if (!*to_find)
		return ((char*)str);
	while (*str != to_find[0])
		if (*str++ == '\0')
			return (NULL);
	i = 0;
	while (to_find[i] != '\0')
	{
		if (str != 0 && str[i] != to_find[i])
		{
			str++;
			str = ft_strstr(str, to_find);
		}
		i++;
	}
	return ((char*)str);
}
