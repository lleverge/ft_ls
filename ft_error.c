/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 12:48:18 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/18 10:56:17 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
			change_tab(tab, i);
			j++;
		}
		else
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
		if (read_param(error_tab[i]) == -1)
			perror(remove_slash(error_tab[i]));
		i++;
	}
	if (error_tab[0])
		free_tab(error_tab);
}

void		ft_check_void_av(void)
{
	ft_putendl_fd("ft_ls: fts_open: No such file or directory", 2);
	exit(0);
}

void		opt_error(char *s)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putendl_fd(s, 2);
	ft_putstr_fd("usage: ft_ls [-Ralrt] [file ...]\n", 2);
	exit(1);
}

void		ft_error_rights(char *path)
{
	ft_putstr_fd("ft_ls: ", 2);
	ft_putstr_fd(path, 2);
	ft_putendl_fd(": Permission denied", 2);
	ft_putchar('\n');
}
