/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:05:27 by miniore           #+#    #+#             */
/*   Updated: 2025/01/23 12:17:33 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_limits(t_game *game)
{
	int	column_size;
	int	row_size;
	int	i;
	int	j;

	row_size = ft_strlen(game->map[0]);
	column_size = 0;
	while (game->map[column_size])
		column_size++;
	j = 0;
	while (j < row_size - 1)
	{
		if (game->map[0][j] != 49 || game->map[column_size - 1][j] != 49)
			ft_perror(game, "Map limits error.\n");
		j++;
	}
	i = 1;
	while (i < column_size)
	{
		if (game->map[i][0] != 49 || game->map[i][row_size - 2] != 49)
			ft_perror(game, "Map limits error.\n");
		i++;
	}
}

static int	count_elements(char c)
{
	static int	player_count;
	static int	end_final;

	if (c == 80)
		player_count++;
	if (c == 69)
		end_final++;
	if (player_count > 1 || end_final > 1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

static void	check_elements(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			if (game->map[i][j] != 49
				&& game->map[i][j] != 48 && game->map[i][j]
				!= 80 && game->map[i][j] != 67 && game->map[i][j] != 69)
				ft_perror(game, "Elements error.\n");
			if (game->map[i][j] == COLLECT)
				game->collectives += 1;
			if (count_elements(game->map[i][j]))
				ft_perror(game, "Too many player or end elements.\n");
			j++;
		}
		i++;
	}
	if (game->collectives < 1)
		ft_perror(game, "Invalid number of collectibles.\n");
}

static void	check_size(t_game *game)
{
	int		line_len;
	int		i;
	int		j;
	int		len;

	i = 0;
	len = 0;
	line_len = ft_strlen(game->map[i]) - 1;
	while (game->map[++i])
	{
		j = 0;
		while (game->map[i][j] && game->map[i][j] != '\n')
		{
			len++;
			j++;
		}
		if (line_len != len)
			ft_perror(game, "Size map error.\n");
		len = 0;
	}
	if ((i < 3 || line_len < 3) || (i == 3 && line_len < 5)
		|| (line_len == 3 && i < 5))
		ft_perror(game, "Size map error.\n");
}

void	check_map(t_game *game)
{
	check_size(game);
	check_elements(game);
	check_limits(game);
	check_valid_path(game);
}
