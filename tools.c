/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lleverge <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/16 14:10:24 by lleverge          #+#    #+#             */
/*   Updated: 2016/03/17 15:39:49 by lleverge         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void		display_count(t_elem *list, t_opt *opt, t_pad *pad)
{
	if (opt->l == 1 && opt->a && REAL_DIR(list->name))
    {
        ft_putstr("total ");
        ft_putnbr(count_blocks(list, opt));
        ft_putchar('\n');
        ft_padding(&list, pad);
    }
    if (opt->l == 1 && opt->a == 0)
    {
		if (list->name[0] != '.')
		{
			ft_putstr("total ");
			ft_putnbr(count_blocks(list, opt));
			ft_putchar('\n');
			ft_padding(&list, pad);
		}
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
