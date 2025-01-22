/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:19:02 by porellan          #+#    #+#             */
/*   Updated: 2025/01/22 18:46:04 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "Libft/Printf/ft_printf.h"
# include <MLX42.h>

#define PLAYER 'P'
#define END 'E'
#define COLLECT 'C'
#define FLOOR '0'
#define WALL '1'

typedef struct game
{
	mlx_t		*window;
	int			width;
	int			height;
	char		**map;
	int			collectives;
	int			moving;
	int			movements;
	int			is_end;
	mlx_image_t	*floor_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*player_img;
	mlx_image_t	*collect_img;
	mlx_image_t	*end_img;
}	t_game;

void	ft_perror(t_game *game, char *error_message);
void	free_array(char **array);
char	**read_map(t_game *game, char *file);
void	check_map(t_game *game);
void	check_valid_journey(t_game *game);
void	create_textures(t_game *game);
void	load_images(t_game *game);
void	my_keyhook(mlx_key_data_t keydata, void *param);
void	move_player_w(t_game *game, int y, int x);
void	move_player_a(t_game *game, int y, int x);
void	move_player_s(t_game *game, int y, int x);
void	move_player_d(t_game *game, int y, int x);
void	end_game(t_game *game);

#endif