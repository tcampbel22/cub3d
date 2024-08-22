/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 15:43:17 by tcampbel          #+#    #+#             */
/*   Updated: 2024/08/22 18:05:09 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	sprite_dist(t_data *data, t_sprite *sprite)
{
	float	x;
	float	y;

	x = sprite->x - data->pl->pl_x;
	y = sprite->y - data->pl->pl_y;
	sprite->dist = sqrt(x * x + y * y);
	sprite->angle = atan2(y, x) - data->pl->p_orientation;
	  if (sprite->angle < -PI)
        sprite->angle += 2 * PI;
    if (sprite->angle >= 2 * PI)
        sprite->angle -= 2 * PI;
}

void	sprite_scale(t_data *data, t_sprite *sprite, mlx_image_t *frame)
{
	sprite->scale = data->ray->proj_plane / (sprite->dist * 100);
	sprite->width = sprite->scale * frame->width;
	sprite->height = sprite->scale * frame->height;
}

void	render_sprite(t_data *data, t_sprite *sprite, t_ray *ray)
{
	float	sp_x;
	int		x;
	int		y;
	float	start_x;
	float	start_y;
	float	end_x;
	float	end_y;
	float	sp_txt_x;
	float	sp_txt_y;

	sprite_dist(data, sprite);
	sprite_scale(data, sprite, sprite->frame[sprite->c_frame]);
	if (sprite->angle < (-PI / 2 + 0.1) || sprite->angle > (PI / 2 + 0.1))
        return;
	sp_x = (data->s_width / 2) + (tan(sprite->angle) * ray->proj_plane);
	if (sp_x < 0 || sp_x > data->s_width)
		return ;
	start_x = sp_x - (sprite->width / 2);
	end_x = sp_x + (sprite->width / 2);
	start_y = fl_max(0.0f, ((data->s_height / 2) - (sprite->height / 2)));
	end_y = fl_min((data->s_height - 1.0f), ((data->s_height / 2) + (sprite->height / 2)));
	x = start_x;
	while (x < end_x)
	{
		if (x >= 0 && x < data->s_width)
		{
			y = start_y;
			if (sprite->dist < data->depth[x])
			{
				while (y < end_y)
				{
					if (y >= 0 && y < data->s_height)
					{
						sp_txt_x = ((x - start_x) / sprite->width) * sprite->frame[sprite->c_frame]->width;
						sp_txt_y = ((y - start_y) / sprite->height) * sprite->frame[sprite->c_frame]->height;
						int	colour = get_txt_color(sprite->frame[sprite->c_frame], sp_txt_x, sp_txt_y, data->txt->shade);
						int	alpha = (colour >> 24) & 0xFF;
						if (alpha != 0)
							safe_pixel(data->img->sprite, x, y, colour);
					}
					y++;
				}
			}
		}
		x++;
	}
}

void	sprite(t_data *data, t_ray *ray, t_sprite *duck)
{
	duck->x = 5.5;
	duck->y = 5;
	if (data->img->sprite)
		mlx_delete_image(data->mlx, data->img->sprite);
	safe_image(data, data->s_width, data->s_height, &data->img->sprite);
	render_sprite(data, duck, ray);
	mlx_image_to_window(data->mlx, data->img->sprite, 0, 0);
}
