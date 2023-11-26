/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:55:08 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/26 14:50:09 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	move_up(t_gameimg *gameImg)
{
	if (gameImg->map[gameImg->p_img->man->instances->y / MOVE - 1]
		[gameImg->p_img->man->instances->x / MOVE] != MAP_WALL)
	{
		gameImg->p_img->man->instances->y -= MOVE;
		gameImg->move_cnt++;
		ft_printf("Move cnt : %d\n", gameImg->move_cnt);
	}
}

void	move_right(t_gameimg *gameImg)
{
	if (gameImg->map[gameImg->p_img->man->instances->y / MOVE]
		[gameImg->p_img->man->instances->x / MOVE + 1] != MAP_WALL)
	{
		gameImg->p_img->man->instances->x += MOVE;
		gameImg->move_cnt++;
		ft_printf("Move cnt : %d\n", gameImg->move_cnt);
	}
}

void	move_down(t_gameimg *gameImg)
{
	if (gameImg->map[gameImg->p_img->man->instances->y / MOVE + 1]
		[gameImg->p_img->man->instances->x / MOVE] != MAP_WALL)
	{
		gameImg->p_img->man->instances->y += MOVE;
		gameImg->move_cnt++;
		ft_printf("Move cnt : %d\n", gameImg->move_cnt);
	}
}

void	move_left(t_gameimg *gameImg)
{
	if (gameImg->map[gameImg->p_img->man->instances->y / MOVE]
		[gameImg->p_img->man->instances->x / MOVE - 1] != MAP_WALL)
	{
		gameImg->p_img->man->instances->x -= MOVE;
		gameImg->move_cnt++;
		ft_printf("Move cnt : %d\n", gameImg->move_cnt);
	}
}

int	check_flood(char **map)
{
	int	i;
	int	j;
	int	height;

	height = 0;
	while (map[height])
		height++;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == MAP_WALL || map[i][j] == MAP_FLOOR
					|| map[i][j] == 'X'))
				return (FALSE);
			if ((i == 0 && map[i][j] == MAP_FLOOR)
			|| (j == 0 && map[i][j] == MAP_FLOOR)
			|| (i == height - 1 && map[i][j] == MAP_FLOOR)
			|| (j == (int)ft_strlen(map[0]) - 1 && map[i][j] == MAP_FLOOR))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
