/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 16:49:09 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/13 16:14:48 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *s)
{
	int		mult;
	long	result;

	while (ft_isspace(*s))
		s++;
	mult = 1;
	if (*s == '-' || *s == '+')
		if (*s++ == '-')
			mult = -1;
	result = 0;
	while (ft_isdigit(*s))
	{
		if (mult < 0 && (result > LONG_MAX / 10
		|| (result == LONG_MAX / 10 && *s - 48 > LONG_MIN % 10)))
			return ((int)LONG_MIN);
		else if (mult > 0 && (result > LONG_MAX / 10
		|| (result == LONG_MAX / 10 && *s - 48 > LONG_MAX % 10)))
			return ((int)LONG_MAX);
		result = result * 10 + (*s - 48);
		s++;
	}
	return (result * mult);
}
