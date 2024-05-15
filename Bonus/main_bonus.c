/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mel-jira <mel-jira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 12:13:22 by mel-jira          #+#    #+#             */
/*   Updated: 2024/05/14 20:40:47 by mel-jira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

t_leaks	*ft_last_node(t_leaks *node)
{
	t_leaks	*tmp;

	tmp = node;
	if (tmp)
	{
		while (tmp->next)
			tmp = tmp->next;
		return (tmp);
	}
	return (NULL);
}

void	*ft_malloc(size_t a)
{
	static t_leaks	*l;
	t_leaks			*tmp;

	if (!l)
	{
		l = malloc(sizeof(t_leaks));
		if (!l)
			error1();
		l->next = NULL;
		l->ptr = malloc(a);
		if (!l->ptr)
			error1();
		return (l->ptr);
	}
	tmp = ft_last_node(l);
	if (!tmp)
		error1();
	tmp->next = malloc(sizeof(t_leaks));
	if (!tmp->next)
		error1();
	tmp->next->next = NULL;
	tmp->next->ptr = malloc(a);
	if (!tmp->next->ptr)
		error1();
	return (tmp->next->ptr);
}

int	main(int argc, char **argv)
{
	t_map	map;

	if (argc == 2)
	{
		if (parsing(&map, argv[1]))
			return (1);
		if (execution(map))
			return (1);
	}
	return (0);
}
