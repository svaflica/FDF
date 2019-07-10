/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:56:46 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/09 15:51:36 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	int		i;

	if (s && f)
	{
		str = NULL;
		i = ft_strlen(s);
		if ((str = ft_strnew(i)))
			while (i--)
				str[i] = f(i, s[i]);
		return (str);
	}
	return (NULL);
}
