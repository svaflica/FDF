/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <acalandr@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 13:35:53 by acalandr          #+#    #+#             */
/*   Updated: 2019/04/16 19:29:47 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static void	del(void *content, size_t size)
{
	(void)size;
	ft_memdel(&content);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *nextlst;
	t_list *newlst;

	if (lst && f)
	{
		if ((newlst = (t_list*)malloc(sizeof(t_list))))
		{
			if (!(newlst = f(lst)))
				ft_lstdel(&newlst, del);
			else
			{
				nextlst = lst->next;
				newlst->next = ft_lstmap(nextlst, f);
				return (newlst);
			}
		}
	}
	return (NULL);
}
