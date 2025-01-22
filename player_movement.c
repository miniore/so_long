/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:55:33 by miniore           #+#    #+#             */
/*   Updated: 2025/01/22 14:58:29 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static void	end_checker(t_game *game, int y, int x)
{	
	if(game->map[y][x] == COLLECT)
		game->collectives -= 1;
	if(game->collectives == 0 && game->map[y][x] == END)
		end_game(game);
}

void	move_player_w(t_game *game, int y, int x)
{
	end_checker(game, y - 1, x);
	if(game->map[y - 1][x] == END && game->collectives != 0)
		return;
	mlx_image_to_window(game->window, game->player_img, x * 64, (y - 1) * 64);
	mlx_image_to_window(game->window, game->floor_img, x * 64, y * 64);
	game->map[y][x] = FLOOR;
	game->map[y - 1][x] = PLAYER;
	game->movements += 1;
	ft_printf("Movement number: %i\n", game->movements);
}

void	move_player_a(t_game *game, int y, int x)
{
	end_checker(game, y, x - 1);
	if(game->map[y][x - 1] == END && game->collectives != 0)
		return;
	mlx_image_to_window(game->window, game->player_img, (x - 1) * 64, y * 64);
	mlx_image_to_window(game->window, game->floor_img, x * 64, y * 64);
	game->map[y][x - 1] = PLAYER;
	game->map[y][x] = FLOOR;
	game->movements += 1;
	ft_printf("Movement number: %i\n", game->movements);
}

void	move_player_s(t_game *game, int y, int x)
{
	end_checker(game, y + 1, x);
	if(game->map[y + 1][x] == END && game->collectives != 0)
		return;
	mlx_image_to_window(game->window, game->player_img, x * 64, (y + 1) * 64);
	mlx_image_to_window(game->window, game->floor_img, x * 64, y * 64);
	game->map[y + 1][x] = PLAYER;
	game->map[y][x] = FLOOR;
	game->movements += 1;
	ft_printf("Movement number: %i\n", game->movements);
}

void	move_player_d(t_game *game, int y, int x)
{
	end_checker(game, y, x + 1);
	if(game->map[y][x + 1] == END && game->collectives != 0)
		return;
	mlx_image_to_window(game->window, game->player_img, (x + 1) * 64, y * 64);
	mlx_image_to_window(game->window, game->floor_img, x * 64, y * 64);
	game->map[y][x + 1] = PLAYER;
	game->map[y][x] = FLOOR;
	game->movements += 1;
	ft_printf("Movement number: %i\n", game->movements);
}
