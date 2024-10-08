/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tomecker <tomecker@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 18:45:02 by dolifero          #+#    #+#             */
/*   Updated: 2024/09/03 18:49:37 by tomecker         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

void	pad_strings(char **arr, int i)
{
	int	max_length;
	int	len;

	if (arr == NULL)
		return ;
	max_length = 0;
	while (arr[++i])
	{
		len = ft_strlen(arr[i]);
		if (len > max_length)
			max_length = len;
	}
	i = -1;
	while (arr[++i])
	{
		len = ft_strlen(arr[i]);
		if (len < max_length)
		{
			arr[i] = ft_realloc(arr[i], len, max_length + 1);
			ft_memset(arr[i] + len, ' ', max_length - len);
			arr[i][max_length] = '\0';
		}
	}
	arr[i] = NULL;
}

int	ft_count_map(t_data *data, char c)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (i < data->input->map_height)
	{
		j = 0;
		while (j < data->input->map_width)
		{
			if (data->map[i][j] == c)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	delete_img(t_data *data)
{
	mlx_delete_texture(data->texture->n);
	mlx_delete_texture(data->texture->s);
	mlx_delete_texture(data->texture->w);
	mlx_delete_texture(data->texture->e);
}
