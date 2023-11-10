/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:33:14 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/26 15:17:28 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new && lst)
	{
		new->next = *lst;
		*lst = new;
	}
}
/*
void	ft_lstprint(t_list *list)
{
	while (list)
	{
		printf("%s -> ", (char *)list->content);
		list = list->next;
	}
	printf("NULL\n");
}

int	main(void)
{
	t_list	*list1;
	t_list	*newNode;

	list1 = ft_lstnew("Item 1");
	list1->next = ft_lstnew("Item 2");
	printf("Original List 1: ");
	ft_lstprint(list1);

	newNode = ft_lstnew("New Item");
	ft_lstadd_front(&list1, newNode);
	ft_lstprint(list1);
	return (0);
}*/
