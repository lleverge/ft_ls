/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:10:24 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/17 10:57:17 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
