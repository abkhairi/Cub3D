/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utilitis4.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abkhairi <abkhairi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 18:18:35 by mel-jira          #+#    #+#             */
/*   Updated: 2024/05/15 19:33:33 by abkhairi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	basic_init(t_mapheader *mapheader)
{
	mapheader->no = 0;
	mapheader->we = 0;
	mapheader->ea = 0;
	mapheader->so = 0;
	mapheader->f = 0;
	mapheader->c = 0;
}

int	count_c(char *str, char c)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str == c)
			i++;
		str++;
	}
	return (i);
}

int	valid_colors(t_map *map, char *str, int f_or_c)
{
	char	**tmp;
	int		i;

	tmp = NULL;
	i = 0;
	if (count_c(str, ',') > 2)
		return (1);
	tmp = ft_split(str, ',');
	if (!tmp)
		return (1);
	while (i < 3 && tmp[i] && tmp[i][0])
	{
		if (ft_atoi(tmp[i], 0) > 255 || ft_atoi(tmp[i], 0) < 0)
			return (1);
		if (f_or_c)
			map->ceiling[i] = ft_atoi(tmp[i], 0);
		else
			map->floor[i] = ft_atoi(tmp[i], 0);
		i++;
	}
	if (i != 3)
		return (1);
	if (tmp[i])
		return (1);
	return (0);
}
