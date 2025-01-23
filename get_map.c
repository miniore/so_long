/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:30:00 by miniore           #+#    #+#             */
/*   Updated: 2025/01/23 11:49:20 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**copy_map(t_list *lines)
{
	size_t	len;
	char	**map;
	int		i;
	char	*map_line;

	if (!lines)
		return (0);
	i = 0;
	len = ft_lstsize(lines);
	map = (char **)ft_calloc(len + 1, sizeof(char *));
	if (!map)
		return (0);
	while (lines)
	{
		map_line = lines->content;
		map[i] = ft_strdup(map_line);
		lines = lines->next;
		i++;
	}
	return (map);
}

char	**read_map(t_game *game, char *file)
{
	int		fd;
	t_list	*lines;
	t_list	*temp;
	char	**map;
	char	*map_lines;

	lines = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(game);
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		map_lines = get_next_line(fd);
		if (!map_lines)
			break ;
		temp = ft_lstnew(map_lines);
		ft_lstadd_back(&lines, temp);
	}
	map = copy_map(lines);
	ft_lstclear(&lines, free);
	close(fd);
	return (map);
}
