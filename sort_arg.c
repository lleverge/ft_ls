/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_arg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 15:56:51 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/17 18:45:34 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**sort_arg(char **tab, t_opt *opt)
{
	ft_sort_tab(tab);
	if (opt->r && opt->t)
	{
		tab = arg_time(tab);
		tab = rev_tab(tab);
	}
	else if (opt->t == 1)
		tab = arg_time(tab);
	else if (opt->r == 1)
		tab = rev_tab(tab);
	return (tab);
}

char		**rev_tab(char **tab)
{
	int		end;
	int		i;
	char	*swap;

	i = 0;
	end = 0;
	while (tab[end] != 0)
		end++;
	end = end - 1;
	while (end >= i)
	{
		swap = tab[i];
		tab[i] = tab[end];
		tab[end] = swap;
		i++;
		end--;
	}
	return (tab);
}

char		**arg_swap(char **tab, int j)
{
	char *swap;

	swap = tab[j];
	tab[j] = tab[j + 1];
	tab[j + 1] = swap;
	return (tab);
}

char		**arg_time(char **tab)
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
	return (tab);
}
