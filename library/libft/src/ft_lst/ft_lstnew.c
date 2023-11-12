/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:36:30 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/26 15:46:19 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*tmp;

	tmp = (t_list *)malloc(sizeof(t_list));
	if (!tmp)
		return (NULL);
	tmp->content = content;
	tmp->next = 0;
	return (tmp);
}
/*
int main() {
    // Test case 1: Non-null input
    char *item1 = "Item 1";
    t_list *list1 = ft_lstnew(item1);
    printf("List 1: %s\n", (char *)list1->content);

    // Test case 2: Null input
    t_list *list2 = ft_lstnew(NULL);
    printf("List 2: %s\n", (char *)list2->content);

    // Test case 3: Non-null input
    char *item3 = "Item A";
    t_list *list3 = ft_lstnew(item3);
    printf("List 3: %s\n", (char *)list3->content);

    return 0;
}*/
