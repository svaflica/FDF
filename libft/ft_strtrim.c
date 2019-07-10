/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:58:30 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/12 15:40:38 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int cut;
	int len;

	if (s)
	{
		cut = 0;
		len = ft_strlen(s) - 1;
		while (ft_isspace(s[cut]))
			cut++;
		while ((ft_isspace(s[len])) && cut < len)
			len--;
		return (ft_strsub(s, cut, len - cut + 1));
	}
	return (NULL);
}
