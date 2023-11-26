/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:05:52 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/26 14:08:56 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	get_textures(t_gameimg *gameImg)
{
	gameImg->p_text = ft_calloc(1, sizeof(t_texture));
	gameImg->p_text->floor = mlx_load_png("./textures/floor.png");
	if (!(gameImg->p_text->floor))
		exit(EXIT_FAILURE);
	gameImg->p_text->wall = mlx_load_png("./textures/stone.png");
	if (!(gameImg->p_text->wall))
		exit(EXIT_FAILURE);
	gameImg->p_text->collect = mlx_load_png("./textures/pancakes.png");
	if (!(gameImg->p_text->collect))
		exit(EXIT_FAILURE);
	gameImg->p_text->man = mlx_load_png("./textures/santa.png");
	if (!(gameImg->p_text->man))
		exit(EXIT_FAILURE);
	gameImg->p_text->exit = mlx_load_png("./textures/snowman.png");
	if (!(gameImg->p_text->exit))
		exit(EXIT_FAILURE);
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
			mlx_image_to_window(gameImg->mlx, image->floor,
				j * MOVE, i * MOVE);
			if (gameImg->map[i][j] == MAP_WALL)
				mlx_image_to_window(gameImg->mlx, image->wall,
					j * MOVE, i * MOVE);
			if (gameImg->map[i][j] == MAP_EXIT)
			{
				mlx_image_to_window(gameImg->mlx, image->exit,
					j * MOVE, i * MOVE);
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
				mlx_image_to_window(gameImg->mlx, image->collect,
					j * MOVE, i * MOVE);
			if (gameImg->map[i][j] == 'P')
				mlx_image_to_window(gameImg->mlx, image->man,
					j * MOVE, i * MOVE);
			j++;
		}
		i++;
	}
}

void	check_collect(t_gameimg *gameimg)
{
	if (gameimg->map[gameimg->p_img->man->instances->y / MOVE]
		[gameimg->p_img->man->instances->x / MOVE] == MAP_COLLECTABLE)
	{
		delete_dots(gameimg);
		gameimg->map[gameimg->p_img->man->instances->y / MOVE]
		[gameimg->p_img->man->instances->x / MOVE] = MAP_FLOOR;
		gameimg->collect_cnt++;
	}
	else if (gameimg->map[gameimg->p_img->man->instances->y / MOVE]
		[gameimg->p_img->man->instances->x / MOVE] == MAP_EXIT)
	{
		if (gameimg->collect_cnt == gameimg->total_collect)
			mlx_close_window(gameimg->mlx);
	}
}
