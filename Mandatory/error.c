/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:20:16 by mel-jira          #+#    #+#             */
/*   Updated: 2024/05/14 20:38:59 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	error1(void)
{
	write(2, "Error\n", 7);
	write(2, "something went unexpectedly wrong\n", 35);
	exit(1);
}

void	error2(void)
{
	write(2, "Error\n", 7);
	write(2, "map saction\n", 13);
}

void	error43(void)
{
	write(2, "Error\n", 7);
	write(2, "colores or texture saction of map\n", 35);
}

void	error5(void)
{
	write(2, "Error\n", 7);
	write(2, "map name\n", 10);
}

void	error_player(void)
{
	write(2, "Error\n", 7);
	write(2, "there is more then one player\n", 31);
}
