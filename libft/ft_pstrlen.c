/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pstrlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/12 16:23:34 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/12 16:52:18 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_pstrlen(const char **ara)
{
	size_t count;

	count = 0;
	while (ara[count])
		count++;
	return (count);
}
