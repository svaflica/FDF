/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: acalandr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/25 21:37:59 by acalandr          #+#    #+#             */
/*   Updated: 2019/05/25 21:38:09 by acalandr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_FDF_H
# define FDF_FDF_H

# include "../libft/libft.h"
# include "mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <stdio.h>

# define MASH 30
# define WIN_WIDTH_MAX 2650
# define WIN_HEIGHT_MAX 1240
# define WHITE 16777215

/*
** Mesh -> Triangles -> Vertex   ->  coords
** 	|			|			|			|
** list   3 s_vectors   s_vector     x,y,z
*/

typedef struct			s_vector3
{
	float				x;
	float				y;
	float				z;
	int					color;
	struct s_vector3	*next;
}						t_vector3;

typedef struct			s_quaternion
{
	float				w;
	float				x;
	float				y;
	float				z;
}						t_quaternion;

typedef struct			s_mlx
{
	void				*mlx_ptr;
	void				*win_ptr;
	void				*img_ptr;
	int					*map;
	t_vector3			*poly;
	int					win_x;
	int					win_y;
	float				c_y;
	float				c_x;
	int					mouse_x;
	int					mouse_y;
}						t_mlx;

/*
**		Functions which work with vectors
*/

t_vector3				*vector3_new(float x, float y, float z, int color);
t_vector3				*vector3_copy(t_vector3 *src);
void					vector3_null(t_vector3 **beg, int size);
void					vector3_del(t_vector3 *del);
void					ft_vecdel(t_vector3 **res);
int						vector3_pushback(t_vector3 **beg, t_vector3 *new);

/*
**		Function to create connection and image
*/

int						ft_new_mlx(t_mlx *mlx);

int						ft_vec_len(char **map);
void					ft_skip_num(char **map);
int						ft_skip_whitespaces(char **map);
int						ft_seek_color(char **map);

t_vector3				*ft_parse(char **map, t_mlx *mlx);
char					**ft_read(char *name);

/*
**		Funtions to draw line
*/

float					fpart(float x);
void					plot(float x, float y, int col, t_mlx *mlx);

void					ft_draw(t_mlx *mlx);
void					draw_poly(t_vector3 *triangle, t_mlx *mlx);
void					draw_line(t_vector3 *start, t_mlx *mlx);

/*
**		Function which makes list of vector3s
*/

int						ft_vec_len(char **map);
void					ft_skip_num(char **map);
int						ft_seek_color(char **map);
void					ft_skip_hex(char **map);

t_vector3				**ft_strsplitvec(char **map, t_mlx *mlx);

void					vector3_normal(t_vector3 *vector);
float					vector3_magnitude(t_vector3 *v3);
void					rotate_vector3(t_vector3 *vertex, t_quaternion *rot);
t_vector3				*vector3_cross(t_vector3 *first, t_vector3 *second);
t_vector3				*triangle_normal(t_vector3 *triangle);
t_quaternion			*quaternion_new_rot(t_vector3 *axis, float angle);
float					vector3_dot(t_vector3 *lhs, t_vector3 *rhs);
t_vector3				*vector3_cross(t_vector3 *first, t_vector3 *second);
t_vector3				*vector3_sub(t_vector3 *first, t_vector3 *second);

void					ft_move_2d(int key_press, t_mlx *mlx);
int						mouse_move(int x, int y, t_mlx *mlx);
int						red_but(t_mlx *mlx);
int						keyb(int key_press, t_mlx *mlx);
int						mouse_zoom(int button, int x, int y, t_mlx *mlx);

int						get_color(t_vector3 *current, float alpha);
int						get_col_z(t_vector3 *curr, t_vector3 *str,
		t_vector3 *end);

void					*ft_perror(void);

typedef struct			s_coo
{
	int					x;
	int					y;
	int					i;
	int					j;
	float				scale;
}						t_coo;

#endif
