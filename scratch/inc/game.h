/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:49:14 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/09 20:24:36 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "MLX42/include/MLX42/MLX42.h"

#define ERROR_MSG_ARG			"[ERROR] You need one argument"
#define ERROR_MSG_FILENO		"[ERROR] Invalid file"
#define ERROR_MSG_EXTENSION		"[ERROR] It is not .ber file"
#define ERROR_MSG_NOFILE		"[ERROR] There is no file name"
#define ERROR_MSG_OPEN			"[ERROR] Can't open the map"
#define ERROR_MSG_INIT			"[ERROR] Initialization is failed"
#define BUFFER_SIZE				10000

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 0
#endif

typedef struct Textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collect;
	mlx_texture_t	*man;
	mlx_texture_t	*exit;
} t_sTexture;

typedef struct Images
{
	mlx_image_t	*floor;
	mlx_image_t	*wall;
	mlx_image_t	*collect;
	mlx_image_t	*man;
	mlx_image_t	*exit;
	mlx_image_t	*exit_2;
} t_sImage;

typedef struct Game
{
	int			width;
	int			height;
	int			nTotalCollect;
	int			collectCnt;
	int			moveCnt;
	char		**map;
	mlx_t		*mlx;
	t_sTexture	*pText;
	t_sImage	*pImg;
} t_sGameImg;