/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 15:24:17 by acalandr          #+#    #+#             */
/*   Updated: 2019/05/25 16:12:26 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"
#include <stdio.h>

int		red_but(t_mlx *mlx)
{
	vector3_del(mlx->poly);
	mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	exit(0);
}

int		keyb(int key_press, t_mlx *mlx)
{
	if (key_press == 13 || key_press == 0 || key_press == 1 || key_press == 2)
		ft_move_2d(key_press, mlx);
	else if (key_press == 53)
		red_but(mlx);
	return (1);
}

int		ft_clamp(int nbr, int min, int max)
{
	if (nbr < min)
		return (min);
	if (nbr > max)
		return (max);
	return (nbr);
}

void	rotate(t_mlx *mlx, t_vector3 *axis, int deltax, int deltay)
{
	t_quaternion	*rot;
	t_vector3		*tmp;

	ft_bzero((void *)(mlx->map), mlx->win_x * mlx->win_y * 4);
	rot = quaternion_new_rot(axis, (abs(deltay) +
		abs(deltax)) * (M_PI * 2 / mlx->win_x));
	tmp = mlx->poly;
	while (tmp)
	{
		rotate_vector3(tmp, rot);
		tmp = tmp->next;
	}
	ft_draw(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr,
							mlx->img_ptr, 0, 0);
	free(rot);
}

int		mouse_move(int x, int y, t_mlx *mlx)
{
	static int		first = 1;
	t_vector3		*axis;
	int				deltax;
	int				deltay;

	if (!first)
	{
		if (x > 0 && y > 0 && x < mlx->win_x && y < mlx->win_y)
		{
			deltay = mlx->mouse_y - y;
			deltax = x - mlx->mouse_x;
			axis = vector3_new(deltay, deltax, (float)(deltay * deltax) / 4, 0);
			if (vector3_magnitude(axis) != 0)
			{
				rotate(mlx, axis, deltax, deltay);
			}
			free(axis);
		}
	}
	else
		first = 0;
	mlx->mouse_x = ft_clamp(x, 0, mlx->win_x);
	mlx->mouse_y = ft_clamp(y, 0, mlx->win_y);
	return (1);
}
