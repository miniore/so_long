/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:14:32 by porellan          #+#    #+#             */
/*   Updated: 2024/11/26 22:05:57 by miniore          ###   ########.fr       */
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

void	move_player(t_game *game, int y, int x, keys_t key)
{
	//static int	i;

	if (key == MLX_KEY_W && game->map[y - 1][x] != 1)
	{
		game->player_img->instances[0].y -= 10;
		// i++;
		// ft_printf("Movement number: %i\n", i);
	}
	if (key == MLX_KEY_A && game->map[y][x - 1] != 1)
	{
		game->player_img->instances[0].x -= 10;
		// i++;
		// ft_printf("Movement number: %i\n", i);
	}
	if (key == MLX_KEY_S && game->map[y + 1][x] != 1)
	{
		game->player_img->instances[0].y += 10;
		// i++;
		// ft_printf("Movement number: %i\n", i);
	}
	if (key == MLX_KEY_D && game->map[y][x + 1] != 1)
	{
		game->player_img->instances[0].x += 10;
		// i++;
		// ft_printf("Movement number: %i\n", i);
	}
}

void	press_key(t_game *game, keys_t key)
{
	int	y;
	int	x;
	int	found;

	y = 0;
	found = 0;
	while(!found && game->map[y++])
	{
		x = 0;
		while(game->map[y][x])
		{
			x++;
			if(game->map[y][x] == 'P')
					found = 1;
		}
	}
	if(found == 1)
		move_player(game, y, x, key);
}

void my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game *game;
	static int	i;

	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		press_key(game, keydata.key);
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		press_key(game, keydata.key);
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		press_key(game, keydata.key);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		press_key(game, keydata.key);
	i += 1;
	ft_printf("Movement number: %i\n", i);
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