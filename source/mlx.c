/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/22 11:56:16 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/25 14:13:17 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

int				ft_new_mlx(t_mlx *mlx)
{
	int bpp;
	int bpp2;
	int endian;

	if (!(mlx->mlx_ptr = mlx_init()))
		return (ft_perror() != NULL);
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, mlx->win_x, mlx->win_y, "FDF");
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, mlx->win_x, mlx->win_y);
	mlx->map = (int *)mlx_get_data_addr(mlx->img_ptr, &bpp, &bpp2, &endian);
	return (1);
}
