/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:36:48 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/26 15:32:55 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}
/*
int main() {
    // Test case 1: Non-null input
    t_list *list1 = ft_lstnew("Item 1");
    list1->next = ft_lstnew("Item 2");
    list1->next->next = ft_lstnew("Item 3");
    printf("List 1: ");
    ft_lstprint(list1); // Assuming you have a function to print the list

    int size1 = ft_lstsize(list1);
    printf("Size of List 1: %d\n\n", size1);

    // Test case 2: Null input
    t_list *list2 = NULL;
    printf("List 2: NULL\n");

    int size2 = ft_lstsize(list2);
    printf("Size of List 2: %d\n\n", size2);

    // Test case 3: Mix of non-null and null input
    t_list *list3 = ft_lstnew("Item A");
    list3->next = NULL;
    printf("List 3: Item A -> NULL\n");

    int size3 = ft_lstsize(list3);
    printf("Size of List 3: %d\n\n", size3);

    return 0;
}*/
