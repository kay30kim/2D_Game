/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 12:29:50 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/10/26 16:23:10 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// while + if + while
int	ft_cnt_str(const char *s, char c)
{
	int	cnt;
	int	i;

	cnt = 0;
	i = 0;
	while (s && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			cnt++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (cnt);
}

int	ft_len_str(const char *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

void	ft_init(int *i, int *j, int *k)
{
	*i = -1;
	*j = -1;
	*k = 0;
}

char	**ft_split_go(char const *s, char c, char **res)
{
	int		i;
	int		j;
	int		k;

	ft_init(&i, &j, &k);
	while (++j < ft_cnt_str(s, c) && ++i > -1)
	{
		while (s[i] && s[i] == c)
			i++;
		res[j] = (char *)malloc(sizeof(char) * (ft_len_str(&s[i], c) + 1));
		if (!res[j])
		{
			while (j > 0)
				free(res[--j]);
			free(res);
			return (NULL);
		}
		k = 0;
		while (s[i] && s[i] != c)
			res[j][k++] = s[i++];
		res[j][k] = '\0';
	}
	res[j] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * (ft_cnt_str(s, c) + 1));
	if (!res || !s)
		return (NULL);
	return (ft_split_go(s, c, res));
}
/*
#include <stdio.h>
int main(void)
{
    const char *input = "   long  space  check  ";
	char *input2 = "xxxxxxxxhello!";
    const char delimiter = 'x';

    char **result = ft_split(input, delimiter);

    if (result) {
        for (int i = 0; result[i] != NULL; i++) {
            printf("Substring %d: >%s<\n", i + 1, result[i]);
            free(result[i]); // Free each substring
        }

        free(result); // Free the array of substrings
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}

void *ft_free_table(char **table)
{
	int i;

	i = 0;
	while(table[i])
	{
		free(table[i])
		i++;
	}
	free(table);
	return (NULL);
}
*/
/*
need to be care about !s
while (s && s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i]) // -> should not i++
			cnt++;
		while (s[i] && s[i] != c)
			i++;
	}
*/
