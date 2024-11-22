/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 18:19:02 by porellan          #+#    #+#             */
/*   Updated: 2024/11/20 17:54:10 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "Libft/libft.h"
# include "Libft/Printf/ft_printf.h"

#define PLAYER 'P'
#define END 'E'
#define COLLECT 'C'
#define FLOOR '0'
#define WALL '1'

char	**read_map(char *file);
void	check_map(char **map);
void	check_valid_journey(char **map, int collect);

#endif