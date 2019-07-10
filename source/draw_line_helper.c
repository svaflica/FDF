/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 10:40:58 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/25 17:21:40 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

float	fpart(float nbr)
{
	if ((nbr - (int)nbr) >= 0)
		return (nbr - (int)nbr);
	else
		return (nbr - (int)nbr + 1.0);
}

void	plot(float x, float y, int col, t_mlx *mlx)
{
	int rx;
	int ry;

	rx = (int)roundf(x + mlx->c_x);
	ry = (int)roundf(y + mlx->c_y);
	if (rx > 0 && rx < mlx->win_x && ry > 0 && ry < mlx->win_y)
		mlx->map[rx + ry * mlx->win_x] = col;
}
