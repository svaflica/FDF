/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moving.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djeanna <djeanna@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:00:18 by djeanna           #+#    #+#             */
/*   Updated: 2019/05/25 17:24:07 by djeanna          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/fdf.h"

static void		ft_get_shift(int key_press, int *x_shift, int *y_shift)
{
	*x_shift = 0;
	*y_shift = 0;
	if (key_press == 13)
		*y_shift = -10;
	else if (key_press == 1)
		*y_shift = 10;
	else if (key_press == 0)
		*x_shift = -10;
	else if (key_press == 2)
		*x_shift = 10;
}

void			ft_move_2d(int key_press, t_mlx *mlx)
{
	int			x_shift;
	int			y_shift;
	t_vector3	*tmp;

	ft_get_shift(key_press, &x_shift, &y_shift);
	tmp = mlx->poly;
	ft_bzero((void *)(mlx->map), mlx->win_x * mlx->win_y * 4);
	while (tmp && tmp->next && tmp->next->next)
	{
		tmp->x += x_shift;
		tmp->next->x += x_shift;
		tmp->next->next->x += x_shift;
		tmp->y += y_shift;
		tmp->next->y += y_shift;
		tmp->next->next->y += y_shift;
		draw_poly(tmp, mlx);
		tmp = tmp->next->next->next;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
}

static float	ft_scale(int button)
{
	if (button == 4)
		return (0.8);
	else if (button == 5)
		return (1.2);
	else
		return (1);
}

int				mouse_zoom(int button, int x, int y, t_mlx *mlx)
{
	float		scale;
	t_vector3	*tmp;

	scale = ft_scale(button);
	if (scale == 1)
		return (1);
	tmp = mlx->poly;
	ft_bzero((void *)(mlx->map), mlx->win_x * mlx->win_y * 4);
	while (tmp && tmp->next && tmp->next->next)
	{
		tmp->x *= scale;
		tmp->next->x *= scale;
		tmp->next->next->x *= scale;
		tmp->y *= scale;
		tmp->next->y *= scale;
		tmp->next->next->y *= scale;
		tmp->z *= scale;
		tmp->next->z *= scale;
		tmp->next->next->z *= scale;
		draw_poly(tmp, mlx);
		tmp = tmp->next->next->next;
	}
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, mlx->img_ptr, 0, 0);
	return (0);
}
