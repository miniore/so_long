/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:14:32 by porellan          #+#    #+#             */
/*   Updated: 2024/11/22 16:59:37 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	int k = 0;

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
	while (map_copy[k])
	{
		ft_printf("%s", map_copy[k]);
		k++;
	}
	end_found = check_end(map_copy);				
	if (moving == 1 && (!collect && end_found == 1))
		ft_printf("Journey success");
	else
		ft_printf("Journey failed");
	free(map_copy);
}

void	check_file(char *file)
{
	int len;

	len = ft_strlen(file);
    if (!ft_strnstr(file, ".ber", len))
        exit(1);
}

int main(int argc, char **argv)
{    
    //t_game	game;
	char	**map;
	int i = 0;
	
	if (argc != 2)
        exit(1);
    check_file(argv[1]);
	map = read_map(argv[1]);
	while (1)
	{
		if (!map[i])
			break;
		ft_printf("%s", map[i]);
		i++;
	}
	check_map(map);
	return (0);
}
