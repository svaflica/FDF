/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 18:15:04 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/13 11:36:36 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_itoa(int n)
{
	char	c;
	char	*str;
	int		i;
	int		temp;
	int		neg;

	i = 1;
	c = ft_rvminint(&n);
	i += (neg = ft_isabs(&n));
	temp = n;
	while ((temp /= 10) != 0)
		i++;
	if (!(str = ft_strnew(i)))
		return (NULL);
	while (i--)
	{
		str[i] = c + n % 10;
		if (i == 0 && neg)
			str[i] = '-';
		c = '0';
		n /= 10;
	}
	return (str);
}
