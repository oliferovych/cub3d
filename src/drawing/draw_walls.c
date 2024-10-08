/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 01:26:38 by dolifero          #+#    #+#             */
/*   Updated: 2024/09/03 17:12:29 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void	redraw(void *param)
{
	t_data	*data;

	data = (t_data *)param;
	setplane(data);
	castrays(data);
	clear_image(data->cubed->walls);
	draw(data);
}

void	print_wall_line(t_data *data, int x, int hit_c)
{
	int	color;

	while (data->texture->start_y < data->texture->end_y)
	{
		data->texture->tex_y = (int)data->texture->tex_pos \
			% data->hit[x][hit_c].tex->height;
		data->texture->tex_pos += data->texture->step;
		if (is_pixel_transp(data->cubed->walls, x, data->texture->start_y))
		{
			color = get_texture_color(data->hit[x][hit_c].tex,
					data->hit[x][hit_c].tex_x, data->texture->tex_y);
			if (color != 0x00000000)
				my_put_pixel(data->cubed->walls, x, data->texture->start_y,
					color);
		}
		data->texture->start_y++;
	}
}

void	draw_walls(t_data *data, int x, int hit_c)
{
	int	height;

	height = HEIGHT / data->hit[x][hit_c].distance;
	data->texture->start_y = -height / 2 + HEIGHT / 2;
	if (data->texture->start_y < 0)
		data->texture->start_y = 0;
	data->texture->end_y = height / 2 + HEIGHT / 2;
	if (data->texture->end_y >= HEIGHT)
		data->texture->end_y = HEIGHT - 1;
	data->texture->step = 1.0 * data->hit[x][hit_c].tex->height / height;
	data->texture->tex_pos = (data->texture->start_y \
		- HEIGHT / 2 + height / 2) * data->texture->step;
	print_wall_line(data, x, hit_c);
}

void	draw(t_data *data)
{
	int	x;

	x = 0;
	while (x < WIDTH)
	{
		draw_walls(data, x, 0);
		x++;
	}
}
