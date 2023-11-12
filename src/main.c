/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:48:46 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/12 16:59:53 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	check_collect(t_gameimg *gameimg)
{
	if (gameimg->map[gameimg->p_img->man->instances->y / MOVE]
		[gameimg->p_img->man->instances->x / MOVE] == MAP_COLLECTABLE)
	{
		delete_dots(gameimg);
		gameimg->map[gameimg->p_img->man->instances->y / MOVE]
		[gameimg->p_img->man->instances->x / MOVE] = MAP_FLOOR;
		gameimg->collect_cnt++;
		if (gameimg->collect_cnt == gameimg->total_collect)
			gameimg->p_img->exit->instances->enabled = false;
	}
	else if (gameimg->map[gameimg->p_img->man->instances->y / MOVE]
		[gameimg->p_img->man->instances->x / MOVE] == MAP_EXIT)
	{
		if (gameimg->collect_cnt == gameimg->total_collect)
			mlx_close_window(gameimg->mlx);
	}
}

void	ft_key(mlx_key_data_t keydata, void *param)
{
	t_gameimg	*gameimg;

	gameimg = param;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE))
		move_up(gameimg);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE))
		move_right(gameimg);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE))
		move_down(gameimg);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE))
		move_left(gameimg);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(gameimg->mlx);
	check_collect(gameimg);
}

int	init_game(t_gameimg *gameimg)
{
	gameimg->move_cnt = 0;
	gameimg->collect_cnt = 0;
	gameimg->mlx = mlx_init(gameimg->width, gameimg->height, "so_long", TRUE);
	if (!(gameimg->mlx))
	{
		puts(mlx_strerror(mlx_errno));
		return (FALSE);
	}
	return (TRUE);
}

void	go_game(t_gameimg *gameimg)
{
	get_textures(gameimg);
	get_images(gameimg);
	draw_map(gameimg, gameimg->p_img);
	mlx_key_hook(gameimg->mlx, &ft_key, gameimg);
	mlx_loop(gameimg->mlx);
	mlx_terminate(gameimg->mlx);
	free_map(gameimg->map);
	free(gameimg->p_text);
	free(gameimg->p_img);
}

int	main(int argc, char **argv)
{
	printf("aaa");
	t_gameimg	gameimg;
	int			fd;

	if (argc != 2)
		return (ft_printf(ERROR_MSG_ARG));
	if (!check_extension(argv[1]))
		return (ft_printf(ERROR_MSG_EXTENSION));
	gameimg.map = read_map(argv[1], &fd);
	if (!gameimg.map)
		return (ft_printf(ERROR_MSG_OPEN));
	set_mapsize(&gameimg, gameimg.map);
	if (valid_path(&gameimg, fd) == FALSE)
		return (free_map(gameimg.map), 1);
	if (init_game(&gameimg) == FALSE)
		return (ft_printf(ERROR_MSG_INIT));
	else
		go_game(&gameimg);
	return (0);
}
