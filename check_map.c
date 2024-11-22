/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:05:27 by miniore           #+#    #+#             */
/*   Updated: 2024/11/20 18:04:51 by porellan         ###   ########.fr       */
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
			ft_printf("Limits error 1\n");
		j++;
	}
	i = 1;
	while (i < column_size)
	{
		if (map[i][0] != 49 || map[i][row_size - 2] != 49)
			ft_printf("Limits error 2\n");
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
		ft_printf("Too many player or end elements");
}

static int	check_elements(char **map)
{
	int	i;
	int	j;
	int	collective_count;

	i = 0;
	collective_count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] && map[i][j] != '\n')
		{
			if (map[i][j] != 49 && map[i][j] != 48 && map[i][j] != 80 && map[i][j] != 67 && map[i][j] != 69)
				ft_printf("Elements error");
			if (map[i][j] == COLLECT)
				collective_count++;
			count_elements(map[i][j]);
			j++;
		}
		i++;
	}
	if (collective_count < 1)
		ft_printf("Invalid number of collectibles");
	return(collective_count);
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
			ft_printf("Size map error 1\n");
		len = 0;
	}
	if ((i < 3 || line_len < 3) || (i == 3 && line_len < 5) || (line_len == 3 && i < 5))
	{
		//ft_free_array(map);
		ft_printf("Size map error 2\n");
	}
}

void	check_map(char **map)
{
	int	collective_count;
	
	check_size(map);
	collective_count = check_elements(map);
	check_limits(map);
	check_valid_journey(map, collective_count);
}