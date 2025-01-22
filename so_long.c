/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:14:32 by porellan          #+#    #+#             */
/*   Updated: 2025/01/22 18:46:39 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_file(char *file)
{
	size_t	len;

	len = ft_strlen(file);
	if (len <= 4)
	{
		ft_putstr_fd("File error.\n", 2);
		exit(EXIT_FAILURE);
	}
	len -= 4;
	if (ft_strncmp(&file[len], ".ber", 4))
	{
		ft_putstr_fd("File error.\n", 2);
		exit(EXIT_FAILURE);
	}
}

static void	calculate_size(t_game *game)
{
	int	i;

	i = 0;
	game->width = ft_strlen(game->map[0]) - 1;
	while (game->map[i++])
		game->height = i;
}

int main(int argc, char **argv)
{
    t_game	*game;

	if (argc != 2)
	{
        ft_putstr_fd("Arguments error.\n", 2);
		exit(EXIT_FAILURE);
	}
	check_file(argv[1]);
	game = (t_game *)ft_calloc(1, sizeof(t_game));
	if(!game)
		return(EXIT_FAILURE);
	game->map = read_map(game, argv[1]);
	check_map(game);
	calculate_size(game);
	game->window = mlx_init(game->width * 64, game->height * 64, "Game42", false);
	if (!game->window)
		ft_perror(game, "Window error.\n");
	create_textures(game);
	load_images(game);
	mlx_key_hook(game->window, my_keyhook, game);
	mlx_loop(game->window);
	end_game(game);
	return (EXIT_SUCCESS);
}

	// while (1)
	// {
	// 	if (!game->map[i])
	// 		break;
	// 	ft_printf("%s", game->map[i]);
	// 	i++;
	// }