/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poligonalize.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/20 20:11:45 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/25 17:28:42 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static int				ft_height(char **map)
{
	char **tmp;

	tmp = map;
	while (*tmp)
		tmp++;
	return (tmp - map);
}

static int				ft_weight(char *map)
{
	int		check;
	int		res;
	char	*tmp;

	res = 0;
	check = 0;
	tmp = map;
	while (*tmp)
	{
		if ((char)*tmp != ' ')
		{
			if (!check)
				res++;
			check = 1;
		}
		else
			check = 0;
		tmp++;
	}
	return (res);
}

static t_vector3		**ft_free(t_vector3 **res, char **tmp2)
{
	ft_vecdel(res);
	ft_strdel(tmp2);
	return (NULL);
}

static t_vector3		**ft_split(char **tmp, t_mlx *mlx, t_coo coo,
									t_vector3 **res)
{
	char		*tmp2;

	while (*tmp)
	{
		tmp2 = *tmp;
		coo.j = 0;
		while (**tmp)
		{
			if (!ft_skip_whitespaces(tmp))
				return (ft_free(res, &tmp2));
			if (!(vector3_pushback(&res[coo.i], vector3_new(coo.j++ *
				coo.scale * MASH - coo.x, coo.i * coo.scale * MASH - coo.y,
				ft_atoi(&(**tmp)) * coo.scale * MASH, ft_seek_color(&*tmp)))))
				return (ft_free(res, &tmp2));
			ft_skip_hex(tmp);
			if (!ft_skip_whitespaces(tmp))
				return (ft_free(res, &tmp2));
		}
		coo.i++;
		tmp++;
		ft_strdel(&tmp2);
	}
	return (res);
}

t_vector3				**ft_strsplitvec(char **map, t_mlx *mlx)
{
	t_coo		coo;
	char		**tmp;
	t_vector3	**res;

	coo.i = 0;
	coo.j = 0;
	coo.x = ft_weight(*map) * MASH;
	coo.y = ft_height(map) * MASH;
	coo.scale = 1;
	if (coo.x * 1.5 > WIN_WIDTH_MAX)
		coo.scale = WIN_WIDTH_MAX / (coo.x * 1.5);
	if (coo.y * 1.5 > WIN_HEIGHT_MAX)
		if (coo.scale > WIN_HEIGHT_MAX / (coo.y * 1.5))
			coo.scale = WIN_HEIGHT_MAX / (coo.y * 1.5);
	mlx->win_x = (int)roundf((float)1.5 * (float)coo.x * coo.scale);
	mlx->win_y = (int)roundf((float)1.5 * (float)coo.y * coo.scale);
	mlx->c_x = (float)mlx->win_x / 2.0 + (mlx->win_x % 2 == 0 ? 0.5 : 0);
	mlx->c_y = (float)mlx->win_y / 2.0 + (mlx->win_x % 2 == 0 ? 0.5 : 0);
	coo.x = (int)roundf((float)coo.x * coo.scale / 2.0);
	coo.y = (int)roundf((float)coo.y * coo.scale / 2.0);
	tmp = map;
	if (!(res = malloc(sizeof(t_vector3) * (ft_vec_len(tmp) + 1))))
		return (NULL);
	vector3_null(res, ft_vec_len(tmp) + 1);
	return (ft_split(tmp, mlx, coo, res));
}
