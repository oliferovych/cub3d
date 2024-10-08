/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:02:11 by dolifero          #+#    #+#             */
/*   Updated: 2024/09/03 19:29:12 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void	ft_movement_hook(void *param)
{
	t_data	*data;
	mlx_t	*mlx;
	double	speed;

	data = (t_data *)param;
	speed = 1 / data->speed;
	mlx = data->cubed->mlx;
	if (mlx_is_key_down(mlx, MLX_KEY_W))
		move_forward(data, speed);
	else if (mlx_is_key_down(mlx, MLX_KEY_S))
		move_forward(data, -speed);
	else if (mlx_is_key_down(mlx, MLX_KEY_D))
		move_right(data, speed);
	else if (mlx_is_key_down(mlx, MLX_KEY_A))
		move_right(data, -speed);
}

void	ft_camera_hook(void *param)
{
	t_data	*data;
	double	angle;
	double	olddir_x;
	double	olddir_y;

	angle = 4 * (M_PI / 180);
	data = param;
	olddir_x = data->dir_x;
	olddir_y = data->dir_y;
	if (mlx_is_key_down(data->cubed->mlx, MLX_KEY_RIGHT))
	{
		data->dir_x = cos(angle) * olddir_x - sin(angle) * olddir_y;
		data->dir_y = sin(angle) * olddir_x + cos(angle) * olddir_y;
	}
	if (mlx_is_key_down(data->cubed->mlx, MLX_KEY_LEFT))
	{
		data->dir_x = cos(angle) * olddir_x + sin(angle) * olddir_y;
		data->dir_y = -sin(angle) * olddir_x + cos(angle) * olddir_y;
	}
}

void	ft_window_hook(struct mlx_key_data key, void *param)
{
	t_data	*data;

	data = param;
	if (key.key == MLX_KEY_ESCAPE && key.action == MLX_PRESS)
		mlx_close_window(data->cubed->mlx);
}
