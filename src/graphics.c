/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:05:52 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/12 16:18:07 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	get_textures(t_gameimg *gameImg)
{
	gameImg->p_text = ft_calloc(1, sizeof(t_texture));
	gameImg->p_text->floor = mlx_load_png("./textures/floor.png");
	gameImg->p_text->wall = mlx_load_png("");
	gameImg->p_text->collect = mlx_load_png("");
	gameImg->p_text->man = mlx_load_png("");
	gameImg->p_text->exit = mlx_load_png("");
}

void	get_images(t_gameimg *gameImg)
{
	gameImg->p_img = ft_calloc(1, sizeof(t_image));
	gameImg->p_img->floor = mlx_texture_to_image(gameImg->mlx,
			gameImg->p_text->floor);
	gameImg->p_img->wall = mlx_texture_to_image(gameImg->mlx,
			gameImg->p_text->wall);
	gameImg->p_img->collect = mlx_texture_to_image(gameImg->mlx,
			gameImg->p_text->collect);
	gameImg->p_img->man = mlx_texture_to_image(gameImg->mlx,
			gameImg->p_text->man);
	gameImg->p_img->exit = mlx_texture_to_image(gameImg->mlx,
			gameImg->p_text->exit);
	mlx_delete_texture(gameImg->p_text->floor);
	mlx_delete_texture(gameImg->p_text->wall);
	mlx_delete_texture(gameImg->p_text->collect);
	mlx_delete_texture(gameImg->p_text->man);
	mlx_delete_texture(gameImg->p_text->exit);
}

void	draw_floor(t_gameimg *gameImg, t_image *image)
{
	int	i;
	int	j;

	i = 0;
	while (gameImg->map[i])
	{
		j = 0;
		while (gameImg->map[i][j])
		{
			mlx_image_to_window(gameImg->mlx, image->floor, i * MOVE, j * MOVE);
			if (gameImg->map[i][j] == MAP_WALL)
				mlx_image_to_window(gameImg->mlx, image->wall, i * MOVE, j
					* MOVE);
			if (gameImg->map[i][j] == MAP_EXIT)
			{
				mlx_image_to_window(gameImg->mlx, image->exit, i * MOVE, j
					* MOVE);
			}
			j++;
		}
		i++;
	}
}

void	draw_map(t_gameimg *gameImg, t_image *image)
{
	int	i;
	int	j;

	draw_floor(gameImg, image);
	i = 0;
	while (gameImg->map[i])
	{
		j = 0;
		while (gameImg->map[i][j])
		{
			if (gameImg->map[i][j] == 'C')
				mlx_image_to_window(gameImg->mlx, image->collect, i * MOVE, j
					* MOVE);
			if (gameImg->map[i][j] == 'P')
				mlx_image_to_window(gameImg->mlx, image->man, i * MOVE, j
					* MOVE);
			j++;
		}
		i++;
	}
}
