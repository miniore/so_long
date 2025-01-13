/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:19:02 by porellan          #+#    #+#             */
/*   Updated: 2025/01/13 20:33:34 by porellan         ###   ########.fr       */
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
	mlx_image_t	*floor_img;
	mlx_image_t	*wall_img;
	mlx_image_t	*player_img;
	mlx_image_t	*collect_img;
	mlx_image_t	*end_img;
}	t_game;

void	ft_perror(char *error_message);
char	**read_map(char *file);
void	check_map(t_game *game);
void	check_valid_journey(char **map, int collect);
void	create_textures(t_game *game);
int		load_images(t_game *game);

#endif