/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:57:21 by miniore           #+#    #+#             */
/*   Updated: 2025/01/23 12:33:20 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static void	delete_images(t_game *game)
{
	if (game->floor_img)
		mlx_delete_image(game->wndw, game->floor_img);
	if (game->wall_img)
		mlx_delete_image(game->wndw, game->wall_img);
	if (game->player_img)
		mlx_delete_image(game->wndw, game->player_img);
	if (game->collect_img)
		mlx_delete_image(game->wndw, game->collect_img);
	if (game->end_img)
		mlx_delete_image(game->wndw, game->end_img);
}

void	end_game(t_game *game)
{
	delete_images(game);
	mlx_terminate(game->wndw);
	free_array(game->map);
	free(game);
	exit(EXIT_SUCCESS);
}

void	ft_perror(t_game *game, char *error_message)
{
	ft_putstr_fd(error_message, 2);
	delete_images(game);
	mlx_terminate(game->wndw);
	free_array(game->map);
	free(game);
	exit(EXIT_FAILURE);
}
