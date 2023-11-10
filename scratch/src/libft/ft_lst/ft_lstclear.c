/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:33:31 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/28 14:29:59 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*head;

	if (!lst || !del)
		return ;
	head = *lst;
	while (head)
	{
		tmp = head;
		head = head->next;
		ft_lstdelone(tmp, del);
	}
	*lst = 0;
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

void	print_node(void *content)
{
	printf("%s -> ", (char *)content);
}

void	delete_string_node(void *content)
{
	content = 0;
}

int	main(void)
{
	t_list	*list1;

	list1 = ft_lstnew("Item 1");
	list1->next = ft_lstnew("Item 2");
	list1->next->next = ft_lstnew("Item 3");
	printf("Original List 1: ");
	ft_lstprint(list1);

	printf("Clearing List 1: ");
	ft_lstclear(&list1, delete_string_node);
	printf("List 1 cleared\n");

	if (list1 == NULL)
	{
		printf("List 1 is now NULL\n");
	}
	ft_lstprint(list1);
	return (0);
}*/
