/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:48:46 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/11 13:43:20 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

void	check_collect(t_sGameImg *gameImg)
{
	if (gameImg->map[gameImg->pImg->man->instances->y / 32][gameImg->pImg->man->instances->x / 32] == MAP_COLLECTABLE)
	{
		delete_dot(gameImg);
		gameImg->map[gameImg->pImg->man->instances->y / 32][gameImg->pImg->man->instances->x / 32] = MAP_FLOOR;
		gameImg->collectCnt++;
		if (gameImg->collectCnt == gameImg->nTotalCollect)
			gameImg->pImg->exit->instances->enabled = false;
	}
	else if (gameImg->map[gameImg->pImg->man->instances->y / 32][gameImg->pImg->man->instances->x / 32] == MAP_EXIT)
	{
		if (gameImg->collectCnt == gameImg->nTotalCollect)
			mlx_close_window(gameImg->mlx);
	}
}

void	ft_key(mlx_key_data_t keydata, void *param)
{
	t_sGameImg *gameImg;

	gameImg = param;
	if ((keydata.key == MLX_KEY_W && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_UP && keydata.action == MLX_RELEASE))
		move_up(gameImg);
	if ((keydata.key == MLX_KEY_D && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_RIGHT && keydata.action == MLX_RELEASE))
		move_right(gameImg);
	if ((keydata.key == MLX_KEY_S && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_DOWN && keydata.action == MLX_RELEASE))
		move_down(gameImg);
	if ((keydata.key == MLX_KEY_A && keydata.action == MLX_RELEASE)
		|| (keydata.key == MLX_KEY_LEFT && keydata.action == MLX_RELEASE))
		move_left(gameImg);
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_RELEASE)
		mlx_close_window(gameImg->mlx);
	check_collect(gameImg);
}

int	init_game(t_sGameImg *gameImg)
{
	gameImg->moveCnt = 0;
	gameImg->collectCnt = 0;
	if (!(gameImg->mlx = mlx_init(gameImg->width, gameImg->height
				, "so_long", TRUE)));
	{
		puts(mlx_strerror(mlx_errno));
		return(FALSE);
	}
	return (TRUE);
}

void	go_game(t_sGameImg *gameImg)
{
	get_textures(gameImg);
	get_images(gameImg);
	draw_map(gameImg, gameImg->pImg);
	mlx_key_hook(gameImg->mlx, &ft_key, gameImg);
	mlx_loop(gameImg->mlx);
	mlx_terminate(gameImg->mlx);
	free_map(gameImg->map);
	free(gameImg->pText);
	free(gameImg->pImg);
}

int	main(int argc, char **argv)
{
	t_sGameImg	gameImg;
	int			fd;

	if (argc != 2)
		return (ft_printf(ERROR_MSG_ARG));
	if (!check_extension(argv[1]))
		return (ft_printf(ERROR_MSG_EXTENSION));
	ft_bzero(&gameImg, sizeof(t_sGameImg));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (ft_printf(ERROR_MSG_FILENO));
	gameImg.map = read_map(argv[1], fd);
	if (!gameImg.map)
		return (ft_printf(ERROR_MSG_OPEN));
	set_mapsize(gameImg, gameImg.map); // 32 check
	if (valid_path(&gameImg, argv[1]) == FALSE)
		return (free_map(gameImg.map), 1);
	if (init_game(&gameImg) == FALSE)
		return (ft_printf(ERROR_MSG_INIT));
	else
		go_game(&gameImg);
	return (0);
}
