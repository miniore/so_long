/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:05:27 by miniore           #+#    #+#             */
/*   Updated: 2025/01/13 20:35:42 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_limits(char **map)
{
	int	column_size;
	int	row_size;
	int	i;
	int	j;

	row_size = ft_strlen(map[0]);
	column_size = 0;
	while (map[column_size])
		column_size++;
	j = 0;
	while (j < row_size - 1)
	{
		if (map[0][j] != 49 || map[column_size - 1][j] != 49)
			ft_perror("Map limits error.");
		j++;
	}
	i = 1;
	while (i < column_size)
	{
		if (map[i][0] != 49 || map[i][row_size - 2] != 49)
			ft_perror("Map limits error.");
		i++;
	}
}

static void	count_elements(char c)
{
	static int	player_count;
	static int	end_final;

	if (c == 80)
		player_count++;
	if (c == 69)
		end_final++;
	if (player_count > 1 || end_final > 1)
		ft_perror("Too many player or end elements.");
}

void	check_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] != 49 && game->map[i][j] != 48 && game->map[i][j] != 80 && game->map[i][j] != 67 && game->map[i][j] != 69)
				ft_perror("Elements error.");
			if (game->map[i][j] == COLLECT)
				game->collectives += 1;
			count_elements(game->map[i][j]);
			j++;
		}
		i++;
	}
	if (game->collectives < 1)
	 	ft_perror("Invalid number of collectibles.");
}

static void    check_size(char **map)
{
    int	line_len;
	int		i;
	int		j;
	int len;

	i = 0;
	len = 0;
	line_len = ft_strlen(map[i]) - 1;
	while (map[++i])
	{
		j = 0;
		while(map[i][j] && map[i][j] != '\n')
		{
			len++;
			j++;
		}
		if (line_len != len)
			ft_perror("Size map error.");
		len = 0;
	}
	if ((i < 3 || line_len < 3) || (i == 3 && line_len < 5) || (line_len == 3 && i < 5))
		ft_perror("Size map error.");
}

void	check_map(t_game *game)
{	
	check_size(game->map);
	check_elements(game);
	check_limits(game->map);
	check_valid_journey(game->map, game->collectives);
}
