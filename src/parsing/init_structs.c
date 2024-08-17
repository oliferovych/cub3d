/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 01:03:04 by dolifero          #+#    #+#             */
/*   Updated: 2024/08/17 17:27:14 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int	init_image(t_input *input, t_cubed *cubed, t_data *data)
{
	cubed->bg = mlx_new_image(cubed->mlx, WIDTH, HEIGHT);
	ceiling_floor(cubed, input);
	cubed->walls = mlx_new_image(cubed->mlx, WIDTH, HEIGHT);
	setPlane(data);
	castRays(data);
	draw_walls(cubed, data);
	write(1, "tot\n", 4);
	ft_hook(data);
	if (!init_bg_img(cubed, data) || !init_walls_img(cubed, data)
		|| !init_overlay_img(cubed, data))
		return (0);
	mlx_loop(cubed->mlx);
	mlx_terminate(cubed->mlx);
	return (1);
}

t_cubed	*init_cubed(t_input *input, char *filename)
{
	t_cubed	*cubed;

	cubed = malloc(sizeof(t_cubed));
	if (!cubed)
		return (NULL);
	cubed->title = ft_strjoin("cub3d - ", filename);
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	cubed->mlx = mlx_init(WIDTH, HEIGHT, cubed->title, 1);
	if (!cubed->mlx)
		return (ft_putendl_fd("Window initialization fail.", 2),
			free_input(input), NULL);
	return (cubed);
}

t_data	*init_data(t_input *input, t_cubed *cubed)
{
	t_data	*data;

	data = malloc(sizeof(t_data));
	if (!data)
		return (NULL);
	data->cubed = cubed;
	data->Map = input->map;
	data->posX = input->pos_x;
	data->posY = input->pos_y;
	data->fov = 90;
	setDir(data, input);
	data->wallDistances = malloc(sizeof(double) * WIDTH);
	if (!data->wallDistances)
	{
		free(data);
		return (NULL);
	}
	data->hit_side = malloc(sizeof(char) * WIDTH);
	if (!data->hit_side)
	{
		free(data->wallDistances);
		free(data);
		return (NULL);
	}
	return (data);
}
