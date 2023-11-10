/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:26:39 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/09 15:42:05 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int get_total_collect(t_sGameImg *gameImg)
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
