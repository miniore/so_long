/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 18:44:36 by porellan          #+#    #+#             */
/*   Updated: 2025/01/23 12:02:56 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	put_img(t_game *game, mlx_image_t *img, int x, int y)
{
	if (mlx_image_to_window(game->wndw, img, x * 64, y * 64) < 0)
		ft_perror(game, "Image error.\n");
}

void	load_images(t_game *game)
{
	int	x;
	int	y;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == WALL)
				put_img(game, game->wall_img, x, y);
			if (game->map[y][x] == FLOOR || game->map[y][x] == PLAYER
				|| game->map[y][x] == COLLECT)
				put_img(game, game->floor_img, x, y);
			if (game->map[y][x] == PLAYER)
				put_img(game, game->player_img, x, y);
			if (game->map[y][x] == COLLECT)
				put_img(game, game->collect_img, x, y);
			if (game->map[y][x] == END)
				put_img(game, game->end_img, x, y);
			x++;
		}
		y++;
	}
}

static mlx_image_t	*textures_to_img(t_game *game, char *route)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(route);
	if (!texture)
		ft_perror(game, "Load image error.\n");
	img = mlx_texture_to_image(game->wndw, texture);
	if (!img)
		ft_perror(game, "Load image error.\n");
	mlx_delete_texture(texture);
	return (img);
}

void	create_textures(t_game *game)
{
	game->floor_img = textures_to_img(game, "./textures/floor.png");
	game->wall_img = textures_to_img(game, "./textures/wall.png");
	game->player_img = textures_to_img(game, "./textures/player.png");
	game->collect_img = textures_to_img(game, "./textures/collect.png");
	game->end_img = textures_to_img(game, "./textures/end.png");
}
