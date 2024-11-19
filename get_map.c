/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: miniore <miniore@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 21:30:00 by miniore           #+#    #+#             */
/*   Updated: 2024/11/18 21:30:45 by miniore          ###   ########.fr       */
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
	}
	return (map);
}

char	**read_map(char *file)
{
    int	fd;
	t_list	*lines;
	t_list	*temp;
	char	**map;
	char	*map_lines;

	lines = NULL;
	fd = open(file, O_RDONLY);
	if (fd == -1)
		exit(1);
	while (1)
	{
		map_lines = get_next_line(fd);
		ft_printf("%s", map_lines);
		temp = ft_lstnew(map_lines);
		ft_lstadd_back(lines, temp);
	}
	map = copy_map(lines);
	ft_lstclear(&lines, free);
	close(fd);
	return (map);
}
