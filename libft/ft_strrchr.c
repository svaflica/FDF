/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 12:55:00 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/12 14:14:24 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	char *p;
	char *curp;

	curp = (char*)s;
	p = NULL;
	while (*curp)
	{
		if (*curp == (unsigned char)c)
			p = curp;
		curp++;
	}
	if (*curp == (unsigned char)c)
		p = curp;
	return (p);
}
