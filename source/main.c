/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:46:34 by acalandr          #+#    #+#             */
/*   Updated: 2019/05/25 17:24:19 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

int		main(int c, char **v)
{
	t_mlx		mlx;

	if (!(mlx.poly = ft_parse(ft_read(v[1]), &mlx)))
		return (-1);
	mlx.mouse_x = 0;
	mlx.mouse_y = 0;
	ft_draw(&mlx);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.win_ptr, mlx.img_ptr, 0, 0);
	mlx_hook(mlx.win_ptr, 2, 1L << 0, &keyb, &mlx);
	mlx_hook(mlx.win_ptr, 17, 1L << 2, &red_but, &mlx);
	mlx_hook(mlx.win_ptr, 6, 1L << 2, &mouse_move, &mlx);
	mlx_hook(mlx.win_ptr, 4, 1L << 2, &mouse_zoom, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
