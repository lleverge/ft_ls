/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:10:24 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/18 12:08:00 by lleverge         ###   ########.fr       */
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

void		ft_repname(char *name, int nb, t_opt *opt)
{
	if (nb > 1 || opt->rec == 1)
	{
		ft_putstr(name);
		ft_putstr(":\n");
	}
}

void		change_tab(char **tab, int index)
{
	while (tab[index])
	{
		tab[index] = tab[index + 1];
		index++;
	}
}

int			count_rep(char **tab)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (tab[i] != 0)
	{
		if ((read_param(tab[i])) == 1)
			count++;
		i++;
	}
	return (count);
}

void		rep_in_tab(char **tab, char **rep_tab)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i] && tab[i] != 0)
	{
		if (read_param(tab[i]) == 1)
		{
			rep_tab[j] = ft_strdup(tab[i]);
			j++;
		}
		i++;
	}
	rep_tab[j] = NULL;
}


char		*ft_strnjoin(char const *s1, char const *s2, size_t len)
{
	size_t	i;
	char	*s;

	i = 0;
	s = ft_strnew(ft_strlen(s1) + (ft_strlen(s2) * len) + 1);
	if (s)
	{
		ft_strcat(s, s1);
		while (i < len)
		{
			ft_strcat(s, s2);
			i++;
		}
	}
	return (s);
}
