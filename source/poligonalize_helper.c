/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   poligonalize_helper.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 15:57:55 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/25 15:58:01 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int			ft_vec_len(char **map)
{
	char **tmp;

	tmp = map;
	while (*tmp)
		tmp++;
	return (tmp - map);
}

void		ft_skip_num(char **map)
{
	while ((**map >= '0' && **map <= '9') || **map == '-')
		*map = *map + 1;
	if (**map == ',')
		*map = *map + 1;
}

int			ft_skip_whitespaces(char **map)
{
	while (**map == ' ')
		*map = *map + 1;
	if (**map && **map != '-' && (**map < '0' || **map > '9'))
		return (0);
	return (1);
}

int			ft_seek_color(char **map)
{
	ft_skip_num(map);
	if (**map == '0')
		return (ft_atoi_hex(*map));
	return (-1);
}

void		ft_skip_hex(char **map)
{
	while ((**map >= '0' && **map <= '9') || **map == 'x' ||
		(**map >= 'A' && **map <= 'F') || (**map >= 'a' && **map <= 'f'))
		*map = *map + 1;
}
