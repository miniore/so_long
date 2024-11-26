/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:14:32 by porellan          #+#    #+#             */
/*   Updated: 2024/11/26 19:44:52 by porellan         ###   ########.fr       */
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

void	press_key(t_game *game)
{
	int	i;

	i = 0;
	
	ft_printf("Movement number: %i\n");
}

void	repeat_key(t_game *game)
{
	int	i;

	i = 0;
	ft_printf("Movement number: %i\n");
}

void my_keyhook(mlx_key_data_t keydata, void *param)
{
	t_game *game;

	game = param;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
		press_key(game);
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_REPEAT)
		puts("!");
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
		puts("Hello ");
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_REPEAT)
		puts("e");
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
		puts("Hello ");
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_REPEAT)
		puts("h");
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
		puts("Hello ");
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_REPEAT)
		puts("ñ");
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