/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyowchoi <hyowchoi@student.42seoul.>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/17 14:11:49 by hyowchoi          #+#    #+#             */
/*   Updated: 2024/03/17 14:17:35 by hyowchoi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACE_BONUS_H
# define RAY_TRACE_BONUS_H

# include "vector_bonus.h"
# include "mlx_info_bonus.h"
# include "parse_bonus.h"

# define CHECKER_N	10

// init_objs_axis.c
void	get_objs_axis(t_list *objs);

t_color	shoot_ray_to_viewport(t_vars *vars, t_ray *r);

// draw_phong_lighting.c
t_color	phong_lighting(t_vars *vars, t_info *info, t_ray *r, t_hit_info *hit);

// draw_shadow.c
int		is_shadow(t_vars *vars, t_info *info, t_light *l, t_hit_info *h);

// render_viewport.c
void	render_viewport(t_info *info, t_vars *vars);
int		shoot_ray_to_objects(t_vars *vars, \
							t_list *objs, t_ray *r, t_hit_info *hit);

// object_sphere.c
int		shoot_ray_to_sphere(t_vars *vars, \
							t_sphere *sphere, t_ray *r, t_hit_info *hit);

// object_plane.c
int		shoot_ray_to_plane(t_vars *vars, t_plane *p, t_ray *r, t_hit_info *hit);

// object_cylinder.c
int		shoot_ray_to_cylinder(t_vars *vars, \
							t_cylinder *c, t_ray *r, t_hit_info *hit);

// object_cone.c
int		shoot_ray_to_cone(t_vars *vars, \
							t_cone *cone, t_ray *ray, t_hit_info *hit);

// objects_utils.c
void	solve_quardatic_eq(t_quad_eq *sol);
int		update_hit_info(t_quad_eq *sol, t_hit_info *hit);

// draw_pattern.c
t_color	get_checker(t_hit_info *hit, t_color c);

// parse_bumpmap.c
int		get_pixel_grayscale(t_data *data, int u, int v);
t_color	get_pixel_color(t_data *data, int u, int v);

// check_invalid_angle.c
double	check_acos(double val);

#endif
