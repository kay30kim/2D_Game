/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 16:05:52 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/09 20:32:30 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	get_textures(t_sGameImg *gameImg)
{
	gameImg->pText = ft_calloc(1, sizeof(t_sTexture));
	gameImg->pText->floor = mlx_load_png("./textures/floor.png");
	gameImg->pText->wall = mlx_load_png("");
	gameImg->pText->collect = mlx_load_png("");
	gameImg->pText->man = mlx_load_png("");
	gameImg->pText->exit = mlx_load_png("");
}

void	get_images(t_sGameImg *gameImg)
{
	gameImg->pImg = ft_calloc(1, sizeof(t_sImage));
	gameImg->pImg->floor = mlx_texture_to_image(gameImg->mlx, gameImg->pText->floor);
	gameImg->pImg->wall = mlx_texture_to_image(gameImg->mlx, gameImg->pText->wall);
	gameImg->pImg->collect = mlx_texture_to_image(gameImg->mlx, gameImg->pText->collect);
	gameImg->pImg->man = mlx_texture_to_image(gameImg->mlx, gameImg->pText->man);
	gameImg->pImg->exit = mlx_texture_to_image(gameImg->mlx, gameImg->pText->exit);
	mlx_delete_texture(gameImg->pText->floor);
	mlx_delete_texture(gameImg->pText->wall);
	mlx_delete_texture(gameImg->pText->collect);
	mlx_delete_texture(gameImg->pText->man);
	mlx_delete_texture(gameImg->pText->exit);
}

void	draw_map(t_sGameImg *gameImg, t_sImage *image)
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
				mlx_image_to_window(gameImg->mlx, image->collect, i * 32, j *32);
			
			if (gameImg->map[i][j] == 'P')
				mlx_image_to_window(gameImg->mlx, image->man, i*32, j*32);
			j++;
		}
		i++;
	}
}