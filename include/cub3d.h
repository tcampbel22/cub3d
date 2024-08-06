/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: clundber < clundber@student.hive.fi>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 15:08:23 by clundber          #+#    #+#             */
/*   Updated: 2024/08/06 15:00:14 by clundber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h> 	// for printf, perror
# include <unistd.h> 	// for write, close, read
# include <fcntl.h>		// for open
# include <stdlib.h> 	// for malloc, free, exit
# include <string.h> 	// for strerror
# include <math.h>
# include <stdbool.h>
# include <limits.h>
# include "../libft/includes/libft.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <unistd.h>

# define DEG_RAD 0.0174532925
# define PI 3.14159265359
# define BUBBLE 0.2
# define mms 3
typedef struct s_data	t_data;

typedef enum e_key
{
	LEFT,
	RIGHT,
	FORWARD,
	BACK,
	S_LEFT,
	S_RIGHT
}	t_key;

typedef enum e_wall
{
	NORTH,
	EAST,
	SOUTH,
	WEST
}	t_wall;

typedef struct s_txt
{
	float 	wall_txt_x;
	int		wall_face;
}	t_txt;

typedef struct s_img
{
	mlx_image_t		*mm; //minimap
	mlx_image_t		*mm_wall; //minimap  walls
	mlx_image_t		*mm_floor; //minmap floor
	mlx_image_t		*floor; //game floor
	mlx_image_t 	*ceiling; //game ceiling
	mlx_image_t		*pl; //player
	mlx_image_t		*ray_grid; //layer for all the rays
	mlx_image_t		*fg; //foreground
	mlx_image_t		*wall_txt[5];
	mlx_t		*mlx;
}	t_img;

typedef struct s_ray
{
	t_data	*data;
	float	hori_x;
	float	hori_y;
	float	vert_x;
	float	vert_y;
	float	h_delta_x;
	float	h_delta_y;
	float	v_delta_x;
	float	v_delta_y;
	float	horizontal_dist;
	float	vertical_dist;
	float	ray_orient;
	float	distance;
	float	h_step_dist;
	float	v_step_dist;
	float	proj_plane;
	//int		wall_face;
}	t_ray;

typedef struct s_player
{
	float		pl_x;
	float		pl_y;
	float		p_orientation;
	float		step_x;
	float		step_y;
	float		bub_x;
	float		bub_y;
	t_data		*data;
}	t_player;

typedef struct s_data
{
	char		**map;
	int			mapstart;
	float		map_x_border;
	float		map_y_border;
	int			floor[4];
	int			ceiling[4];
	char		*wall_text[5]; //0N, 1E, 2S, 3W    //rename to wall_path
	float		s_height;
	float		s_width;
	float		fov;
	float		render_dist;
	t_player	*player;
	t_ray		*ray;
	t_img		*img;
	t_txt		*txt;
	mlx_t		*mlx;
	float		scale;
}	t_data;



//INIT

void	init_all(t_data *data, t_ray *ray, t_player *player, t_txt *txt);
void	init_img_text(t_img *img);

//UTILS

float	get_scale(t_data *data);
int		ft_atoi_cubd(const char *str);

//RAYCASTING, COLOURS, RENDERING

int		get_txt_color(mlx_image_t *img, int x, int y);
int		make_color(int r, int g, int b, int a);
void	mm_render(t_data *data, t_player *player, t_img *img);
void	minimap(t_data *data, t_img *img);
void	color_image(mlx_image_t *image, int color);
void	update_params(t_data *data, t_ray *ray);
int		ft_collision(t_data *data, float y, float x);
void	ray_main(void *param);
void	update_mm_player(t_data *data, t_player *pl);
void	fix_orientation(float *orientation);

//MLX
void	mlx_main(t_data *data);
void	keypress(void *param);
void	safe_pixel(mlx_image_t *img, uint32_t x, uint32_t y, uint32_t color);
void	safe_image(t_data *data, uint32_t w, uint32_t h, mlx_image_t **img);
void	move_player(t_data *data, t_player *pl, t_key key);
void	safe_texture(t_data *data, mlx_texture_t **img, char *path);
void	safe_text_to_image(t_data *data, mlx_texture_t *text, mlx_image_t **img);

//PARSING

int		parsing(int argc, char **argv, t_data *data);
int		map_parse(char *map_str, t_data *data);
char	*get_path(char *line);
int		ft_isspace(char c);
int		check_name(char *str);
int		check_line(char *line, t_data *data);
int		get_color(int *arr, char *str);
int		extract_data(char *arg, t_data *data);
int		validate_map(t_data *data);

//FREE & ERROR

int		ft_nullfree(char *str, int err);
int		ret_error(char *str);
void	free_img(t_img *img);
void	ft_mapfree(char **array);
void	armageddon(t_data *data, char *error);

#endif
