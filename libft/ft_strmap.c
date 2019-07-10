/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:56:13 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/09 15:51:26 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	int		i;

	if (s && f)
	{
		str = NULL;
		i = ft_strlen(s);
		if ((str = ft_strnew(i)))
			while (i--)
				str[i] = f(s[i]);
		return (str);
	}
	return (NULL);
}
