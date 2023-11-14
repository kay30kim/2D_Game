/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:26:39 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/13 12:27:17 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	get_total_collect(t_gameimg *gameImg)
{
	int	total;
	int	i;
	int	j;

	total = 0;
	i = 0;
	while (gameImg->map[i])
	{
		j = 0;
		while (gameImg->map[i][j])
		{
			if (gameImg->map[i][j] == 'C')
				total++;
			j++;
		}
		i++;
	}
	return (total);
}

void	flood_map(t_gameimg *gameImg, int i, int j)
{
	if (!(i < 1 || j < 1 || j >= gameImg->width || i > gameImg->height
			|| gameImg->tmp[i][j] == '1' || gameImg->tmp[i][j] == 'X'))
	{
		gameImg->tmp[i][j] = 'X';
		flood_map(gameImg, i + 1, j);
		flood_map(gameImg, i - 1, j);
		flood_map(gameImg, i, j + 1);
		flood_map(gameImg, i, j - 1);
	}
}

int	*start_position(char **map)
{
	int	i;
	int	j;
	int	*pos;

	pos = (int *)ft_calloc(2, sizeof(int));
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == MAP_ENTRY)
			{
				pos[0] = i;
				pos[1] = j;
			}
			j++;
		}
		i++;
	}
	return (pos);
}

int	valid_path(t_gameimg *gameImg, char *map)
{
	int	*pos;

	gameImg->tmp = read_map(map);
	pos = start_position(gameImg->tmp);
	flood_map(gameImg, pos[0], pos[1]);
	if (check_flood(gameImg->tmp) == FALSE)
	{
		free(pos);
		free_map(gameImg->tmp);
		return (ft_printf(ERROR_MSG_PATH), FALSE);
	}
	free(pos);
	free_map(gameImg->tmp);
	return (TRUE);
}
