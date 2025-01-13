/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:14:32 by porellan          #+#    #+#             */
/*   Updated: 2025/01/13 21:06:58 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_perror(char *error_message)
{
	ft_printf("%s\n", error_message);
	exit(1);
}

void	check_file(char *file)
{
	int len;

	len = ft_strlen(file);
    if (!ft_strnstr(file, ".ber", len))
        ft_perror("File error");
}

void	calculate_size(t_game *game)
{
	int	i;

	i = 0;
	game->width = ft_strlen(game->map[0]) - 1;
	while (game->map[i++])
		game->height = i;
}

void	end_checker(t_game *game, int y, int x)
{	
	if(game->map[y][x] == COLLECT)
		game->collectives -= 1;
	if(game->collectives == 0 && game->map[y][x] == END)
		exit(1);
}


void	move_player(t_game *game, int y, int x, keys_t key)
{
	static int	i;
	if (game->map[y - 1][x] != WALL && key == MLX_KEY_W)
	{
		end_checker(game, y - 1, x);
		mlx_image_to_window(game->window, game->player_img, x * 64, (y - 1) * 64);
		mlx_image_to_window(game->window, game->floor_img, x * 64, y * 64);
		game->map[y][x] = FLOOR;
		game->map[y - 1][x] = PLAYER;
		i++;
		ft_printf("Movement number: %i\n", i);
	}
	if (game->map[y][x - 1] != WALL && key == MLX_KEY_A)
	{
		end_checker(game, y, x - 1);
		mlx_image_to_window(game->window, game->player_img, (x - 1) * 64, y * 64);
		mlx_image_to_window(game->window, game->floor_img, x * 64, y * 64);
		game->map[y][x] = FLOOR;
		game->map[y][x - 1] = PLAYER;
		i++;
		ft_printf("Movement number: %i\n", i);
	}
	if (game->map[y + 1][x] != WALL && key == MLX_KEY_S)
	{
		end_checker(game, y + 1, x);
		mlx_image_to_window(game->window, game->player_img, x * 64, (y + 1) * 64);
		mlx_image_to_window(game->window, game->floor_img, x * 64, y * 64);
		game->map[y][x] = FLOOR;
		game->map[y + 1][x] = PLAYER;
		i++;
		ft_printf("Movement number: %i\n", i);
	}
	if (game->map[y][x + 1] != WALL && key == MLX_KEY_D)
	{
		end_checker(game, y, x + 1);
		mlx_image_to_window(game->window, game->player_img, (x + 1) * 64, y * 64);
		mlx_image_to_window(game->window, game->floor_img, x * 64, y * 64);
		game->map[y][x] = FLOOR;
		game->map[y][x + 1] = PLAYER;
		i++;
		ft_printf("Movement number: %i\n", i);
	}
}

void	press_key(t_game *game, keys_t key)
{
	int	y;
	int	x;
	int	found;

	y = 0;
	found = 0;
	while(!found && y++ < game->height)
	{
		x = 0;
		while(!found && x++ < game->width)
		{
			if(game->map[y][x] == PLAYER)
				found = 1;
		}
	}
	if(found == 1 && key == MLX_KEY_W)     //Aqui me quede. Configurar las cuatro teclas de esta manera a ver si reducen lineas.
		move_player(game, y, x, key);      //Ajustar funciones en archivos. Cambio de imagen al cojer moneda y final. Frees y leaks.
}

void my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = (t_game *)param;
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
	check_map(game);
	calculate_size(game);
	game->window = mlx_init(game->width * 64, game->height * 64, "Game42", false);
	if (!game->window)
		ft_perror("Window error");
	create_textures(game);
	load_images(game);
	mlx_key_hook(game->window, my_keyhook, game);
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