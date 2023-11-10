/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:48:46 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/09 20:26:39 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include "libft.h"

int	init_game(t_sGameImg *gameImg)
{
	gameImg->moveCnt = 0;
	gameImg->collectCnt = 0;
	if (!(gameImg->mlx = mlx_init(gameImg->width, gameImg->height
				, "so_long", TRUE)));
	{
		puts(mlx_strerror(mlx_errno));
		return(EXIT_FAILURE);
	}
	get_textures(gameImg);
	get_images(gameImg);
	draw_map(gameImg, gameImg->pImg);
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
	return (0);
}
