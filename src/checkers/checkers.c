/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dolifero <dolifero@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/10 22:19:41 by dolifero          #+#    #+#             */
/*   Updated: 2024/08/17 01:25:59 by dolifero         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cubed.h"

int	ft_isappr(char c)
{
	return ((c >= '0' && c <= '9') || c == 'N'
		|| c == 'W' || c == 'S' || c == 'E'
		|| c == ' ');
}

int	check_args(int argc, char **argv)
{
	if (argc != 2)
		return (ft_putendl_fd("Insufficient amount of arguments", 2), 0);
	if (!ft_strstr(argv[1], ".cub"))
	{
		ft_putendl_fd("Wrong filetype", 2);
		ft_printf("(The input must be of the .cub format)\n");
		return (0);
	}
	if (access(argv[1], F_OK) != 0)
		return (ft_putendl_fd("File doesn't exist or not accessible", 2), 0);
	return (1);
}

int	check_params(t_input *input)
{
	if (!input->wall_e || !input->wall_n
		|| !input->wall_s || !input->wall_w
		|| !input->ceiling || !input->floor)
		return (0);
	return (1);
}

int	check_input(t_input *input)
{
	if (!input)
		return (ft_putendl_fd("Input allocation failed", 2), 0);
	if (!check_params(input))
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Missing parameters", 2);
		free_input(input);
		return (0);
	}
	if (!check_map(input->map, input))
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Wrong map", 2);
		free_input(input);
		return (0);
	}
	return (1);
}