/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:48:18 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/16 15:55:43 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int			count_error(char **tab)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (tab[i] != 0)
	{
		if (read_param(tab[i]) == -1)
			count++;
		i++;
	}
	return (count);
}

void		error_in_tab(char **tab, char **error_tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] && tab[i] != 0)
	{
		if (read_param(tab[i]) == -1)
		{
			error_tab[j] = ft_strdup(tab[i]);
			j++;
		}
		i++;
	}
	error_tab[j] = NULL;
}

void		ft_manage_error(char **tab)
{
	int		i;
	int		count;
	char	**error_tab;

	i = 0;
	count = count_error(tab);
	error_tab = NULL;
	if (!count)
		return ;
	if (!(error_tab = (char **)malloc(sizeof(char *) * (count + 1))))
		exit(1);
	error_in_tab(tab, error_tab);
	ft_sort_tab(error_tab);
	while (error_tab[i] != 0)
	{
		ft_putstr("ft_ls: ");
		perror(remove_slash(error_tab[i]));
		i++;
	}
}

void		opt_error(char *s)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putendl_fd(s, 2);
	ft_putstr_fd("usage: ft_ls [-Ralrt] [file ...]\n", 2);
	exit(1);
}

void		no_file_dir(char *fname)
{
	ft_putstr("ft_ls: ");
	perror(remove_slash(fname));
	return ;
}
