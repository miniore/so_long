/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:57:21 by miniore           #+#    #+#             */
/*   Updated: 2025/01/22 18:49:53 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

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
	if(game->floor_img)
		mlx_delete_image(game->window, game->floor_img);
	if(game->wall_img)
		mlx_delete_image(game->window, game->wall_img);
	if(game->player_img)
		mlx_delete_image(game->window, game->player_img);
	if(game->collect_img)
		mlx_delete_image(game->window, game->collect_img);
	if(game->end_img)
		mlx_delete_image(game->window, game->end_img);
}

void	end_game(t_game *game)
{
	mlx_terminate(game->window);
	delete_images(game);
	free_array(game->map);
	free(game);
	exit(EXIT_SUCCESS);
}

void	ft_perror(t_game *game, char *error_message)
{
	ft_putstr_fd(error_message, 2);
	delete_images(game);
	free_array(game->map);
	free(game);
	exit(EXIT_FAILURE);
}
