/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:56:51 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/17 16:49:27 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**arg_swap(char **tab, int j)
{
	char *swap;

	swap = tab[j];
	tab[j] = tab[j + 1];
	tab[j + 1] = swap;
	return (tab);
}

void 		arg_time(char **tab)
{
	int		i;
	int		j;
	int		time1;
	int		time2;
	t_stat	stat;

	i = 0;
	j = 0;
	while (tab[i] != 0)
	{
		while (tab[j + 1] != 0)
		{
			lstat(tab[j], &stat);
			time1 = (int)stat.st_mtime;
			lstat(tab[j + 1], &stat);
			time2 = (int)stat.st_mtime;
			if (time1 < time2)
				tab = arg_swap(tab, j);
			j++;
		}
		i++;
	}
}
