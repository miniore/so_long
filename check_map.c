/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 19:05:27 by miniore           #+#    #+#             */
/*   Updated: 2024/11/18 21:31:11 by miniore          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_map(char **map)
{
	check_size(map);
	check_elements(map);
	check_limits(map);
}

static void	check_limits(char **map)
{
	int	column_size;
	int	row_size;
	int	i;
	int	j;

	row_size = ft_strlen(map[0]);
	while (map[column_size])
		column_size++;
	j = 0;
	while (j < row_size - 1)
	{
		if (map[0][j] != '1' || map[column_size - 1][j] != '1')
			ft_printf("Limits error");
		j++;
	}
	i = 1;
	while (i < column_size - 1)
	{
		if (map[i][0] != '1' || map[i][row_size - 1] != '1')
			ft_printf("Limits error");
		i++;
	}
}

static void	count_elements(char c)
{
	static int	player_count;
	static int	end_final;

	if (player_count > 1 || end_final > 1)
		ft_printf("Too many player or end elements");
}

static void	check_elements(char **map)
{
	int	i;
	int	j;
	int	collective_count;

	i = 0;
	while (map)
	{
		j = 0;
		while (map[i][j] != '\n')
		{
			if (map[i][j] != '1' || map[i][j] != '0' || map[i][j] != 'P' || map[i][j] != 'C' || map[i][j] != 'E')
				ft_printf("Elements error");
			if (map[i][j] == 'C')
				collective_count++;
			count_elements(map[i][j]);
			j++;
		}
		i++;
	}
	if (collective_count < 1)
		ft_printf("Invalid number of collectibles");
}

static void    check_size(char **map)
{
    size_t	line_len;
	int		i;

	i = 0;
	line_len = ft_strlen(map[i]); 
	while (map)
	{
		if (line_len != ft_strlen(map[i]))
			ft_printf("Size map error");
		if ((i < 3 || line_len < 3) || (i == 3 && line_len < 5) || (line_len == 3 && i < 5))
		{
			//ft_free_array(map);
			ft_printf("Size map error");
		}
		i++;
	}
}
