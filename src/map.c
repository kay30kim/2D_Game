/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 11:49:06 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/18 14:34:26 by kyung-ki         ###   ########.fr       */
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

char	**read_map(char *script_map)
{
	char	**map;
	char	*buf;
	char	*tmp;
	int		n;
	int		fd;

	n = 0;
	fd = open(script_map, O_RDONLY);
	if (fd < 0)
		return (0);
	tmp = NULL;
	buf = NULL;
	while (n == 0 || tmp != NULL)
	{
		n = 1;
		tmp = get_next_line(fd);
		buf = ft_strjoin2(buf, tmp);
	}
	map = ft_split(buf, '\n');
	free(buf);
	close(fd);
	return (map);
}

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