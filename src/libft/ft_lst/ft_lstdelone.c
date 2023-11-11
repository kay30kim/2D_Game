/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:33:53 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/26 15:33:30 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!del || !lst)
		return ;
	del(lst->content);
	free(lst);
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
	printf("aa\n");
	printf("%s -> \n", (char *)content);
	content = 0;
	printf("%s -> \n\n", (char *)content);
}

int	main(void)
{
	t_list	*list1;

	list1 = ft_lstnew("Item 1");
	list1->next = ft_lstnew("Item 2");
	printf("Original List 1: ");
	ft_lstprint(list1);
	
	printf("Deleting List 1: ");
	ft_lstdelone(list1, delete_string_node);
	printf("List 1 deleted\n\n");

	ft_lstprint(list1);
	return (0);
}*/
