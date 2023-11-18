/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kyung-ki <kyung-ki@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:49:14 by kyung-ki          #+#    #+#             */
/*   Updated: 2023/11/18 15:06:34 by kyung-ki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_H
# define GAME_H

# include "MLX42/MLX42.h"
# include "ft_printf.h"
# include "get_next_line.h"
# include "libft.h"
# include <fcntl.h>

# define ERROR_MSG_ARG "[ERROR] You need one argument\n"
# define ERROR_MSG_FILENO "[ERROR] Invalid file\n"
# define ERROR_MSG_EXTENSION "[ERROR] It is not .ber file\n"
# define ERROR_MSG_NOFILE "[ERROR] There is no file name\n"
# define ERROR_MSG_OPEN "[ERROR] Can't open the map\n"
# define ERROR_MSG_INIT "[ERROR] Initialization is failed\n"
# define ERROR_MSG_PATH "[ERROR] THis is not a valid path\n"
# define ERROR_MSG_MAP "[ERROR] Map is not good\n"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# define MAP_COLLECTABLE 67		// ASCII ='C'
# define MAP_WALL 49			// ASCII = '1'
# define MAP_FLOOR 48			// ASCII = '0'
# define MAP_EXIT 69			// ASCII = 'E'
# define MAP_ENTRY 80			// ASCII = 'P'

# ifndef TRUE
#  define TRUE 1
# endif
# ifndef FALSE
#  define FALSE 0
# endif
# define MOVE 32

typedef struct Textures
{
	mlx_texture_t	*floor;
	mlx_texture_t	*wall;
	mlx_texture_t	*collect;
	mlx_texture_t	*man;
	mlx_texture_t	*exit;
}	t_texture;

typedef struct Images
{
	mlx_image_t		*floor;
	mlx_image_t		*wall;
	mlx_image_t		*collect;
	mlx_image_t		*man;
	mlx_image_t		*exit;
	mlx_image_t		*exit_2;
}	t_image;

typedef struct Game
{
	int				width;
	int				height;
	int				total_collect;
	int				collect_cnt;
	int				move_cnt;
	char			**map;
	char			**tmp;
	mlx_t			*mlx;
	t_texture		*p_text;
	t_image			*p_img;
}	t_gameimg;

void	get_textures(t_gameimg *gameImg);
void	get_images(t_gameimg *gameImg);
void	draw_floor(t_gameimg *gameImg, t_image *image);
void	draw_map(t_gameimg *gameImg, t_image *image);
void	check_collect(t_gameimg *gameImg);
void	ft_key(mlx_key_data_t keydata, void *param);
int		init_game(t_gameimg *gameImg);
void	go_game(t_gameimg *gameImg);
int		get_total_collect(t_gameimg *gameImg);
int		check_extension(const char *str);
char	**read_map(char *script_map);
void	set_mapsize(t_gameimg *gameImg, char **map);
void	free_map(char **map);
void	delete_dots(t_gameimg *gameImg);
int		valid_path(t_gameimg *gameImg, char *map);
int		*start_position(char **map);
void	flood_map(t_gameimg *gameImg, int i, int j);
void	move_up(t_gameimg *gameImg);
void	move_right(t_gameimg *gameImg);
void	move_down(t_gameimg *gameImg);
void	move_left(t_gameimg *gameImg);
int		check_flood(char **map);
int		check_map(t_gameimg *game_img, int cnt_entry,
			int cnt_exit, int cnt_col);

#endif