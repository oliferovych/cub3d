/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 01:46:29 by dolifero          #+#    #+#             */
/*   Updated: 2024/08/17 01:26:54 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void	print_input(t_input *input)
{
	printf("\n");
	printf("Wall N: %s\n", input->wall_n);
	printf("Wall S: %s\n", input->wall_s);
	printf("Wall W: %s\n", input->wall_w);
	printf("Wall E: %s\n", input->wall_e);
	printf("\n");
	printf("Ceiling color: %X\n", input->ceiling);
	printf("Floor color: %X\n", input->floor);
	printf("\n");
	printf("Player posY: %f\n", input->pos_y);
	printf("Player posX: %f\n", input->pos_x);
	printf("View direction: %c\n", input->view_dir);
	printf("\n");
}

void	print_map(t_input *input)
{
	int	i;

	i = 0;
	while (input->map[i])
	{
		printf("%s\n", input->map[i]);
		i++;
	}
	printf("\n");
}

void	print_dist(t_data *data)
{
	for (int x = 0; x < WIDTH; x++)
        printf("Ray %d: Distance to wall = %f\n", x, data->wallDistances[x]);
}