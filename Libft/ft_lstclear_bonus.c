/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: porellan <porellan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 19:20:00 by porellan          #+#    #+#             */
/*   Updated: 2023/10/16 19:05:13 by porellan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*backup;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		backup = (*lst)->next;
		del((*lst)->content);
		free((*lst));
		(*lst) = backup;
	}
	(*lst) = 0;
}
