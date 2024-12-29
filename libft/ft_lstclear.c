/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lasablon <lasablon@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:00:11 by lasablon          #+#    #+#             */
/*   Updated: 2024/05/30 17:27:31 by lasablon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*buff;

	while (*lst != NULL && del != NULL)
	{
		del((*lst)->content);
		buff = (*lst)->next;
		free(*lst);
		(*lst) = buff;
	}
	*lst = NULL;
}
