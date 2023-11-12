/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:34:48 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/26 15:15:37 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	while (lst && lst->next)
		lst = lst->next;
	return (lst);
}
/*
int	main(void)
{
	t_list	*list1;
	t_list	*last1;
	t_list	*list2;
	t_list	*last2;
	t_list	*list3;
	t_list	*last3;

	// Test case 1: Non-null input with multiple elements
	list1 = ft_lstnew("Item 1");
	list1->next = ft_lstnew("Item 2");
	list1->next->next = ft_lstnew("Item 3");
	printf("List 1: ");
	ft_lstprint(list1); // Assuming you have a function to print the list
	last1 = ft_lstlast(list1);
	printf("Last element in List 1: %s\n\n", (char *)last1->content);
	// Test case 2: Null input
	list2 = NULL;
	printf("List 2: NULL\n");
	last2 = ft_lstlast(list2);
	if (last2 == NULL)
	{
		printf("Last element in List 2: NULL\n\n");
	}
	// Test case 3: Non-null input with a single element
	list3 = ft_lstnew("Item A");
	printf("List 3: Item A\n");
	last3 = ft_lstlast(list3);
	printf("Last element in List 3: %s\n\n", (char *)last3->content);
	return (0);
}*/
