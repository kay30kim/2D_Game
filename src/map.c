/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:49:06 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/12 16:59:22 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

char	**read_map(char *script_map, int *fd)
{
	char	*temp_map;
	char	**map;
	int		n;

	n = 0;
	temp_map = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!temp_map)
		return (0);
	*fd = open(script_map, O_RDONLY);
	if (fd < 0)
	{
		free(temp_map);
		return (0);
	}
	n = read(*fd, temp_map, BUFFER_SIZE);
	if (n == -1 || n == 0)
	{
		free(temp_map);
		return (0);
	}
	map = ft_split(temp_map, '\n');
	free(temp_map);
	close(*fd);
	return (map);
}

/*
char	**read_map(char *script_map, int *fd)
{
	char	*line;
	char	**map;

	line = NULL;
	map = NULL;
	*fd = open(script_map, O_RDONLY);
	if (*fd < 0)
		return (NULL);
	while ((line = get_next_line(*fd)) != NULL)
	{
		map = ft_strarr_add(map, line);
		free(line);
	}
	close(*fd);
	return (map);
}*/

// char	**read_map(int fd)
// {
// 	char	*tmp;
// 	char	**map;
// 	int		n;

// 	n = 0;
// 	tmp = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
// 	if (!tmp)
// 		return (NULL);
// 	n = read(fd, tmp, BUFFER_SIZE);
// 	if (n == -1 || n == 0)
// 	{
// 		free(tmp);
// 		return (NULL);
// 	}
// 	map = ft_split(tmp, '\n');
// 	free(tmp);
// 	close(fd);
// 	return (map);
// }

void	set_mapsize(t_gameimg *gameImg, char **map)
{
	int	i;

	i = 0;
	gameImg->total_collect = get_total_collect(gameImg);
	gameImg->width = ft_strlen(map[0]) * MOVE;
	while (map[i])
		i++;
	gameImg->height = i * MOVE;
}

void	free_map(char **map)
{
	int	i;

	i = -1;
	while (map[++i])
		free(map[i]);
	free(map);
}

void	delete_dots(t_gameimg *gameImg)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = gameImg->total_collect;
	while (i < cnt)
	{
		if (((gameImg->p_img->collect->instances[i].y
					== gameImg->p_img->man->instances->y)
				&& (gameImg->p_img->collect->instances[i].x
					== gameImg->p_img->man->instances->x))
			&& gameImg->p_img->collect->instances[i].enabled == true)
		{
			cnt--;
			gameImg->p_img->collect->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}
