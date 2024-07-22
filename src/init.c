/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcampbel <tcampbel@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:08:19 by clundber          #+#    #+#             */
/*   Updated: 2024/07/22 15:14:32 by tcampbel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    init_all(t_data *data, t_ray *ray)
{
    int i;

    i = 0;
	data->player_x = 0;
    data->player_y = 0;
    data->mapstart = -1;
    data->p_orientation =  0;
    data->map_x_border = 0;
    data->map_y_border = 0;
	data->wall_text[0] = NULL;
    data->wall_text[1] = NULL;
    data->wall_text[2] = NULL;
    data->wall_text[3] = NULL;
    data->wall_text[4] = NULL;     
    data->s_height = 0;
    data->s_width = 0;
    data->fov = 0;
    data->fov_depth = 0;
    data->mlx = NULL;
    data->map = NULL;
    while (i < 3)
    {
        data->floor[i] = -1;
        data->ceiling[i] = -1;
		i++;
    }
	data->floor[3] = 0;
	data->ceiling[3] = 0;
   	ray->data = data;
    ray->hori_x = 0;
    ray->hori_y = 0;
	ray->vert_x = 0;
	ray->vert_y = 0;
    ray->ray_orient = 0;
    ray->distance = 0;
	ray->horizontal_dist = 0;
	ray->vertical_dist = 0;
    data->ray = ray;
    data->scale = 0;
}
