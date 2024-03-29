/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/07 10:55:00 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/12 14:49:29 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int		i;
	char	*src;

	if (s && f)
	{
		i = 0;
		src = s;
		while (s[i])
			f(i++, src++);
	}
}
