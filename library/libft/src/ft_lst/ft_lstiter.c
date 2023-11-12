/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:34:31 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/26 15:15:30 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	while (lst && f)
	{
		f(lst->content);
		lst = lst->next;
	}
}
/*
void print_node(void *content) {
    printf("%s -> ", (char *)content);
}

int main() {
    // Test case: Non-null input with multiple elements
    t_list *list1 = ft_lstnew("Item 1");
    list1->next = ft_lstnew("Item 2");
    list1->next->next = ft_lstnew("Item 3");
    printf("Original List 1: ");
    ft_lstprint(list1); // Assuming you have a function to print the list

    printf("List 1 after applying ft_lstiter: ");
    ft_lstiter(list1, print_node);
    printf("NULL\n");

    return 0;
}*/
