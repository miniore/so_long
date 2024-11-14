/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:14:32 by porellan          #+#    #+#             */
/*   Updated: 2024/11/14 13:34:04 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**read_map(char *map)
{
    int	fd;
	int	lines;

	lines = 3;
	fd = open(map, O_RDONLY);
	if (fd == -1)
		exit(1);
	while (lines)
	{
		map = get_next_line(fd);
		ft_printf("%s", map);
		lines--;
	}
	return (0);
}

void	check_file(char *map)
{
	int len;

	len = ft_strlen(map);
    if (!ft_strnstr(map, ".ber", len))
        exit(1);
}

int main(int argc, char **argv)
{    
    //char	**map;
	
	if (argc != 2)
        exit(1);
    check_file(argv[1]);
	read_map(argv[1]);
	return (0);
}
