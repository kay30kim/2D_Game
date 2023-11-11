/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:49:06 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/09 15:44:38 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "game.h"

int	check_extension(const char *str)
{
	int	i;
	
	if (!str)
	{
		ft_printf(ERROR_MSG_NOFILE);
		return (FALSE);
	}
	i = ft_strlen(str) - 1;
	if (str[i] != 'r' || str[i - 1] != 'e'
		|| str[i - 2] != 'b'
		|| str[i - 3] != '.')
	{
		return (FALSE);
	}
	return (TRUE);
}

char	**read_map(char *script_map, int fd)
{
	char	*tmp;
	char	**map;
	int		n;

	n = 0;
	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	n = read(fd, tmp, BUFFER_SIZE);
	if (n == -1 || n == 0)
	{
		free(tmp);
		return (NULL);
	}
	map = ft_split(tmp, '\n');
	free(tmp);
	close(fd);
	return (map);
}

void	set_mapsize(t_sGameImg *gameImg, char **map)
{
	int	i;

	i = 0;
	gameImg->nTotalCollect = get_total_collect(gameImg);
	gameImg->width = ft_strlen(map[0]) * 32;
	while (map[i])
		i++;
	gameImg->height = i * 32;
}