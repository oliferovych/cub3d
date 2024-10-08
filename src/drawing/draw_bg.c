/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 01:06:15 by dolifero          #+#    #+#             */
/*   Updated: 2024/09/03 17:02:49 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void	draw_bg(t_data *data, t_input *input)
{
	int		i;
	int		j;

	i = 0;
	while (i < HEIGHT / 2)
	{
		j = -1;
		while (++j < WIDTH)
			my_put_pixel(data->cubed->bg, j, i,
				input->ceiling);
		i++;
	}
	while (i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			my_put_pixel(data->cubed->bg, j, i,
				input->floor);
		i++;
	}
}
