/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:32:57 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/28 14:25:45 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	if (*lst == NULL)
		*lst = new;
	else
	{
		ptr = *lst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->next = new;
	}
}
/*
int	main(void)
{
	t_list	*my_list;
	t_list	**list_ptr;
	t_list	*current;

	my_list = NULL;
	list_ptr = &my_list;
	printf("%p\n",*list_ptr);
	ft_lstadd_back(list_ptr, ft_lstnew("lore"));
	printf("%p\n",*list_ptr);
	ft_lstadd_back(list_ptr, ft_lstnew("lore2"));
	printf("%p\n",*list_ptr);
	ft_lstadd_back(list_ptr, ft_lstnew("lore3"));
	printf("%p\n",*list_ptr);
	// Print the list
	current = my_list;
	while (current)
	{
		printf("%s\n", (char *)current->content);
		current = current->next;
	}
	return (0);
}*/
