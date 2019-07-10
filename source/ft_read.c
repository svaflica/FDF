/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/17 20:02:12 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/25 14:55:41 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static char			*ft_open_and_read(char *name)
{
	int		fd;
	char	*buf;
	char	*tmp;
	char	*res;

	fd = open(name, O_RDONLY);
	res = NULL;
	if (fd < 0 || read(fd, NULL, 0) == -1)
		return (NULL);
	if (!(buf = ft_strnew(10000000)))
		return (NULL);
	while (read(fd, buf, 10000000) > 0)
	{
		tmp = res;
		res = ft_strjoin(res, buf);
		tmp ? free(tmp) : NULL;
		if (res == NULL)
		{
			ft_strdel(&tmp);
			return (NULL);
		}
	}
	close(fd);
	ft_strdel(&buf);
	return (res);
}

char				**ft_read(char *name)
{
	char	*res;
	char	**end;

	res = ft_open_and_read(name);
	end = ft_strsplit(res, '\n');
	ft_strdel(&res);
	if (!end)
	{
		ft_pstrdel((void **)&end);
		return (NULL);
	}
	return (end);
}

static int			ft_push_poly(t_vector3 **res, t_vector3 *tmp,
								t_vector3 *tmp_l)
{
	int count;

	count = 0;
	count += vector3_pushback(res, vector3_copy(tmp_l));
	count += vector3_pushback(res, vector3_copy(tmp));
	count += vector3_pushback(res, vector3_copy(tmp->next));
	count += vector3_pushback(res, vector3_copy(tmp->next));
	count += vector3_pushback(res, vector3_copy(tmp_l->next));
	count += vector3_pushback(res, vector3_copy(tmp_l));
	return (count);
}

static t_vector3	*ft_do_poly(t_vector3 **vec)
{
	t_vector3	*tmp;
	t_vector3	*tmp_l;
	t_vector3	*res;

	res = NULL;
	while (*vec && *(vec + 1))
	{
		tmp = *vec;
		tmp_l = *(vec + 1);
		while (tmp->next && tmp_l->next)
		{
			if (ft_push_poly(&res, tmp, tmp_l) < 6)
			{
				vector3_del(res);
				return (NULL);
			}
			tmp = tmp->next;
			tmp_l = tmp_l->next;
		}
		vec++;
	}
	return (res);
}

t_vector3			*ft_parse(char **map, t_mlx *mlx)
{
	t_vector3		**point;
	t_vector3		*res;

	if (!map)
		return (ft_perror());
	point = ft_strsplitvec(map, mlx);
	if (!point)
		return (ft_perror());
	if (ft_new_mlx(mlx) == 0)
	{
		ft_pstrdel((void **)point);
		return (ft_perror());
	}
	res = ft_do_poly(point);
	ft_vecdel(point);
	return (res);
}
