/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt_types_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:10:21 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:17:35 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_TYPES_BONUS_H
# define MINIRT_TYPES_BONUS_H

# include "libft.h"

// window/pixel size
# define WIDTH 800
# define HEIGHT 600

# define PI 3.14159265358979323846
# define EPSILON 0.000001

# define AMBIENT_ID		"A"
# define CAMERA_ID		"C"
# define LIGHT_ID		"L"
# define TEXTURE_ID		"BU"
# define CHECKER_ID		"CK"
# define SPHERE_ID		"sp"
# define PLANE_ID		"pl"
# define CYLINDER_ID	"cy"
# define CONE_ID		"co"

# define RT_EXT	".rt"

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_vec	t_color;

typedef struct s_ambient
{
	double	light_ratio;
	t_color	color;
}	t_ambient;

typedef struct s_camera
{
	t_vec	pos;
	double	fov;
	t_vec	x;
	t_vec	y;
	t_vec	z;
}	t_camera;

typedef struct s_light
{
	t_vec	pos;
	t_color	color;
	double	brightness;
}	t_light;

/*-----------------------------OBJECTS-------------------------------*/

typedef struct s_sphere
{
	t_vec	pos;
	t_color	color;
	double	diameter;
	double	r;
}	t_sphere;

typedef struct s_plane
{
	t_vec	pos;
	t_vec	normal;
	t_color	color;
	t_vec	axis_x;
	t_vec	axis_y;
}	t_plane;

typedef struct s_cylinder
{
	t_vec	pos;
	t_vec	axis;
	double	diameter;
	double	r;
	double	height;
	t_color	color;
	t_vec	axis_x;
	t_vec	axis_y;
}	t_cylinder;

typedef struct s_cone
{
	t_vec	pos;
	t_vec	axis;
	double	angle;
	double	height;
	t_color	color;
	t_vec	axis_x;
	t_vec	axis_y;
}	t_cone;

typedef enum e_obj_type
{
	OBJ_SP,
	OBJ_PL,
	OBJ_CY,
	OBJ_CO
}	t_obj_type;

typedef struct s_object
{
	void		*obj;
	t_obj_type	type;
}	t_object;

/*------------------------------------------------------------*/

typedef struct s_rotate
{
	t_vec	n;
	double	theta;
}	t_rotate;

typedef struct s_info
{
	int			flag;
	t_ambient	amb;
	t_camera	cam;
	t_list		*lights;
	t_list		*objs;
	t_vec		dx;
	t_vec		dy;
	t_vec		origin;
	t_rotate	rot;
}	t_info;

typedef struct s_ray
{
	t_vec	pos;
	t_vec	d;
}	t_ray;

typedef struct s_hit_info
{
	t_vec	n;
	t_vec	p;
	t_color	color;
	double	t_min;
	double	t_max;
	int		front_face;
	double	len_u;
	double	len_v;
}	t_hit_info;

typedef struct s_quad_eq
{
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	r1;
	double	r2;
}	t_quad_eq;

typedef enum e_error_type
{
	DEFAULT_ERR,
	MALLOC_ERR,
	FILE_ERR,
	INVALID_ID_ERR,
	INVALID_FORMAT_ERR,
	DIVIDE_BY_ZERO,
	INVALID_ARGNUM_ERR
}	t_error_type;

typedef enum e_flag_type
{
	FLAG_AMB = 1,
	FLAG_CAM = 2,
	FLAG_LIGHT = 4,
	FLAG_TEXTURE = 8,
	FLAG_CHECKER = 16
}	t_flag_type;

#endif
