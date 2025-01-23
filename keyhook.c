/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 20:51:19 by miniore           #+#    #+#             */
/*   Updated: 2025/01/23 11:50:05 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	press_key(t_game *game, keys_t key)
{
	int	y;
	int	x;
	int	found;

	y = 0;
	found = 0;
	while (!found && y++ < game->height)
	{
		x = 0;
		while (!found && x++ < game->width)
		{
			if (game->map[y][x] == PLAYER)
				found = 1;
		}
	}
	if (found == 1 && (game->map[y - 1][x] != WALL && key == MLX_KEY_W))
		move_player_w(game, y, x);
	if (found == 1 && (game->map[y][x - 1] != WALL && key == MLX_KEY_A))
		move_player_a(game, y, x);
	if (found == 1 && (game->map[y + 1][x] != WALL && key == MLX_KEY_S))
		move_player_s(game, y, x);
	if (found == 1 && (game->map[y][x + 1] != WALL && key == MLX_KEY_D))
		move_player_d(game, y, x);
}

void	my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game	*game;

	game = (t_game *)param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		press_key(game, keydata.key);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		press_key(game, keydata.key);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		press_key(game, keydata.key);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		press_key(game, keydata.key);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
		end_game(game);
}
