/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls_l3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 17:02:34 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/18 16:30:23 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

char		**arg_in_tab(int argc, char **argv)
{
	int		i;
	int		j;
	char	**tab;

	i = 1;
	j = 0;
	if (!(tab = (char **)malloc(sizeof(char *) * (argc + 1))))
		exit(1);
	while (i < argc)
	{
		if (!(ft_strcmp(argv[i], "-")))
		{
			tab[j] = ft_strdup(argv[i]);
			j++;
		}
		else if (argv[i][0] != '-')
		{
			tab[j] = ft_strdup(argv[i]);
			j++;
		}
		i++;
	}
	tab[j] = 0;
	return (tab);
}

char		*ft_get_time(const long *f_time)
{
	char	*tmp;
	char	*prev;
	char	*new;
	time_t	today;

	time(&today);
	tmp = ctime(f_time);
	if (today - 15724800 > *f_time || today < *f_time)
	{
		prev = ft_strsub(tmp, 4, 7);
		new = ft_strjoin(prev, ft_strsub(tmp, 20, 24));
		new[ft_strlen(new)] = '\0';
		ft_strdel(&prev);
	}
	else
		new = ft_strsub(tmp, 4, 12);
	if (ft_strchr(new, '\n'))
		(ft_strchr(new, '\n'))[0] = '\0';
	return (new);
}

char		*remove_slash(char *name)
{
	if (name[(ft_strlen(name) - 1)] == '/')
		name[(ft_strlen(name) - 1)] = '\0';
	return (name);
}
