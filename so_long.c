/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:14:32 by porellan          #+#    #+#             */
/*   Updated: 2024/11/25 19:32:26 by porellan         ###   ########.fr       */
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

void	put_img(t_game *game, mlx_image_t *img, int x, int y)
{
	if (!(mlx_image_to_window(game->window, img, x * 64, y * 64)))
		ft_printf("Error\n");
}

int	load_images(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (game->map[x])
	{
		y = 0;
		while (game->map[x][y])
		{
			if (game->map[x][y] == FLOOR)
				put_img(game, game->floor_img, x, y);
			// if (game->map[x][y] == WALL)
			// 	put_img(game, game->wall_img, x, y);
			// if (game->map[x][y] == PLAYER)
			// 	put_img(game, game->player_img, x, y);
			// if (game->map[x][y] == COLLECT)
			// 	put_img(game, game->collect_img, x, y);
			// if (game->map[x][y] == END)
			// 	put_img(game, game->end_img, x, y);
		}
	}
	return (EXIT_SUCCESS);
}

mlx_image_t	*textures_to_img(t_game *game, char *route)
{
	mlx_texture_t	*texture;
	mlx_image_t		*img;

	texture = mlx_load_png(route);
	if (!texture)
        ft_printf("Error\n");
	img = mlx_texture_to_image(game->window, texture);
	return (img);
}

void	create_textures(t_game *game)
{
	game->floor_img = textures_to_img(game, "textures/floor.png");
	// game->wall_img = textures_to_img(game, "textures/");
	// game->player_img = textures_to_img(game, "textures/");
	// game->collect_img = textures_to_img(game, "textures/");
	// game->end_img = textures_to_img(game, "textures/");
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
	//mlx_loop_hook(mlx, ft_hook, mlx);
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