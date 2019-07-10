/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 16:08:30 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/19 16:08:32 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_skip_len(char **str)
{
	while ((**str >= 'A' && **str <= 'F') || (**str >= '0' && **str <= '9')
	|| **str)
		*str = *str + 1;
	*str = *str - 1;
}

int			ft_atoi_hex(char *str)
{
	int	res;
	int	mul;

	res = 0;
	mul = 1;
	str += 2;
	ft_skip_len(&str);
	while (*str != 'x')
	{
		if (*str >= 'A' && *str <= 'F')
			res = res + ((*str - 'A') + 10) * mul;
		else if (*str >= '0' && *str <= '9')
			res = res * 10 + (*str - '0');
		mul *= 16;
		str--;
	}
	return (res);
}
