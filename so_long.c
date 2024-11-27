/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:14:32 by porellan          #+#    #+#             */
/*   Updated: 2024/11/27 13:24:13 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_file(char *file)
{
	int len;

	len = ft_strlen(file);
    if (!ft_strnstr(file, ".ber", len))
        exit(1);
}

void	calculate_size(t_game *game)
{
	int	i;

	i = 0;
	game->width = ft_strlen(game->map[0]) - 1;
	while (game->map[i++])
		game->height = i;
}

// void	ft_hook(void *data)    //Usar para los movimientos??
// {
// 	t_game * game;

// 	game = (t_game *)data;
// 	create_textures(game);
// 	load_images(game);

// }

void	move_player(t_game *game, int x, int y, keys_t key)
{
	static int	i;
	int j = 0;
	
	while (1)
	{
		if (!game->map[j])
			break;
		ft_printf("%s", game->map[j]);
		j++;
	}
	if (game->map[y][x - 1] != WALL && key == MLX_KEY_W)
	{
		mlx_image_to_window(game->window, game->player_img, y * 64, (x - 1) * 64);
		mlx_image_to_window(game->window, game->floor_img, y * 64, x * 64);
		game->map[x][y] = FLOOR;
		game->map[x][y - 1] = PLAYER;
		i++;
		ft_printf("Movement number: %i\n", i);
	}
	if (game->map[x - 1][y] != WALL && key == MLX_KEY_A)
	{
		mlx_image_to_window(game->window, game->player_img, (y - 1) * 64, x * 64);
		mlx_image_to_window(game->window, game->floor_img, y * 64, x * 64);
		game->map[x][y] = FLOOR;
		game->map[x - 1][y] = PLAYER;
		i++;
		ft_printf("Movement number: %i\n", i);
	}
	if (game->map[x][y + 1] != WALL && key == MLX_KEY_S)
	{
		mlx_image_to_window(game->window, game->player_img, y * 64, (x + 1) * 64);
		mlx_image_to_window(game->window, game->floor_img, y * 64, x * 64);
		game->map[x][y] = FLOOR;
		game->map[x][y + 1] = PLAYER;
		i++;
		ft_printf("Movement number: %i\n", i);
	}
	if (game->map[x + 1][y] != WALL && key == MLX_KEY_D)
	{
		mlx_image_to_window(game->window, game->player_img, (y + 1) * 64, x * 64);
		mlx_image_to_window(game->window, game->floor_img, y * 64, x * 64);
		game->map[x][y] = FLOOR;
		game->map[x + 1][y] = PLAYER;
		//game->player_img->instances[0].x += 64;
		i++;
		ft_printf("Movement number: %i\n", i);
	}
}

void	press_key(t_game *game, keys_t key)
{
	int	y;
	int	x;
	int	found;

	x = 0;
	found = 0;
	while(!found && game->map[x++])
	{
		y = 0;
		while(!found && game->map[x][y])
		{
			y++;
			if(game->map[x][y] == PLAYER)
					found = 1;
		}
	}
	ft_printf("y: %i x: %i\n", y, x);
	if(found == 1)
		move_player(game, x, y, key);
}

void my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		press_key(game, keydata.key);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		press_key(game, keydata.key);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		press_key(game, keydata.key);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		press_key(game, keydata.key);
}

int main(int argc, char **argv)
{
    t_game	*game  = NULL;

	if (argc != 2)
        exit(1);
	check_file(argv[1]);
	game = (t_game *)ft_calloc(1, sizeof(t_game));
	game->map = read_map(argv[1]);
	check_map(game->map);
	calculate_size(game);
	game->window = mlx_init(game->width * 64, game->height * 64, "Game42", false);
	if (!game->window)
		return(1);   //Poner funcion errores personalizada
	create_textures(game);
	load_images(game);
	mlx_key_hook(game->window, my_keyhook, game);
	//mlx_loop_hook(game->window, ft_hook, (void *)game);
	mlx_loop(game->window);
	mlx_terminate(game->window);
	return (0);
}

	// while (1)
	// {
	// 	if (!game->map[i])
	// 		break;
	// 	ft_printf("%s", game->map[i]);
	// 	i++;
	// }