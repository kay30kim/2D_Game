/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/26 14:33:50 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/26 14:34:04 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	check(t_gameimg *game_img, int i, int j)
{
	if (game_img->map[i][j] != MAP_ENTRY 
		&& game_img->map[i][j] != MAP_COLLECTABLE
		&& game_img->map[i][j] != MAP_EXIT 
		&& game_img->map[i][j] != MAP_FLOOR)
	{
		if (game_img->map[i][j] != MAP_WALL)
			return (1);
	}
	return (0);
}
