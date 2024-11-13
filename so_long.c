/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:14:32 by porellan          #+#    #+#             */
/*   Updated: 2024/11/12 19:31:51 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    read_map(char)
{
    
}

char **check_map(char *map)
{
    int len;

    len = ft_strlen(map);
    if (!ft_strnstr(map, ".ber", len))
        exit(1);
}

int main(char **argv, int argc)
{
    char **map;
    
    if (argc != 2)
        exit(1);
    check_map(argv);
    
}
