/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:55:08 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/18 14:33:00 by kyung-ki         ###   ########.fr       */
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

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (!(map[i][j] == MAP_WALL || map[i][j] == MAP_FLOOR
					|| map[i][j] == 'X'))
				return (FALSE);
			j++;
		}
		i++;
	}
	return (TRUE);
}
