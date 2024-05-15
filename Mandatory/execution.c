/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:51:11 by mel-jira          #+#    #+#             */
/*   Updated: 2024/05/13 17:26:06 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall2(t_map *map, double horizontal_x, double horizontal_y)
{
	int	x;
	int	y;

	x = floor(horizontal_x / 32);
	y = floor(horizontal_y / 32);
	if (y < 0 || y >= (map->my)
		|| x < 0 || x >= (map->mx))
		return (0);
	if (map->map[y][x] == '1')
		return (1);
	return (0);
}

void	horizontal_helper(t_map *map, double ray_angle)
{
	map->intercept_y = floor(map->player_y / 32) * 32;
	if (map->dawn)
		map->intercept_y += 32;
	map->intercept_x = map->player_x \
	+ (map->intercept_y - map->player_y) / tan(ray_angle);
	map->ystep = 32;
	if (map->up)
		map->ystep *= -1;
	map->xstep = 32 / tan(ray_angle);
	if (map->left && map->xstep > 0)
		map->xstep *= -1;
	if (map->right && map->xstep < 0)
		map->xstep *= -1;
	map->horizontal = 0;
}

void	horizontal(t_map *map, double ray_angle)
{
	double	horizontal_x;
	double	horizontal_y;

	horizontal_helper(map, ray_angle);
	horizontal_y = map->intercept_y;
	horizontal_x = map->intercept_x;
	while (horizontal_y >= 0 && horizontal_x >= 0
		&& horizontal_x <= ((map->mx - 2) * 32)
		&& horizontal_y <= ((map->my - 2) * 32))
	{
		if (is_wall2(map, horizontal_x, (horizontal_y - map->up)))
		{
			map->horizontal_x = horizontal_x;
			map->horizontal_y = horizontal_y;
			map->horizontal = 1;
			return ;
		}
		horizontal_x += map->xstep;
		horizontal_y += map->ystep;
	}
	map->horizontal_x = LONG_MAX;
	map->horizontal_y = LONG_MAX;
}

void	vertical_helper(t_map *map, double ray_angle)
{
	map->intercept_x = floor(map->player_x / 32) * 32;
	if (map->right)
		map->intercept_x += 32;
	map->intercept_y = map->player_y \
	+ (map->intercept_x - map->player_x) * tan(ray_angle);
	map->xstep = 32;
	if (map->left)
		map->xstep *= -1;
	map->ystep = 32 * tan(ray_angle);
	if (map->up && map->ystep > 0)
		map->ystep *= -1;
	if (map->dawn && map->ystep < 0)
		map->ystep *= -1;
	map->vertical = 0;
}

int	execution(t_map map)
{
	map.img.img = mlx_new_image(map.mlx, map.width, map.height);
	mlx_hook(map.win, 17, 0, &close_window, &map);
	map.img.addr = mlx_get_data_addr(map.img.img,
			&map.img.bits_per_m_pixel, &map.img.line_length,
			&map.img.endian);
	mlx_hook(map.win, 2, 0, key_hook1, &map);
	mlx_hook(map.win, 3, 0, key_hook2, &map);
	mlx_loop_hook(map.mlx, ft_update, &map);
	mlx_loop(map.mlx);
	return (0);
}
