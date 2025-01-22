/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:29:45 by porellan          #+#    #+#             */
/*   Updated: 2025/01/21 15:57:14 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

static int	check_end(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == END && ((map[i][j + 1] == PLAYER
				|| map[i][j - 1] == PLAYER) || (map[i + 1][j] == PLAYER
				|| map[i - 1][j] == PLAYER)))
			{
				map[i][j] = PLAYER;
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

static int	write_in_map(char **map, int i, int j, int *collect)
{
	if (map[i][j] == FLOOR)
	{
		if (map[i][j + 1] == PLAYER || map[i][j - 1] == PLAYER)
			map[i][j] = PLAYER;
		else if (map[i + 1][j] == PLAYER || map[i - 1][j] == PLAYER)
			map[i][j] = PLAYER;
		if (map[i][j] == PLAYER)
			return (1);
	}
	else if (map[i][j] == COLLECT)
	{
		if (map[i][j + 1] == PLAYER || map[i][j - 1] == PLAYER)
			map[i][j] = PLAYER;
		else if (map[i + 1][j] == PLAYER || map[i - 1][j] == PLAYER)
			map[i][j] = PLAYER;
		if (map[i][j] == PLAYER)
		{
			(*collect)--;
			return (1);
		}
	}
	return (0);
}

static char	**map_dup(char **map)
{
	char	**dup_map;
	int		j;
	int		i;

	j = 0;
	while (map[j])
		j++;
	dup_map = (char **)ft_calloc(j + 1, sizeof(char *));
	if (!dup_map)
		return (NULL);
	i = 0;
	while (i < j)
	{
		dup_map[i] = ft_strdup(map[i]);
		i++;
	}
	return (dup_map);
}

static int	fun(t_game *game, char **map_copy, int collect)
{
	int	i;
	int	j;
	
	while ((collect != 0 && game->is_end != 1) && game->moving == 1)
	{
		i = 1;
		game->moving = 0;
		while (map_copy[i + 1])
		{
			j = 1;
			while (map_copy[i][j + 1])
			{
				if (write_in_map(map_copy, i, j, &collect))
					game->moving = 1;
				j++;
			}
			i++;
		}
	}
	return(collect);
}

void	check_valid_journey(t_game *game)
{
	char	**map_copy;
	int		collect;

	map_copy = map_dup(game->map);
	game->moving = 1;
	collect = fun(game, map_copy, game->collectives);
	game->is_end = check_end(map_copy);				
	if (game->moving == 1 && (!collect && game->is_end == 1))
		free_array(map_copy);
	else
	{
		free_array(map_copy);
		ft_perror(game, "Invalid journey.\n");
	}
}
