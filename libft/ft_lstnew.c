/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 12:06:35 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/20 12:49:46 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if ((new = (t_list*)malloc(sizeof(t_list))))
	{
		new->next = NULL;
		if (content)
			if ((new->content = ft_memalloc(content_size)))
			{
				new->content = ft_memcpy(new->content, content, content_size);
				new->content_size = content_size;
			}
			else
			{
				free(new);
				return (NULL);
			}
		else
		{
			new->content = NULL;
			new->content_size = 0;
		}
		return (new);
	}
	return (NULL);
}
