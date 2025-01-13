/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:29:45 by porellan          #+#    #+#             */
/*   Updated: 2025/01/13 20:38:59 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "so_long.h"

int	check_end(char **map)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == END && ((map[i][j + 1] == PLAYER || map[i][j - 1] == PLAYER) 
				|| (map[i + 1][j] == PLAYER || map[i - 1][j] == PLAYER)))
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

int	write_in_map(char **map, int i, int j, int *collect)
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

char	**map_dup(char **map)
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

void	check_valid_journey(char **map, int collect)
{
	char	**map_copy;
	int	end_found;
	int	moving;
	int	i;
	int	j;

	map_copy = map_dup(map);
	moving = 1;
	end_found = 0;
	while ((collect != 0 && end_found != 1) && moving == 1)
	{
		i = 1;
		moving = 0;
		while (map_copy[i + 1])
		{
			j = 1;
			while (map_copy[i][j + 1])
			{
				if (write_in_map(map_copy, i, j, &collect))
					moving = 1;
				j++;
			}
			i++;
		}
	}
	end_found = check_end(map_copy);				
	if (moving == 1 && (!collect && end_found == 1))
		ft_printf("Valid journey");
	else
	{
		free(map_copy);
		ft_perror("Invalid journey");
	}
}
